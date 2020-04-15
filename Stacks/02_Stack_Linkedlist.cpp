//Stack implementation using linked list
//Author: Yuvaraja Subramaniam

#include <iostream>

using namespace std;

struct Node {
	int data;
	struct Node *next;
};

Node *topptr = nullptr;
int stack_size = 0;

//initial position of topptr is NULL

void push( int item );
int pop();
int top();
bool is_stack_empty();
void display();

int main() 
{
	cout << "      STACK IMPLEMENTATION USING LINKED LIST"        << endl;
	cout << "---------------------------------------------------" << endl;
	int choice;
	do {

		cout << "0) push "     << endl;
		cout << "1) pop "      << endl;
		cout << "2) top "      << endl;
		cout << "3) is_stack_empty"  << endl;
		cout << "4) display"   << endl;
		cout << "5) quit"      << endl;
		
		cout << "Enter choice : ";
		cin >> choice;
		cout << endl;

		switch (choice) {
			case 0:
				{
				int in_item;
				cout << "Enter item to push: "; 
				cin >> in_item;
				push(in_item);
				break;
				}

			case 1:
				{
				int out_item;
				if ((out_item = pop()) != -1) 
					cout << "Poped item : " << out_item << endl; 
				break;
				}

			case 2:
				{
				int top_item;
				if ((top_item = top()) != -1) 
					cout << "Top item : " << top_item << endl; 
				break;
				}

			case 3:
				{
				bool is_mty = is_stack_empty();
				cout << "Is empty? : " << (is_stack_empty()?"yes":"no") << endl; 
				break;
				}

			case 4:
				{
				display();
				break;
				}
			
			case 5:
				{
				exit(0);
				break;
				}

			default:
				cout << "Invalid choice : " << choice << endl;
		}
	} while (choice != 6);	
}


//push
void push( int item ) {
	Node *newnode = new Node;
	newnode->data = item;
	newnode->next = topptr;
	topptr = newnode;
	stack_size++;
}


//pop
int pop() {
	if(topptr == nullptr) {
		cout << "stack underflow" << endl;
		return -1;
	}
	else {
		int item = topptr->data;
		Node *delnode = topptr;
		topptr = topptr->next;
		delete delnode;

		stack_size--;

		return item;
	}
}


//top
int top() {
	if(topptr == nullptr) {
		cout << "stack underflow" << endl;
		return -1;
	}
	else {
		return topptr->data;
	}
}


//is_stack_empty
bool is_stack_empty() {
	return ((topptr == nullptr) ? true : false);
}


//display
void display() {
	if (topptr == nullptr) {
		cout << "stack empty" << endl;
		return;
	}
	cout << endl << endl;
	cout << "stack_size = " << stack_size << endl;
	Node *tmpptr = topptr;
	while(tmpptr != nullptr) {
		cout << "| " << tmpptr->data << " |" << endl;
		cout << "____ " << endl;
		tmpptr = tmpptr->next;
	}
	cout << endl;
}
