//Queues - Implementation using stack
//Author: Yuvaraja Subramaniam ( www.linkedin.com/in/yuvaraja )

/* Queue - Abstract data type that has FIFO properties.
   Operations:
	 	 - enqueue() - O(1)
         - dequeue() - O(1)
         - front() or peek() - O(1)
         - is_empty()- O(1)
         - peek()   - O(1)
         - display() - O(n)

	Two stacks would be required to implement a queue out of stacks. There are three ways in which a queue can 
	be implemented using stacks with varying time complexities of enqueue/deque operations.

	Method 1: enqueue - O(1), dequeue - O(n)
	Method 2: enqueue - O(n), dequeue - O(1)
	Method 3: average timecomplexity of O(n/2) for both enqueue and dequeue operations

	This program implements method 2
	
*/

#include <iostream>
#include <stack>

using namespace std;

stack<int> stk_1;
stack<int> stk_2;


//prototypes
bool enqueue(int element) ;
int dequeue() ;
int peek() ;
void display() ;
bool isempty() ;

int main() {
	cout << "     IMPLEMENTATION OF QUEUE USING STACKS METHOD 2. enque = O(n). dequeue = O(1)    " << endl;
	cout << "------------------------------------------------------------------------------------" << endl;

	char choice;

	//menu
	do {
		cout <<" a) Enqueue" 	<< endl;
		cout <<" b) Dequeue" 	<< endl;
		cout <<" c) Front" 	    << endl;
		cout <<" d) Display" 	<< endl;
		cout <<" e) Is empty?" 	<< endl;
		cout <<" q) Quit" 		<< endl;

		cout << endl;
		cout << "Enter choice : ";
		cin >> choice;

		switch (choice) {
			case 'a' :
			{
				int element;
				cout << "Enter element : ";
				cin >> element;
				enqueue(element);
				break;
			}
			case 'b' :
			{
				int element = dequeue();
				if (-1 != element) {
					cout << "dequeued element = " << element << endl;
				}
				break;
			}
			case 'c' :
			{
				int element = peek();
				if (-1 != element) {
					cout << "front element = " << element << endl;
				}
				break;
			}
			case 'd' :
			{
				display();
				break;
			}
			case 'e' :
			{
				bool mty = isempty();
				cout << "Is empty = " << (mty?"yes":"no") << endl;
				break;
			}
		}
		cout<<endl;
	} while (choice != 'q' or choice == 'Q');
}

//Enqueue
bool enqueue(int element) {

	while( ! stk_2.empty() ) {
		stk_1.push( stk_2.top() );
		stk_2.pop();
	}

	stk_1.push(element);

	while( ! stk_1.empty() ) {
		stk_2.push( stk_1.top() );
		stk_1.pop();
	}

	return true;
}

//Dequeue
int dequeue() {
	if ( 0 == stk_2.size() ) {
		cout << "queue empty.." << endl;
		return -1;
	}

	int dequed_element = stk_2.top();
	stk_2.pop();
	return dequed_element;
}

//Front / Peek
int peek() {
	if ( 0 == stk_2.size() ) {
		cout << "queue empty.." << endl;
		return -1;
	}

	int front_element = stk_2.top();
	return front_element;
}


//Display
void display() {
	if ( 0 == stk_2.size() ) {
		cout << "queue empty.." << endl;
		return;
	}
	cout << "Queue contents : ";
	while( ! stk_2.empty() ) {

		int element = stk_2.top();
		stk_2.pop();
		cout << element << " ";
		stk_1.push( element );
	}
	cout << endl;

	while( ! stk_1.empty() ) {
		stk_2.push( stk_1.top() );
		stk_1.pop();
	}
}

//Is queue empty
bool isempty() {
	return stk_2.empty();
}
