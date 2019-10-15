
//created by pp
#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<sstream>
#include"ExpressionManager.h";
using namespace std;

int ExpressionManager::value(void) {
	istringstream inSS;
	bool isInt = false;
	stack<int> nums;
	int total = 0;
	int nextNum = 0;
	int opCount = 0;

	int pushNum;

	if (postfix_.size() < 2) {
		inSS.str(postfix_.at(0));
		inSS >> total;
		return total;
	}
	for (unsigned int i = 0; i < postfix_.size(); i++) {
		if (operators.find(postfix_.at(i)) == string::npos) isInt = true;
		else isInt = false;
		if (isInt) {
			inSS.str(postfix_.at(i));
			inSS >> pushNum;
			nums.push(pushNum);
			inSS.clear();
		}
		else {
			nextNum = nums.top();
			nums.pop();
			if (postfix_.at(i) == "+") nums.top() += nextNum;
			if (postfix_.at(i) == "-") nums.top() -= nextNum;
			if (postfix_.at(i) == "*") nums.top() *= nextNum;
			if (postfix_.at(i) == "/") nums.top() /= nextNum;
			if (postfix_.at(i) == "%") nums.top() %= nextNum;
		}
	}
	total = nums.top();
	return total;
}
string ExpressionManager::infix(void) {
	
	istringstream inSS(inputExpression);
	infix_.clear();
	string toPush;
	while (!inSS.eof()) {
		inSS >> toPush;
		infix_.push_back(toPush);
	}

	stack<string> brackets;
	for (unsigned int i = 0; i < infix_.size(); i++) {
		if (operators.substr(0, 3).find(infix_.at(i)) != string::npos) {
			brackets.push(infix_.at(i));
		}
		if (operators.substr(4, 3).find(infix_.at(i)) != string::npos) {
			if (brackets.size() < 1) return "Caught exception: NOT Infix: Paren Mis-match";
			if ((infix_.at(i) == ")" && brackets.top() == "(") ||
				(infix_.at(i) == "}" && brackets.top() == "{") ||
				(infix_.at(i) == "]" && brackets.top() == "[")) {
				brackets.pop();
			}
			else return "Caught exception: NOT Infix: Paren Mis-match";
		}
	}
	if (brackets.size() > 0) return "Caught exception: NOT Infix: Unbalanced";

	int testNum = 0;
	for (unsigned int i = 0; i < infix_.size(); i++) {
		inSS.clear();
		inSS.str(infix_.at(i));
		inSS >> testNum;
		if (!inSS && operators.substr(0, 3).find(infix_.at(i)) == string::npos && i == 0) 
			return "Caught exception: NOT Infix: Missing Operands";
		if (i > 0) {
			if (operators.substr(8, 6).find(infix_.at(i)) != string::npos &&
				operators.substr(8, 6).find(infix_.at(i - 1)) != string::npos)
				return "Caught exception: NOT Infix: Missing Operands";
			if (!inSS && operators.find(infix_.at(i)) == string::npos)
				return "Caught exception: NOT Infix: Illegal Operator";
			if (operators.find(infix_.at(i)) == string::npos &&
				operators.find(infix_.at(i - 1)) == string::npos)
				return "Caught exception: NOT Infix: Missing Operators";
			if (operators.substr(4, 3).find(infix_.at(i)) != string::npos &&
				operators.substr(8, 6).find(infix_.at(i - 1)) != string::npos)
				return "Caught exception: NOT Infix: Missing Operands";
			if (operators.substr(0, 3).find(infix_.at(i)) != string::npos &&
				operators.find(infix_.at(i - 1)) == string::npos)
				return "Caught exception: NOT Infix: Missing Operators";
		}
		if (!inSS && i == (infix_.size() - 1))
			if (operators.substr(4, 3).find(infix_.at(i)) == string::npos)
				return "Caught exception: NOT Infix: Missing Operands";
	}

	string expression = toString();
	return expression;
}
string ExpressionManager::postfix(void) {
	stack<string> nums;
	string pstFix;
	string leftInt;
	string rightInt;
	bool isInt = false;
	int total = 0;
	
	nums.push("END");
	postfix_.clear();
	for (unsigned int i = 0; i < infix_.size(); i++) {
		if (operators.find(infix_.at(i)) == string::npos) isInt = true;
		else isInt = false;
		if (isInt) {
			pstFix.append(infix_.at(i));
			pstFix.push_back(' ');
			postfix_.push_back(infix_.at(i));
		}
		else {
			if ((nums.top() == "END" || operators.substr(0, 3).find(nums.top()) != string::npos) && 
				operators.substr(4, 3).find(infix_.at(i)) == string::npos)
				nums.push(infix_.at(i)); //push if stack is empty or has open bracket on top (unless it's a close bracket)
			else {
				if (operators.substr(0, 3).find(infix_.at(i)) != string::npos) { //if it's an open bracket
					nums.push(infix_.at(i));
				}
				else if (operators.substr(4, 3).find(infix_.at(i)) != string::npos) { //if it's a closed bracket
					while (operators.substr(0, 3).find(nums.top()) == string::npos) { //until open bracket is found
						pstFix.append(nums.top());
						pstFix.push_back(' ');
						postfix_.push_back(nums.top());
						nums.pop();
					}
					nums.pop(); //pop off open bracket
				}
				else if (operators.substr(8, 2).find(infix_.at(i)) != string::npos) { //if it's a -+
					while (operators.substr(0, 3).find(nums.top()) == string::npos) {
						pstFix.append(nums.top());
						pstFix.push_back(' ');
						postfix_.push_back(nums.top());
						nums.pop();
						if (nums.top() == "END") {
							break;
						}
					}
					nums.push(infix_.at(i));
				}
				else { //if it's */%
					if (operators.substr(8, 2).find(nums.top()) != string::npos) { //if top is a -+
						nums.push(infix_.at(i));
					}
					else {
						while (operators.substr(0, 3).find(nums.top()) == string::npos) {
							pstFix.append(nums.top());
							pstFix.push_back(' ');
							postfix_.push_back(nums.top());
							nums.pop();
							if (nums.top() == "END" || operators.substr(8, 2).find(nums.top()) != string::npos) break;
						}
						nums.push(infix_.at(i));
					}
				}
			}
		}
	}
	while (nums.top() != "END") { //pushes off any remaining operators
		pstFix.append(nums.top());
		pstFix.push_back(' ');
		postfix_.push_back(nums.top());
		nums.pop();
	}
	return pstFix;
}
string ExpressionManager::toString() const {
	ostringstream oSS;

	for (unsigned int i = 0; i < infix_.size(); i++) {
		oSS << infix_.at(i) << " ";
	}

	string expression = oSS.str();
	return expression;
}
void ExpressionManager::setExpression(string inEx) {
	inputExpression = inEx;
	return;
}