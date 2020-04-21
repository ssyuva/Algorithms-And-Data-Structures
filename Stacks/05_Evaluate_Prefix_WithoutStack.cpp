//Evaluation of prefix expression without using stack
//Author: Yuvaraja Subramaniam ( www.linkedin.com/in/yuvaraja )

#include<iostream>
#include<vector>
#include<string>
#include<ctype.h>
#include<cmath>

using namespace std;

//token value
union tvalue {
	char operatr;
	int  operand;
};

//token
struct token {
	int 	type;
	tvalue 	tval;
};

//token types
const int ttype_operator = 0;
const int ttype_operand  = 1;


int evaluate_prefix_exp(string pexp);
void print_tokens(vector<token> & tl); 



int main () {

	cout << "       EVALUATION OF PREFIX EXPRESSION WITHOUT USING STACK           " << endl;
	cout << "---------------------------------------------------------------------" << endl;

	vector<string> prefixexprs = {
	                             	"-+2*34/6^23",
									"+^+232**223"
	                             };

	for(string & pexp : prefixexprs) {

		cout << "Evaluating expression : " << pexp  << endl;
		int result = evaluate_prefix_exp(pexp);
		cout << "Result                : " << result << endl;
	    cout << "---------------------------------------------------------------------" << endl;
		cout << endl;
	}
}



//evaluate prefix expression
/* 
	1. The prefix expression needs to be scanned backwards from the end (because the first sub-expression
	   to be evaluated is actually at the end). Start scanning the prefix expression in the reverse.
	2. Whenever an operator is found, walk forward two steps to find the first and second operands
	3. Evaluate the sub-expression, remove the evaluated subexpression from the main expression and put the
	   evaluated result in place instead.
	4. Keep scanning the expression in reverse until the start is reached.
*/

int evaluate_prefix_exp(string pexp) {

	vector<token> tokenlist;

	//tokenize
	for (char & ch : pexp) {

		if ( isspace(ch) ) 
			continue;

		token tk;

		if (ch == '+' or ch == '-' or ch == '/' or ch == '*' or ch == '^') {
			tk.type  = ttype_operator;
			tk.tval.operatr = ch;
		}
		else {
			tk.type  = ttype_operand;
			tk.tval.operand = ch-'0';
		}
		tokenlist.push_back(tk);
	}
	print_tokens(tokenlist);

	//scan the tokenlist backwards and start evaluating
	while (tokenlist.size() != 1) {
		int operator_pos = -1;
		for (auto i = (tokenlist.size()-1); i >=0 ; i--) {
			if (tokenlist[i].type == ttype_operator) {
				operator_pos = i;
				break;
			}
		}
		
		if (operator_pos == -1) {
			//no operator found. expression evaluation done.
			break;
		}
		//operator located. find the operands
		char operatr  = tokenlist[operator_pos].tval.operatr;
		int operand_1 = tokenlist[operator_pos + 1].tval.operand;
		int operand_2 = tokenlist[operator_pos + 2].tval.operand;
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
		cout << ", result = " << result << endl;

		tokenlist.erase(tokenlist.begin() + operator_pos, tokenlist.begin() + operator_pos+3);
		cout << "erased evaluated subexpression part" << endl;
		print_tokens(tokenlist);

		cout << "adding a new operand token with value = " << result << endl;
		token result_tk;
		result_tk.type = ttype_operand;
		result_tk.tval.operand = result;
		tokenlist.insert(tokenlist.begin() + operator_pos, result_tk);
		print_tokens(tokenlist);
	}
	
	//extract result from the final token
	if (tokenlist[0].type == ttype_operand) {
		return tokenlist[0].tval.operand;
	}
return -1;
}


//print tokenlist
void print_tokens(vector<token> & tl) {

	cout << "Token list            :  " ;

	for (token & tk : tl) {
		if (tk.type == ttype_operator) {
			cout << tk.tval.operatr << " ";
		}
		else if (tk.type == ttype_operand) {
			cout << tk.tval.operand << " ";
		}
	}
	cout << endl;
}

