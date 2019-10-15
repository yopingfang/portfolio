/*
*Alias: Screenslaver
*CS 235 - Lab 5 Expressions
*/
#ifndef EXPRESSION_MANAGER_H
#define EXPRESSION_MANAGER_H

#include "ExpressionManagerInterface.h"
#include <string>
#include <stack>
#include <sstream>
#include <iostream>

class ExpressionManager :
	public ExpressionManagerInterface
{
public:
	ExpressionManager(std::string input);
	~ExpressionManager();

	/** Return the integer value of the infix expression */
	int value();

	/** Return the infix items from the expression
	Throw an error if the expression
	1) is not balanced.
	2) the number of operators IS NOT one less than the number of operands.
	3) there are adjacent operators. */
	std::string infix();

	/** Return a postfix representation of the infix expression */
	std::string postfix();

	/** Return the infix vector'd expression items */
	std::string toString() const;

	int precedence(char c);

	void isBalanced();

private:
	//stack
	std::string expression;
	std::string postfixExpression;
};
#endif /* EXPRESSION_MANAGER_H */

