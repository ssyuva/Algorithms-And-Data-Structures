//Implementation of Cirucular queue using arrays
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

const int qsize = 8;

int circularQ[qsize];

int front = -1; //front and rear are at -1 at the start
int rear  = -1;


//prototypes
bool enqueue(int element) ;
int  dequeue() ;
int  peek() ;
void display() ;
bool isempty() ;
bool isfull() ;

int main() {
	cout << "                          IMPLEMENTATION OF QUEUE USING ARRAY                       " << endl;
	cout << "------------------------------------------------------------------------------------" << endl;

	char choice;

	//menu
	do {
		cout <<" a) Enqueue" 	<< endl;
		cout <<" b) Dequeue" 	<< endl;
		cout <<" c) Front" 	    << endl;
		cout <<" d) Display" 	<< endl;
		cout <<" e) Is empty?" 	<< endl;
		cout <<" f) Is full?" 	<< endl;
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
			case 'f' :
			{
				bool mty = isfull();
				cout << "Is full = " << (mty?"yes":"no") << endl;
				break;
			}
		}
		cout<<endl;
	} while (choice != 'q' or choice == 'Q');
}



//Enqueue operation
bool enqueue(int element) {

	if ( (rear + 1) % qsize == front) {
		cout << "circular queue full.." << endl;
		return false;
	}

	if (-1 == front and -1 == rear) {
		front = rear = 0;
	}
	else {
		rear = (rear + 1) % qsize;
	}

	circularQ[rear] = element;
	return true;
}


//Dequeue operation
int  dequeue() {
	if ( -1 == front and -1 == rear ) {
		cout << "circular queue empty" << endl;
		return -1;
	}

	int data = circularQ[front];
	if ( front == rear ) {
		front = rear = -1;
	}
	else {
		front = (front + 1) % qsize;
	}
return data;
}


//Peek / Front
int  peek() {
	if ( -1 == front and -1 == rear ) {
		cout << "circular queue empty" << endl;
		return -1;
	}
return circularQ[front];
}



//Display the circular queue
void display() {
	if ( -1 == front and -1 == rear ) {
		cout << "circular queue empty" << endl;
	}
	else {
		cout << "Cirucular Q : qsize = " << qsize << ", front = " << front << ", rear = " << rear << endl;
		cout << "Cirucular Q : ";
		for (int i = front; i != rear; i = (i + 1) % qsize) {
			cout << circularQ[i] << " ";
		}
		cout << circularQ[rear] << endl;
	}
}



//Is circular queue empty?
bool isempty() {
	return (-1 == front and -1 == rear);
}



//Is circular queue full?

bool isfull() {
	return ( (rear +1) % qsize == front );
}
