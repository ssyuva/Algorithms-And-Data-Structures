// Construct a binary expression tree from a binary expression - without using stack
// Author: Yuvaraja Subramaniam

/*
	1. Operators will be in only internal nodes.
	2. Operands will be in only leaf nodes.
	3. The last operator that fires will occupy the root of the tree.
	4. The higher precedence operators will occur close to the leaves (because they fire early)
	5. The lower precedence operators will occur close to the root (because they fire late)

	Recursive construction without using stack:
		1. Scan for the operator with lowest priority operator that will fire last (based on associativity), mark it
		2. Split the expression into two parts (left, right) at the marked operator
		3. Recursive apply the BET construction to the left and right subtrees
		4. Combine the constructed left, right subtrees into a complete tree with operator market in step 1 as root.
*/

#include <iostream>
#include <string>
#include <ctype.h>

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
BinaryExpTreeNode * build_BinaryExpTree(string infixexp);
BinaryExpTreeNode * buildSubTree(string & infixexp, int startidx, int endidx);
int scan_low_priority_split_operator(string & infixexp, int startidx, int endidx); 
void print_binary_expr_tree_inorder(BinaryExpTreeNode *tree);
void print_binary_expr_tree_preorder(BinaryExpTreeNode *tree);
void print_binary_expr_tree_postorder(BinaryExpTreeNode *tree);

int main() {
	cout << "CONSTRUCT A BINARY EXPRESSION TREE FROM INFIX EXPRESSION (WITHOUT USING STACK). RECURSIVE APPROACH" << endl;
	cout << "--------------------------------------------------------------------------------------------------" << endl;
	string infixexp = "a * b / c + e / f * g + k - x * y";
	BinaryExpTreeNode *bet = build_BinaryExpTree(infixexp);

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
BinaryExpTreeNode * build_BinaryExpTree(string infixexp) {
	BinaryExpTreeNode *root       = nullptr;
	BinaryExpTreeNode *left_tree  = nullptr;
	BinaryExpTreeNode *right_tree = nullptr;

	cout << "Building Binary Expression Tree for : " << infixexp << endl;

	int splitIdx       = scan_low_priority_split_operator( infixexp, 0, infixexp.length()-1 );
	char root_operator = infixexp[splitIdx];

	cout << "splitIdx = " << splitIdx << ", operator at splitIdx = " << root_operator << endl;
	int left_start     = 0;
	int left_end       = splitIdx - 1;
	int right_start    = splitIdx + 1;
	int right_end      = infixexp.length() - 1;

	root = new BinaryExpTreeNode;
	root->ch = root_operator;

	root->left  = buildSubTree(infixexp, left_start, left_end);
	root->right = buildSubTree(infixexp, right_start, right_end);

	return root;
}



//Build BET subtree for a sub-expression
BinaryExpTreeNode * buildSubTree(string & infixexp, int startidx, int endidx) {

	cout << "buildSubTree : startidx = " << startidx << ", endidx = " << endidx << endl;

	while(isspace(infixexp[startidx])) startidx++;
	while(isspace(infixexp[endidx])) endidx--;

	if (startidx > endidx) return nullptr;

	BinaryExpTreeNode *subtree = new BinaryExpTreeNode;

	if (startidx == endidx) {
		//this is a leaf node
		subtree->ch = infixexp[startidx];
		subtree->left = subtree->right = nullptr;
		//cout << "built leaf node " << subtree->ch << endl;
	}
	else {
		int splitIdx       = scan_low_priority_split_operator( infixexp, startidx, endidx );
		char subtree_optr  = infixexp[splitIdx];
		
		cout << "splitIdx = " << splitIdx << ", operator at splitIdx = " << subtree_optr << endl;

		int left_start     = startidx;
		int left_end       = splitIdx -1;
		int right_start    = splitIdx + 1;
		int right_end      = endidx;

		subtree = new BinaryExpTreeNode;
		subtree->ch = subtree_optr;

		subtree->left  = buildSubTree(infixexp, left_start, left_end);
		cout << "subtree left : ";
 		print_binary_expr_tree_inorder(subtree->left);
		cout << endl;
		subtree->right = buildSubTree(infixexp, right_start, right_end);
		cout << "subtree right : ";
 		print_binary_expr_tree_inorder(subtree->right);
		cout << endl;
	}
return subtree;
}



//scan lowest priority split operator
//returns the index of the split operator
int scan_low_priority_split_operator(string & infixexp, int startidx, int endidx) {

	int splitIdx = -1;
	for( int i = startidx ; i <= endidx and i < infixexp.length() ; i++ ) {
		char ch = infixexp[i];

		if (isspace(ch)) {
			continue;
		}

		if (!is_operator(ch)) {
			continue;
		}
		else {
			//operator found
			if (splitIdx == -1) {
				splitIdx = i;
			}
			else if( precedence(infixexp[i]) < precedence(infixexp[splitIdx]) ) {
				splitIdx = i;
			}
			else if( (precedence(infixexp[i]) == precedence(infixexp[splitIdx])) 
						and 
					 (associativity(infixexp[i])  == assc_left_to_right) ) {
				splitIdx = i;
			}
		}
	}
	return splitIdx;
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
