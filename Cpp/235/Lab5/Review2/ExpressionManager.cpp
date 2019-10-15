//cpp for ExpressionManager.h

#include "ExpressionManager.h"
#include <string>
#include <stack>
#include <sstream>


ExpressionManager::ExpressionManager()
{

}

ExpressionManager::ExpressionManager(std::string expression)
{
	this->infixExpression = expression;
}

ExpressionManager::~ExpressionManager()
{

}

//--------------------------------------------value----------------------------
/** Return the integer value of the infix expression */
int ExpressionManager::value(void)
{
	//Call Postfix first, it will check for balance and stuff
	//Empty the operand stack
	std::stack<std::string> myStack;

	//Check number of operators and operands
	std::stringstream ss(postfixExpression);
	std::string tempExpression;
	int value = 0;
	
	
	while (ss >> tempExpression)
	{
		if (isOperand(tempExpression) == true)
		{
			myStack.push(tempExpression);
		}
		else if (isOperator(tempExpression) == true)
		{
			//Get values
			std::string tempRight = myStack.top();
			myStack.pop();
			std::string tempLeft = myStack.top();
			myStack.pop();

			//Perform equation
			if (tempExpression == "+")
			{
				value = std::stoi(tempLeft) + std::stoi(tempRight);
			}
			else if (tempExpression == "-")
			{
				value = std::stoi(tempLeft) - std::stoi(tempRight);
			}
			else if (tempExpression == "*")
			{
				value = std::stoi(tempLeft) * std::stoi(tempRight);
			}
			else if (tempExpression == "/")
			{
				value = std::stoi(tempLeft) / std::stoi(tempRight);
			}
			else if (tempExpression == "%")
			{
				value = std::stoi(tempLeft) % std::stoi(tempRight);
			}

			//Push value onto stack
			myStack.push(std::to_string(value));
		}
	}

	//Evaluate from postfix. Here's the algorithm:
	/*	1. Empty the operand stack
		2. while there are more tokens
		3.   get the next token
		4.   if the first character of the token is a digit
		5.      push the token on the stack
		6.   else if the token is an operator
		7.      pop the right operand off the stack
		8.      pop the left operand off the stack
		9.      evaluate the operation
		10.      push the result onto the stack
		11. pop the stack and return the result*/

	value = std::stoi(myStack.top());
	myStack.pop();

	//set the objects value to the result
	this->expressionValue = value;

	return value;
}

//--------------------------------------------infix----------------------------
/** Return the infix items from the expression
Throw an error if the expression
1) is not balanced.
2) the number of operators IS NOT one less than the number of operands.
3) there are adjacent operators. */
std::string ExpressionManager::infix(void)
{
	//Check the expression to see if it is balanced
	if (this->isBalanced(infixExpression) == false)
	{
		throw std::invalid_argument("NOT Infix: Paren Mis-match");
	}

	//Check number of operators and operands
	std::stringstream ss(infixExpression);
	std::string tempExpression;

	int countOperators = 0;
	int countOperands = 0;
	bool lastItemWasOperand = false;
	
	while (ss >> tempExpression)
	{
		if (isOperand(tempExpression) == true)
		{
			if (lastItemWasOperand == true)
			{
				throw std::invalid_argument("NOT Infix: Missing Operators");
			}
			else
			{
				lastItemWasOperand = true;
				countOperands++;
			}
		}
		else if (isOperator(tempExpression) == true)
		{
			//We know the current char is an Operator, check if the previous one was
			if (lastItemWasOperand == false)
			{
				throw std::invalid_argument("NOT Infix: Missing Operands");
			}
			else if (countOperands <= 0)
			{
				throw std::invalid_argument("NOT Infix: Missing Operands");
			}
			else
			{
				countOperators++;
				lastItemWasOperand = false;
			}
			
		}
		else if (tempExpression == " ") {}
		else if (tempExpression == "(")
		{
			if ((countOperands + countOperators) > 0)
			{
				if (lastItemWasOperand == true)
				{
					throw std::invalid_argument("NOT Infix: Missing Operators");
				}
			}
		}
		else if (tempExpression == "[")
		{
			if ((countOperands + countOperators) > 0)
			{
				if (lastItemWasOperand == true)
				{
					throw std::invalid_argument("NOT Infix: Missing Operators");
				}
			}
		}
		else if (tempExpression == "{")
		{
			if ((countOperands + countOperators) > 0)
			{
				if (lastItemWasOperand == true)
				{
					throw std::invalid_argument("NOT Infix: Missing Operators");
				}
			}
		}
		else if (tempExpression == ")") {}
		else if (tempExpression == "}") {}
		else if (tempExpression == "]") {}
		else
		{
			throw std::invalid_argument("NOT Infix: Illegal Operator");
		}
	}//End While Loop

	//Make sure last item was operand
	if (lastItemWasOperand == false)
	{
		throw std::invalid_argument("NOT Infix: Missing Operands");
	}

	//Compare Operands and Operators
	if (countOperators != (countOperands - 1))
	{
		throw std::invalid_argument("NOT Infix: Missing Operands. Need more logic here?");
	}

	return infixExpression;
}


//--------------------------------------------postfix--------------------------
/** Return a postfix representation of the infix expression */
std::string ExpressionManager::postfix(void)
{
		/*Scan the infix expression from left to right.
		If the scanned character is an operand, output it.
		Else,
		If the precedence of the scanned operator is greater than the precedence of the operator in the stack (or the stack is empty), push it.
		Else, pop the operator from the stack until the precedence of the scanned operator is greater than the precedence of the operator residing on the top of the stack. Push the scanned operator to the stack.
		If the scanned character is an ‘(‘, push it to the stack.
		If the scanned character is an ‘)’, pop and output from the stack until an ‘(‘ is encountered.
		Repeat steps 2-5 until infix expression is scanned.
		Pop and output from the stack until it is empty.*/
		
	//Check number of operators and operands
	std::stringstream ss(infixExpression);
	std::string tempExpression;
	std::string tempPostfixExpression;

	//Create Temp stack
	std::stack<std::string> myOperatorStack;

	while (ss >> tempExpression)
	{
		if (isOperand(tempExpression) == true)
		{
			//If the scanned character is an operand, output it.
			tempPostfixExpression += tempExpression + " ";
		}
		else if (isOperator(tempExpression) == true)
		{
			//Initial check for myOperatorStack.size() to avoid segmentation faults
			if (myOperatorStack.size() <= 0)
			{
				//If the stack is empty, push it.
				myOperatorStack.push(tempExpression);
			}
			else
			{
				//If the precedence of the scanned operator is greater than the precedence of the operator in the stack, push it.
				std::string tempTopPrecedence = myOperatorStack.top();
				if (precedence(tempExpression) > precedence(tempTopPrecedence))
				{
					//Precedence is greater, so push onto stack
					myOperatorStack.push(tempExpression);
				}
				else
				{
					//Else, pop the operator from the stack until the precedence of the scanned operator is greater than the precedence of the operator residing on the top of the stack.Push the scanned operator to the stack.
					while (precedence(tempExpression) <= precedence(tempTopPrecedence))
					{
						if (myOperatorStack.size() <= 0)
						{
							//If the stack is empty, push it.
							myOperatorStack.push(tempExpression);
						}
						else
						{
							tempPostfixExpression += myOperatorStack.top() + " ";
							myOperatorStack.pop();
							//Reset the top element, if not empty
							if (myOperatorStack.size() <= 0)
							{
								tempTopPrecedence = "0";
							}
							else
							{
								tempTopPrecedence = myOperatorStack.top();
							}
						}
					}//End While Loop
					myOperatorStack.push(tempExpression);
				}
			}
		}//End else if for Operator
		else if ((tempExpression == "(") || (tempExpression == "{") || (tempExpression == "["))
		{
			//If the scanned character is an ‘(‘, push it to the stack.
			myOperatorStack.push(tempExpression);
		}//End else if for Open Paranthesis
		else if ((tempExpression == ")") || (tempExpression == "}") || (tempExpression == "]"))
		{
			//If the scanned character is an ‘)’, pop and output from the stack until an ‘(‘ is encountered.
			std::string tempTopParanthesis = myOperatorStack.top();
			if (tempExpression == ")")
			{
				while (tempTopParanthesis != "(")
				{
					tempPostfixExpression += myOperatorStack.top() + " ";
					myOperatorStack.pop();
					//Reset the top element
					tempTopParanthesis = myOperatorStack.top();
				}//End While Loop
				//myOperatorStack.push(tempExpression); Dont push the paranthesis back on
				if (tempTopParanthesis == "(")
				{
					myOperatorStack.pop();
				}
			}
			else if (tempExpression == "}")
			{
				while (tempTopParanthesis != "{")
				{
					tempPostfixExpression += myOperatorStack.top() + " ";
					myOperatorStack.pop();
					//Reset the top element
					tempTopParanthesis = myOperatorStack.top();
				}//End While Loop
				 //myOperatorStack.push(tempExpression); Dont push the paranthesis back on
				//myOperatorStack.pop();
				if (tempTopParanthesis == "{")
				{
					myOperatorStack.pop();
				}
			}
			else if (tempExpression == "]")
			{
				while (tempTopParanthesis != "[")
				{
					tempPostfixExpression += myOperatorStack.top() + " ";
					myOperatorStack.pop();
					//Reset the top element
					tempTopParanthesis = myOperatorStack.top();
				}//End While Loop
				 //myOperatorStack.push(tempExpression); Dont push the paranthesis back on
				//myOperatorStack.pop();
				if (tempTopParanthesis == "[")
				{
					myOperatorStack.pop();
				}
			}
		}//End else if for Closing Parantheses
		else if (tempExpression == " ") {}
	}//End For loop

	//Pop the rest off, if any
	while (myOperatorStack.size() > 0)
	{
		tempPostfixExpression += myOperatorStack.top() + " ";
		myOperatorStack.pop();
		//return "Not sure what to return yet, isOperator in postFix final popping failed";
	}
	
	//DEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEELETE the stacks


	this->postfixExpression = tempPostfixExpression;
	return tempPostfixExpression;
}

//--------------------------------------------prefix---------------------------
/** (BONUS) Return a prefix representation of the infix expression */
std::string ExpressionManager::prefix(void)
{
	return "NOT IMPLEMENTED";
}

//--------------------------------------------toString-------------------------
/** Return the infix vector'd expression items */
std::string ExpressionManager::toString() const
{
	std::string temp = "toString() Not done yet";
	return temp;
}

//--------------------------------------------isBalanced-----------------------
/** Checks the parantheses to make sure they are balanced*/
bool ExpressionManager::isBalanced(std::string expression)
{
	//Create Temp stack
	std::stack<std::string> myStack;
	
	//Check number of operators and operands
	std::stringstream ss(expression);
	std::string tempExpression;

	//Create Temp stack
	std::stack<std::string> myOperatorStack;

	while (ss >> expression)
	{

	////While loop to go through the input expression.
	//for (int i = 0; i < expression.size(); i++)
	//{
		//Ignore other chars, check for open parantheses
		/*if (expression[i] == '(')
		{
			myStack.push("(");
		}
		if (expression[i] == '{')
		{
			myStack.push("{");
		}
		if (expression[i] == '[')
		{
			myStack.push("[");
		}*/
		if (expression == "(")
		{
			myStack.push("(");
		}
		if (expression == "{")
		{
			myStack.push("{");
		}
		if (expression == "[")
		{
			myStack.push("[");
		}

		//Check for closing parantheses, compare for open
		if (expression == ")")
		{
			//Initial check for myStack.size() to avoid segmentation faults
			if (myStack.size() <= 0)
			{
				
				return false;
			}

			if (myStack.top() == "(")
			{
				//Opening found for closing
				myStack.pop();
			}
			else
			{
				//Opening not found for closing
				throw std::invalid_argument("NOT Infix: Paren Mis-match");
				return false;
			}
		}
		if (expression == "}")
		{
			//Initial check for myStack.size() to avoid segmentation faults
			if (myStack.size() <= 0)
			{
				return false;
			}

			if (myStack.top() == "{")
			{
				//Opening found for closing
				myStack.pop();
			}
			else
			{
				//Opening not found for closing
				throw std::invalid_argument("NOT Infix: Paren Mis-match");
				return false;
			}
		}
		if (expression == "]")
		{
			//Initial check for myStack.size() to avoid segmentation faults
			if (myStack.size() <= 0)
			{
				return false;
			}

			if (myStack.top() == "[")
			{
				//Opening found for closing
				myStack.pop();
			}
			else
			{
				//Opening not found for closing
				throw std::invalid_argument("NOT Infix: Paren Mis-match");
				return false;
			}
		}
	}//End For Loop
	
	//Check size, stack should have 0 elements (closed all open paranthesis)
	if ( myStack.size() != 0)
	{
		throw std::invalid_argument("NOT Infix: Unbalanced");
		return false;
	}

	//DEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEELETE the stack?

	//Else, size is 0
	return true;
}

//--------------------------------------------isOperator-----------------------
/**Check if an individual character in string input is an operator*/
bool ExpressionManager::isOperator(std::string input)
{
	//Call this function when evauating an expression. Call on each, in loop
	if (input == "+")
	{
		return true;
	}
	else if (input == "-")
	{
		return true;
	}
	else if (input == "*")
	{
		return true;
	}
	else if (input == "/")
	{
		return true;
	}
	else if (input == "%")
	{
		return true;
	}

	//If input is not one of these characters, it is not an operator
	return false;
}

//--------------------------------------------isOperand------------------------
/**Check if an individual character in string input is an operand*/
bool ExpressionManager::isOperand(std::string input)
{
	//Call this function when evauating an expression. Call on each, in loop
	if (isdigit(input[0]))
	{
		return true;
	}

	//If input is not a digit, it is not an operand
	return false;
}

//--------------------------------------------precedence-----------------------
/**Check the precedence of an individual character in string input*/
int ExpressionManager::precedence(std::string input)
{
	// ), ], }		3		Immediate	Immediately pop from the stack to the output until you find the opening paranthesis.Do not put paranthesis on output.
	// *, / , %		2		High		Only put on empty stack, or if the top element has precedence of 0 or 1.
	// + , -		1		Low			Only put on empty stack, or stack with precedence of 0 (paranthesis on top)
	// (, [, {		0		Wild		Can always be placed on stack; any other operator can be put on top


	//Return the precedence, depends on which operator
	if (input == "+")
	{
		return 1;
	}
	else if (input == "-")
	{
		return 1;
	}
	else if (input == "*")
	{
		return 2;
	}
	else if (input == "/")
	{
		return 2;
	}
	else if (input == "%")
	{
		return 2;
	}
	else if (input == "(")
	{
		return 0;
	}
	else if (input == "{")
	{
		return 0;
	}
	else if (input == "[")
	{
		return 0;
	}
	else if (input == ")")
	{
		return 3;
	}
	else if (input == "}")
	{
		return 3;
	}
	else if (input == "]")
	{
		return 3;
	}

	//If it is not one of these, it is an operand.
	return 0;
}