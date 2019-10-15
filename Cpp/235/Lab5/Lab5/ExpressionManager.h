//created by pp
#ifndef EXPRESSIONMANAGER_H
#define EXPRESSIONMANAGER_H

#include"ExpressionManagerInterface.h"
#include<vector>

class ExpressionManager : public ExpressionManagerInterface {
private:
	std::string inputExpression;
	std::vector<std::string>infix_;
	std::vector<std::string>postfix_;
	std::string operators = "([{ }]) -+ */%";
public:
	ExpressionManager(void) {};
	~ExpressionManager(void) {};
	int value(void);
	std::string infix(void);
	std::string postfix(void);
	std::string toString() const;
	void setExpression(std::string inEx);
};

#endif