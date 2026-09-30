#include "RPN.hpp"

RPN::RPN()
{

}

RPN::~RPN()
{

}

bool RPN::isOperator(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool RPN::processExpr(std::string expr, int &result)
{
	float operand1;
	float operand2;
	float res;
	for (unsigned int i = 0; i < expr.size(); i++)
	{
		if ((i != 0 && i % 2 != 0) && expr[i] == ' ')
		{
			continue;
		}
		if (std::isdigit(expr[i]))
		{
			nums.push(expr[i] - '0');
			continue;
		}
		if (isOperator(expr[i]) && nums.size() >= 2)
		{
			operand2 = nums.top();
			nums.pop();
			operand1 = nums.top();
			nums.pop();
			if (expr[i] == '+')
				res = operand1 + operand2;
			if (expr[i] == '-')
				res = operand1 - operand2;
			if (expr[i] == '*')
				res = operand1 * operand2;
			if (expr[i] == '/')
			{
				if (operand2 == 0)
					return false;
				res = operand1 / operand2;
			}
			if (res > std::numeric_limits<int>::max() || res < std::numeric_limits<int>::min())
				return false;
			nums.push(res);
			continue;
		}
		return false;
	}
	if (nums.size() != 1)
		return false;
	result = nums.top();
	return true;
}