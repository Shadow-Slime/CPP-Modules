//put numbers in stack
//if operator is found, pop last 2, apply operator, proceed
//if stack size < 2 when operator is find, error

#include <iostream>
#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error" << std::endl;
		return 1;
	}
	float result;
	RPN rpn;
	if (!rpn.processExpr(argv[1], result))
	{
		std::cout << "Error" << std::endl;
		return 1;
	}
	std::cout << result << std::endl;
	return 0;
}