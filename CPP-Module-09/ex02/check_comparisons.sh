#!/bin/bash
# Usage: ./check_comparisons.sh [binary] [max_n] [runs_per_n]
# Example: ./check_comparisons.sh ./PmergeMe 50 5

BIN=${1:-./PmergeMe}
MAX_N=${2:-50}
RUNS=${3:-5}

GREEN=$'\e[32m'; RED=$'\e[31m'; RESET=$'\e[0m'

# Ford-Johnson worst case: F(n) = sum_{k=1..n} ceil(log2(3k/4))
# ceil(log2(3k/4)) = smallest m such that 2^(m+2) >= 3k
max_cmp()
{
    local n=$1 total=0 k m
    for ((k = 1; k <= n; k++)); do
        m=0
        while (( (1 << (m + 2)) < 3 * k )); do
            ((m++))
        done
        ((total += m))
    done
    echo "$total"
}

if [ ! -x "$BIN" ]; then
    echo "Binary '$BIN' not found or not executable."
    exit 1
fi

failures=0
printf "%-5s %-6s %-12s %-12s %-8s %s\n" "n" "max" "worst vec" "worst deq" "sorted" "result"

for ((n = 1; n <= MAX_N; n++)); do
    limit=$(max_cmp "$n")
    worst_vec=0
    worst_deq=0
    status="OK"
    sorted_ok="yes"

    for ((r = 1; r <= RUNS; r++)); do
        input=$(shuf -i 1-100000 -n "$n" | tr '\n' ' ')
        output=$($BIN $input)

        vec=$(echo "$output" | grep "Vector" | awk '{print $NF}')
        deq=$(echo "$output" | grep "Deque"  | awk '{print $NF}')
        after=$(echo "$output" | grep "After:" | sed 's/After: *//')

        # Same elements as the input, in ascending order?
        expected=$(echo "$input" | tr ' ' '\n' | grep . | sort -n | tr '\n' ' ')
        got=$(echo "$after" | tr ' ' '\n' | grep . | tr '\n' ' ')
        [ "$expected" != "$got" ] && sorted_ok="NO"

        [ -z "$vec" ] || [ -z "$deq" ] && { status="PARSE ERROR"; continue; }
        (( vec > worst_vec )) && worst_vec=$vec
        (( deq > worst_deq )) && worst_deq=$deq

        (( vec > limit || deq > limit )) && status="OVER MAX"
        (( vec != deq )) && [ "$status" = "OK" ] && status="VEC/DEQ DIFFER"
    done

    [ "$sorted_ok" = "NO" ] && status="NOT SORTED"

    if [ "$status" = "OK" ]; then
        color=$GREEN
    else
        color=$RED
        ((failures++))
    fi
    printf "%-5s %-6s %-12s %-12s %-8s %s%s%s\n" \
        "$n" "$limit" "$worst_vec" "$worst_deq" "$sorted_ok" "$color" "$status" "$RESET"
done

echo
if (( failures == 0 )); then
    echo "${GREEN}All sizes 1..$MAX_N passed ($RUNS runs each).${RESET}"
else
    echo "${RED}$failures size(s) failed.${RESET}"
    exit 1
fi