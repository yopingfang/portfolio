#ifndef EXPRESSION_MANAGER_H
#define EXPRESSION_MANAGER_H
#include "ExpressionManagerInterface.h"
#include <string>
#include <sstream>

class ExpressionManager : public ExpressionManagerInterface
{
	private:
		std::string infixExpression;
		std::string postfixExpression;
		int expressionValue;

	public:
		ExpressionManager();
		ExpressionManager(std::string);
		~ExpressionManager();
		int value(void);
		std::string infix(void);
		std::string postfix(void);
		std::string prefix(void);
		std::string toString() const;
		bool isBalanced(std::string);
		bool isOperator(std::string);
		bool isOperand(std::string);
		int precedence(std::string);
};
#endif // EXPRESSION_MANAGER_H