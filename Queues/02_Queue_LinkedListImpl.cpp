//Queues - Implementation using liked list
//Author: Yuvaraja Subramaniam

/* Queue - Abstract data type that has FIFO properties.
   Operations:
	 	 - enqueue() - O(1)
         - dequeue() - O(1)
         - front() or peek() - O(1)
         - is_empty()- O(1)
         - peek()   - O(1)
         - display() - O(n)

	
	Advantage over array implementation - the queue can grow dynamically. In the case of array implementation
	the maximum size of the queue gets fixed at compile time.

	One extra rear pointer is required to achieve O(1) for insertionsi. Otherwise the entire list would need to 
	be traversed to insert at the end, which will give a time complexity of O(n). If required a separate queue
	size could also be maintained.
*/

#include <iostream>

using namespace std;

struct Node {
	int data;
	struct Node *next;
};

Node * front = nullptr;
Node * rear  = nullptr;

//prototypes
bool enqueue(int element) ;
int dequeue() ;
int peek() ;
void display() ;
bool isempty() ;
bool isfull() ;

int main() {
	cout << "                       IMPLEMENTATION OF QUEUE USING LINKED LIST                    " << endl;
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
	
	Node *newnode = new Node;
	newnode->data = element;

	if(front == nullptr and rear == nullptr) {
		front = rear = newnode;
	}
	else {
		newnode->next = nullptr;
		rear->next    = newnode;
		rear = newnode;
	}
return true;
}

//Dequeue
int dequeue() {
	if ( front == nullptr and rear == nullptr ) {
		cout << "queue empty.." << endl;
		return -1;
	}
	
	int dequed_element = front->data;
	Node *delnode = front;

	if (front == rear) {
		front = rear = nullptr;
	}
	else {
		front = front->next;
	}

	delete delnode;
	return dequed_element;
}

//Front / Peek
int peek() {
	if ( front == nullptr ) {
		cout << "queue empty.." << endl;
		return -1;
	}
	return front->data;
}


//Display
void display() {
	if (front == nullptr and rear == nullptr) {
		cout << "queue empty.." << endl;
		return;
	}
	cout << "Queue contents : ";
	
	for (Node *curr  = front ; curr != rear ; curr = curr->next) {
		cout << " " << curr->data;
	}
	cout << " " << rear->data << endl;
}

//Is queue empty
bool isempty() {
	if ( nullptr == front and nullptr == rear) {
		return true;
	}
return false;
}

