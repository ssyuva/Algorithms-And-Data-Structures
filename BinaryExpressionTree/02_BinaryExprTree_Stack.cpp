// Construct a binary expression tree from a binary expression - using stack
// Author: Yuvaraja Subramaniam

/*
	1. Operators will be in only internal nodes.
	2. Operands will be in only leaf nodes.
	3. The last operator that fires will occupy the root of the tree.
	4. The higher precedence operators will occur close to the leaves (because they fire early)
	5. The lower precedence operators will occur close to the root (because they fire late)

	Steps:
	
	1. Convert the infix expression into postfix expression 
	2. Scan the postfix expression from left to right. If the incoming char is an operand create a leaf node and 
	   push it on the stack.
	3. If the incoming char is in an operator, pop the top two items from the stack, build the expression sub-tree
	   for the incoming operator and push the root of the resulting subtree back on the stack.
	4. Repeat until the end of the expression is reached. The stack should contain only one element which is the root
	   of the expression tree.
*/

#include <iostream>
#include <string>
#include <ctype.h>
#include <stack>

using namespace std;

const int assc_left_to_right = 0;
const int assc_right_to_left = 1;


struct BinaryExpTreeNode {
	char ch;
	struct BinaryExpTreeNode *left;
	struct BinaryExpTreeNode *right;
};



//function prototypes
int precedence(char opr);
int associativity(char opr);
bool is_operator(char ch);
string infix_to_postfix(string infixexp);
void apply_operator(char opch, stack<char> & stk, string & postexp);

BinaryExpTreeNode * build_BinaryExpTreeUsingStack(string infixexp);
int scan_low_priority_split_operator(string & infixexp, int startidx, int endidx); 

void print_binary_expr_tree_inorder(BinaryExpTreeNode *tree);
void print_binary_expr_tree_preorder(BinaryExpTreeNode *tree);
void print_binary_expr_tree_postorder(BinaryExpTreeNode *tree);

int main() {
	cout << "       CONSTRUCT A BINARY EXPRESSION TREE FROM INFIX EXPRESSION (USING STACK. SINGLE PASS)        " << endl;
	cout << "--------------------------------------------------------------------------------------------------" << endl;
	string infixexp = "a * b / c + e / f * g + k - x * y";

	BinaryExpTreeNode *bet = build_BinaryExpTreeUsingStack(infixexp);

	cout << "Inorder traversal of built tree = ";
 	print_binary_expr_tree_inorder(bet);
	cout  << endl;

	cout << "Preorder traversal of built tree = ";
 	print_binary_expr_tree_preorder(bet);
	cout  << endl;

	cout << "Postorder traversal of built tree = ";
 	print_binary_expr_tree_postorder(bet);
	cout  << endl;
}



//Build binary expression tree
BinaryExpTreeNode * build_BinaryExpTreeUsingStack(string infixexp) {

	cout << "Building Binary Expression Tree for : " << infixexp << endl;

	//STEP 1: Convert from infix to postfix expression
	string postexp = infix_to_postfix(infixexp);
	cout << "Postfix expression : " << postexp << endl;
	cout << endl;

	stack<BinaryExpTreeNode *> stk;

	for (int i = 0 ; i < postexp.length() ; i++) {
		char ch = postexp[i];

		if ( isspace(ch) ) {
			continue;
		}

		if ( is_operator(ch) ) {
			//incoming char is an operator
			BinaryExpTreeNode *tmp = new BinaryExpTreeNode;
			tmp->ch    = ch;
			tmp->right = stk.top();
			stk.pop();
			tmp->left  = stk.top();
			stk.pop();
			stk.push(tmp);
		}
		else {
			//incoming char is an operand
			BinaryExpTreeNode *tmp = new BinaryExpTreeNode;
			tmp->ch    = ch;
			tmp->left  = nullptr;
			tmp->right = nullptr;
			stk.push(tmp);
		}
	}

	if ( 1 == stk.size() ) {
		BinaryExpTreeNode *tmp = stk.top();
		stk.pop();
		return tmp;
	}
	else {
		return nullptr;
	}
}


//print binary expression tree - inorder
void print_binary_expr_tree_inorder(BinaryExpTreeNode *tree) {
	if (tree == nullptr) return;
	print_binary_expr_tree_inorder(tree->left);
	cout << tree->ch;
	print_binary_expr_tree_inorder(tree->right);
}

//print binary expression tree - preorder
void print_binary_expr_tree_preorder(BinaryExpTreeNode *tree) {
	if (tree == nullptr) return;
	cout << tree->ch;
	print_binary_expr_tree_preorder(tree->left);
	print_binary_expr_tree_preorder(tree->right);
}

//print binary expression tree - postorder
void print_binary_expr_tree_postorder(BinaryExpTreeNode *tree) {
	if (tree == nullptr) return;
	print_binary_expr_tree_postorder(tree->left);
	print_binary_expr_tree_postorder(tree->right);
	cout << tree->ch;
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
		case '(' :
		case ')' :
			return 4;
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
		case '(' :
		case ')' :
			return assc_left_to_right;
			break;

		case '^' :
			return assc_right_to_left;
			break;
	}
}
