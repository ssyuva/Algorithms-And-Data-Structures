//Stack Applications - Conversion from infix expression to postfix expression
//Author: Yuvaraja Subramaniam ( www.linkedin.com/in/yuvaraja )

#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <vector>
#include <ctype.h>

using namespace std;

const int assc_left_to_right = 0;
const int assc_right_to_left = 1;

//function prototypes
int precedence(char opr);
int associativity(char opr);
string infix_to_postfix(string infixexp);
void apply_operator(char opch, stack<char> & stk, string & postexp);
bool is_operator(char ch);


int main() {
	cout << "     CONVERSION FROM INFIX (Polish) TO POSTFIX (Reverse Polish) EXPRESSION      " << endl;
	cout << "     ---------------------------------------------------------------------      " << endl;
	vector<string> inlist = {
							"a * b + c",
							"A - B / C * D + E",
							"K + L - M * N + (O ^ P) * W / U / V * T + Q",
							"A - B + (M ^ N) * (O + P) - Q/R^S*T+Z"
							};

	for (string & inexp : inlist) {
		string postexp = infix_to_postfix(inexp);
		cout << "Infix expression : "   << inexp << endl;
		cout << "Postfix expression : " << postexp << endl;
		cout << endl;
	}
}



/* Rules of infix to postfix conversion:
   	1. Print the operands as they arrive
  	2. If the stack is empty or contains '(' push incoming operator on stack
	3. If incoming char is '(' push on stack
	4. If incoming char is ')' pop the stack and print until matching ')' is popped out
	5. If incoming operator has higher precedence than the operator at the top of stack, push
	6. If incoming operator has lower precedence than the operator at the top, pop the top of stack
	   and print. Then try applying the incoming operator with new top of the stack.
	7. If the incoming operator has equal precedence to the operator at the top, apply associativity rule:
		a) If the associativity is left-to-right, pop on print the top, then push the incoming operator
		b) If the associativity is right-to-left, push the incoming operator
*/

//convert from infix to postfix expression
string infix_to_postfix(string infixexp) {
	cout << "Converting infix expression : " << infixexp << endl;
	string postexp = "";
	stack<char> stk;

	for (char & ch : infixexp) {
		if (isspace(ch)) {
			//postexp.push_back(ch);
			continue;
		}

		if (is_operator(ch)) {
			//ch is an operator or bracket
			apply_operator(ch, stk, postexp);
		}
		else {
			//if ch is an operand, output to postfix expression
			postexp.push_back(ch);
		}

		cout << "out expr built : " << postexp << endl;
	}

	//end of the expression reached. print out everything in the stack
	while( ! stk.empty() ) {
		postexp.push_back(stk.top());
		stk.pop();
	}
	return postexp;
}


//apply an operator to the stack & postfix expression
void apply_operator(char ch, stack<char> & stk, string & postexp) {

	cout << "incoming char = " << ch << endl;

	if ( stk.empty() or stk.top() == '(' ) {
		stk.push(ch);	
	} 
	else if (ch == '(') {
			stk.push(ch);
	} 
	else if (ch == ')') {

		while( (stk.top()) != '(' ){
			postexp.push_back(stk.top());
			stk.pop();
		}
		stk.pop(); //opening brace out
	} 
	else if ( precedence(ch) > precedence(stk.top()) ) {

		stk.push(ch);
	} 
	else if ( precedence(ch) < precedence(stk.top()) ) {

		postexp.push_back(stk.top());
		stk.pop();
		apply_operator(ch, stk, postexp);
	} 
	else if ( precedence(ch) == precedence(stk.top()) ) {

		if ( associativity(ch) == assc_left_to_right )  {
			postexp.push_back(stk.top());
			stk.pop();
			stk.push(ch);
		} 
		else if ( associativity(ch) == assc_right_to_left )  {
			stk.push(ch);
		}
	}
}

//return if the char is an operator
bool is_operator(char ch) {
	if (ch == '+' or ch == '-' or ch == '*' or ch == '/' or ch == '^' or ch == ')' or ch == '(') {
		return true;
	}
return false;
}

//return the precedence of operators
int precedence(char opr) {

	switch (opr) {

		case '+' :
		case '-' :
			return 1;
			break;

		case '*' :
		case '/' :
			return 2;
			break;

		case '^' :
			return 3;
			break;
	}
}


//return the associativity of operators
int associativity(char opr) {

	switch (opr) {

		case '+' :
		case '-' :
		case '*' :
		case '/' :
			return assc_left_to_right;
			break;

		case '^' :
			return assc_right_to_left;
			break;
	}
}
