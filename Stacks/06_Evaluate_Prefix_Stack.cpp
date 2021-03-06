//Evaluation of prefix expression using stack
//Author: Yuvaraja Subramaniam ( www.linkedin.com/in/yuvaraja )

#include <iostream>
#include <stack>
#include <vector> 
#include <string>
#include <ctype.h>
#include <cmath>

using namespace std;


int evaluate_prefix_exp_stack(string pexp);


int main () {

	cout << "             EVALUATION OF PREFIX EXPRESSION USING STACK             " << endl;
	cout << "---------------------------------------------------------------------" << endl;

	vector<string> prefixexprs = {
	                             	"-+2*34/6^23",
									"+^+232**223"
	                             };

	for(string & pexp : prefixexprs) {

		cout << "Evaluating expression : " << pexp  << endl;
		int result = evaluate_prefix_exp_stack(pexp);
		cout << "Result                : " << result << endl;
	    cout << "---------------------------------------------------------------------" << endl;
		cout << endl;
	}
}



//evaluate prefix expression
/* 
	1. The prefix expression needs to be scanned backwards from the end (because the first sub-expression
	   to be evaluated is actually at the end). Start scanning the prefix expression in the reverse.
	2. If the incoming char is an operand, push on stack
	3. If the incoming char is an operator, the corresponding operands will the top two elements of the stack.
	   Pop the top two operands from the stack, evaluate the expression and push the result back into the stack.
	4. Keep scanning the expression in reverse until the start is reached. When the expression evaluation is
	   complete, there should be only one operand (result) in the stack. Pop the result and print.
*/

int evaluate_prefix_exp_stack(string pexp) {

	stack<int> stk;

	//scan the expression in reverse and start evaluating
	for (int i = pexp.length() - 1; i >= 0; i--) {
		char inchar = pexp[i];
	
		if ( isspace(inchar) ) {
			continue;
		}

		if ( inchar == '+' or inchar == '-' or inchar == '*' or inchar == '/' or inchar == '^' ) {
			//incoming operator
			char operatr  = inchar;

			int operand_1 = stk.top(); 
			stk.pop();

			int operand_2 = stk.top();
			stk.pop();

			int result;

			switch(operatr) {
				case '+':
					result = operand_1 + operand_2;
					break;
				case '-':
					result = operand_1 - operand_2;
					break;
				case '*':
					result = operand_1 * operand_2;
					break;
				case '/':
					result = operand_1 / operand_2;
					break;
				case '^':
					result = pow(operand_1, operand_2);
					break;
				default:
					cout << "do not know what to do with operator : " << operatr << endl;
			}

			cout << "sub-exp operator      : " << operatr << ", operand_1 = " << operand_1 << ", operand_2 = " << operand_2;
			cout << ", result back to stk = " << result << endl;

			stk.push(result); //push the result back to the stack
		}
		else {
			//incoming number
			stk.push( inchar - '0' );
		}
	}

	//check for only one element in the top of the stack and return result
	if (stk.size() == 1) {
		int result = stk.top();
		stk.pop();
		return result;
	}
	else {
		cout << "error evaluating expression : << " << pexp << endl;
		return -1;
	}
}

