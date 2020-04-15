//Stack implementation using array
//Author: Yuvaraja Subramaniam

#include <iostream>

using namespace std;

const int stack_size     = 10;
const int stack_last_idx = stack_size - 1;
int stack[stack_size];

//initial position of top is -1
int stack_top = -1;

void push( int item );
int pop();
int top();
bool is_stack_empty();
bool is_full();
void display();

int main() 
{
	cout << "      STACK IMPLEMENTATION USING ARRAY" << endl;
	cout << "-----------------------------------------------" << endl;
	int choice;
	do {

		cout << "0) push "     << endl;
		cout << "1) pop "      << endl;
		cout << "2) top "      << endl;
		cout << "3) is_stack_empty"  << endl;
		cout << "4) is_full"   << endl;
		cout << "5) display"   << endl;
		cout << "6) quit"      << endl;
		
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
				bool is_fl = is_full();
				cout << "Is full? : " << (is_full()?"yes":"no") << endl; 
				break;
				}

			case 5:
				{
				display();
				break;
				}
			
			case 6:
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
	if (stack_top < stack_last_idx) {
		stack[++stack_top] = item;
	}
	else {
		cout << "stack overflow" << endl;
	}
}


//pop
int pop() {
	if(stack_top >= 0) {
		return stack[stack_top--];
	}
	else {
		cout << "stack underflow" << endl;
		return -1;
	}
}


//top
int top() {
	if(stack_top >= 0) {
		return stack[stack_top];
	}
	else {
		cout << "stack empty" << endl;
		return -1;
	}
}


//is_stack_empty
bool is_stack_empty() {
	return ((stack_top >= 0) ? false : true);
}


//is_full
bool is_full() {
	return ((stack_top == stack_last_idx) ? true : false);
}

//display
void display() {
	if (stack_top == -1) {
		cout << "stack empty" << endl;
		return;
	}
	cout << endl << endl;
	cout << "stack_size = " << stack_size << ", top = " << stack_top << endl;
	for(int i=stack_top; i >= 0; i--) {
		cout << "| " << stack[i] << " |" << endl;
		cout << "____ " << endl;
	}
	cout << endl;
}
