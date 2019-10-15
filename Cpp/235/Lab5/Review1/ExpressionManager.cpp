/*
*Alias: Screenslaver
*CS 235 - Lab 5 Expressions
*/
#include "ExpressionManager.h"

ExpressionManager::ExpressionManager(std::string input) {
	expression = input;
	expression.erase(0, 12);
}


ExpressionManager::~ExpressionManager()
{
}

int ExpressionManager::value() {
	int finalValue = 0;
	std::stack<int> stkNum;
	std::string operatr;
	std::istringstream iss(postfixExpression);
	std::string currentObject;
	int expressionNum = 0;
	int tempSolution = 0;

	while (iss >> currentObject) {
		std::istringstream testss(currentObject);
		if (testss >> expressionNum) {
			stkNum.push(expressionNum);
			finalValue = expressionNum;
			//std::cout << stkNum.top();
		}
		else {
			//std::cout << iss.str();
			//char operatr;
			operatr = currentObject;
			//std::cout << operatr << std::endl;
			int lastNum = stkNum.top();
			int firstNum = 0;
			stkNum.pop();
			firstNum = stkNum.top();
			stkNum.pop();
			if (operatr == "+") {
				tempSolution = firstNum + lastNum;
			}
			else if (operatr == "-") {
				tempSolution = firstNum - lastNum;
			}
			else if (operatr == "*") {
				tempSolution = firstNum * lastNum;
			}
			else if (operatr == "/") {
				tempSolution = firstNum / lastNum;
			}
			else if (operatr == "%") {
				tempSolution = firstNum % lastNum;
			}

			if (stkNum.empty()) {
				finalValue = tempSolution;
				stkNum.push(tempSolution);
			}
			else {
				stkNum.push(tempSolution);
			}
		}
	}

	
	return finalValue;
}

std::string ExpressionManager::infix() {
	std::string infixEx = expression;
	std::stack<char> parenStk;

	isBalanced();

	for (unsigned int i = 0; i < infixEx.length(); ++i) {
		if (isdigit(expression.at(i))) {
			if (expression.length() > (i + 2)) {
				if ((isdigit(expression[i + 2])) || expression[i + 2] == '(' || expression[i+2] == '[' || expression[i+2] == '{') {
					throw std::string("Missing Operators");
				}
			}
			if (i > 1) {
				if ((isdigit(expression[i - 2])) || expression[i - 2] == ')' || expression[i - 2] == ']' || expression[i - 2] == '}') {
					throw std::string("Missing Operators");
				}
			}
		}
		
		else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/' || expression[i] == '%') {
			if ((expression.length() < (i + 2)) || (i < 1) || 
				(!(isdigit(expression[i - 2]) || expression[i-2] == ')' || expression[i-2] == ']' || expression[i-2] == '}') || 
				!(isdigit(expression[i + 2]) || expression[i + 2] == '(' || expression[i + 2] == '[' || expression[i + 2] == '{'))) {
				throw std::string("Missing Operands");
			}
		}
		else if (expression[i] == ' ' || expression[i] == '(' || expression[i] == '[' || expression[i] == '{'
			|| expression[i] == ')' || expression[i] == ']' || expression[i] == '}') {

		}
		else {
			throw std::string("Illegal Operator");
		}
	}

	return infixEx;
}

std::string ExpressionManager::postfix() {
	std::stack<char> stk;

	for (unsigned int i = 0; i < expression.length(); ++i) {
		if (isdigit(expression.at(i))) {
			postfixExpression += expression[i];
			if (expression[i + 1] == ' ' || i == expression.length() - 1) {
				postfixExpression += ' ';
			}
		}
		else if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{') {
			stk.push(expression[i]);
		}
		else if (expression[i] == ')') {
			while (!stk.empty() && stk.top() != '(') {
				char c = stk.top();
				stk.pop();
				postfixExpression += c;
				postfixExpression += ' ';
			}
			if (stk.top() == '(') {
				stk.pop();
			}
		}
		else if (expression[i] == ']') {
			while (!stk.empty() && stk.top() != '[') {
				char c = stk.top();
				stk.pop();
				postfixExpression += c;
				postfixExpression += ' ';
			}
			if (stk.top() == '[') {
				stk.pop();
			}
		}
		else if (expression[i] == '}') {
			while (!stk.empty() && stk.top() != '{') {
				char c = stk.top();
				stk.pop();
				postfixExpression += c;
				postfixExpression += ' ';
			}
			if (stk.top() == '{') {
				stk.pop();
			}
		}
		else if (expression[i] == ' ') {
		}
		else {
			while (!stk.empty() && precedence(expression[i]) <= precedence(stk.top()))
			{
				char c = stk.top();
				stk.pop();
				postfixExpression += c;
				postfixExpression += ' ';
			}
			stk.push(expression[i]);
		}
	}

	while (!stk.empty()) {
		char c = stk.top();
		stk.pop();
		postfixExpression += c;
		postfixExpression += ' ';
	}

	return postfixExpression;
}

std::string ExpressionManager::toString() const {
	std::string line;

	return line;
}

int ExpressionManager::precedence(char c) {
	if (c == '*' || c == '/' || c == '%') {
		return 2;
	}
	else if (c == '+' || c == '-') {
		return 1;
	}
	else if (c == '(' || c == '[' || c == '{') {
		return 0;
	}
	else {
		return -1;
	}
}

void ExpressionManager::isBalanced() {
	std::stack<char> parenStk;

	for (unsigned int i = 0; i < expression.length(); ++i) {
		if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{') {
			parenStk.push(expression[i]);
		}
		else if (expression[i] == ')') {
			if (!parenStk.empty() && parenStk.top() == '(') {
				parenStk.pop();
			}
			else {
				throw std::string("Paren Mis-match");
			}
		}
		else if (expression[i] == ']') {
			if (!parenStk.empty() && parenStk.top() == '[') {
				parenStk.pop();
			}
			else {
				throw std::string("Paren Mis-match");
			}
		}
		else if (expression[i] == '}') {
			if (!parenStk.empty() && parenStk.top() == '{') {
				parenStk.pop();
			}
			else {
				throw std::string("Paren Mis-match");
			}
		}
	}
	if (!parenStk.empty()) {
		throw std::string("Unbalanced");
	}

	return;
}
