#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <list>
#include <limits>

class RPN
{
	public:
		RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();
		bool isOperator(char c);
		bool processExpr(std::string expr, float &result);
	private:
		std::stack<float, std::list<float> > nums;
};

#endif