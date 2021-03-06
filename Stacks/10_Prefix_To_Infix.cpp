//Convert prefix expression to infix expression
//Author: Yuvaraja Subramaniam ( www.linkedin.com/in/yuvaraja )

#include <iostream>
#include <stack>
#include <vector> 
#include <string>
#include <ctype.h>
#include <cmath>

using namespace std;


string prefix_to_infix(string pexp);


int main () {

	cout << "              CONVERSION OF PREFIX EXPRESSION TO INFIX               " << endl;
	cout << "---------------------------------------------------------------------" << endl;

	vector<string> prefixexprs = {
	                             	"-+2*34/6^23",
									"+^+232**223"
	                             };

	for(string & pexp : prefixexprs) {

		cout << "Conversing expression : " << pexp  << endl;
		string result = prefix_to_infix(pexp);
		cout << "Result                : " << result << endl;
	    cout << "---------------------------------------------------------------------" << endl;
		cout << endl;
	}
}



//convert prefix expression to infix
/* 
	1. The prefix expression needs to be scanned from reverse end (right to left)
	2. If the incoming char is an operand, push on stack
	3. If the incoming char is an operator, the corresponding operands will the top two elements of the stack. Pop the 
       top two operands from the stack, construct the infix sub-expression and push the infix expression into the stack.
	4. Keep scanning the expression until the start is reached. When the expression conversion is complete, there should 
	   be only one element in the stack which should be the converted infix expression
*/

string prefix_to_infix(string pexp) {

	stack<string> stk;

	//scan the expression from front to back
	for (int i =  pexp.length()-1; i >= 0; i--) {
		char inchar = pexp[i];
	
		if ( isspace(inchar) ) {
			continue;
		}

		if ( inchar == '+' or inchar == '-' or inchar == '*' or inchar == '/' or inchar == '^' ) {
			//incoming operator
			char operatr  = inchar;

			string operand_1 = stk.top(); 
			stk.pop();

			string operand_2 = stk.top();
			stk.pop();

			string infix;

			switch(operatr) {
				case '+':
					infix = operand_1 + " + " + operand_2;
					break;
				case '-':
					infix = operand_1 + " - " + operand_2;
					break;
				case '*':
					infix = operand_1 + " * " + operand_2;
					break;
				case '/':
					infix = operand_1 + " / " + operand_2;
					break;
				case '^':
					infix = operand_1 + " ^ " + operand_2;
					break;
				default:
					cout << "do not know what to do with operator : " << operatr << endl;
			}

			infix = "(" + infix + ")";

			cout << "sub-exp operator      : " << operatr << ", operand_1 = " << operand_1 << ", operand_2 = " << operand_2;
			cout << ", infix back to stk = " << infix << endl;

			stk.push(infix); //push the result back to the stack
		}
		else {
			//incoming number
			stk.push(string(1, inchar));
		}
	}

	//check for only one element in the top of the stack and return result
	if (stk.size() == 1) {
		string infix = stk.top();
		stk.pop();
		return infix;
	}
	else {
		cout << "error evaluating expression : << " << pexp << endl;
		return string("error");
	}
}

