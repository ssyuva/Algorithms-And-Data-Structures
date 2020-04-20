//Implementation of Cirucular queue using linked list
//Author: Yuvaraja Subramaniam ( www.linkedin.com/in/yuvaraja )

/*  Circular queue fixes the issue of linear queue showing up as full when the rear pointer is
	at the end and front has gotten to the rear from backside

	 	 - enqueue() - O(1)
         - dequeue() - O(1)
         - front() or peek() - O(1)
         - is_full() - O(1)
         - is_empty()- O(1)
         - peek()   - O(1)
         - display() - O(n)

	Various implementations - Arrays, LinkedList
*/

#include <iostream>

using namespace std;

struct Node {
	int data;
	struct Node *next;
};

//initially front = rear = NULL
Node *front = nullptr;
Node *rear  = nullptr;


//prototypes
bool enqueue(int element) ;
int  dequeue() ;
int  peek() ;
void display() ;
bool isempty() ;

int main() {
	cout << "               IMPLEMENTATION OF CIRCULAR QUEUE USING LINKED LIST                   " << endl;
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



//Enqueue operation
bool enqueue(int element) {

	Node *newnode = new Node;
	newnode-> data = element;

	if (nullptr == front and nullptr == rear) {
		front = rear = newnode;
	}
	else {
		rear->next = newnode;
		rear = newnode;
	}
	rear->next = front;
	return true;
}


//Dequeue operation
int  dequeue() {
	if ( nullptr == front and nullptr == rear ) {
		cout << "circular queue empty" << endl;
		return -1;
	}

	int data      = front->data;
	Node *delnode = front;

	if ( front == rear ) {
		front = rear = nullptr;
	}
	else {
		front = front->next;
		rear->next = front;
	}
	delete delnode;
return data;
}


//Peek / Front
int  peek() {
	if ( nullptr == front and nullptr == rear ) {
		cout << "circular queue empty" << endl;
		return -1;
	}
return front->data;
}



//Display the circular queue
void display() {
	if ( nullptr == front and nullptr == rear ) {
		cout << "circular queue empty" << endl;
	}
	else {
		cout << "Cirucular Q : ";
		for (Node *curr = front; curr != rear; curr = curr->next) {
			cout << curr->data << " ";
		}
		cout << rear->data << endl;
	}
}



//Is circular queue empty?
bool isempty() {
	return (nullptr == front and nullptr == rear);
}

