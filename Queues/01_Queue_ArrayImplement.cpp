//Queues - Implementation using arrays
//Author: Yuvaraja Subramaniam ( www.linkedin.com/in/yuvaraja )

/* Queue - Abstract data type that has FIFO properties.
   Operations:
	 	 - enqueue() - O(1)
         - dequeue() - O(1)
         - front() or peek() - O(1)
         - is_full() - O(1)
         - is_empty()- O(1)
         - peek()   - O(1)
         - display() - O(n)

	Disadvantage - Once the rear pointer reaches the end of the queue, elements can no longer be queued

	Various implementations - Arrays, LinkedList, Stacks
*/

#include <iostream>

using namespace std;

const int qsize = 8;

int front = -1;
int rear  = -1;
int queue[qsize];

//prototypes
bool enqueue(int element) ;
int dequeue() ;
int peek() ;
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

//Enqueue
bool enqueue(int element) {
	if(rear == qsize - 1) {
		cout << "queue full.. element insertion failed" << endl;
		return false;
	}

	if (front == -1 and rear == -1) {
		front++;
	}
	rear++;
	queue[rear] = element;
	return true;
}

//Dequeue
int dequeue() {
	if ( front == -1 and rear == -1 ) {
		cout << "queue empty.." << endl;
		return -1;
	}
	else if (front == rear) {
		int dequed_element = queue[front];
		front = rear = -1;
		return dequed_element;
	}
	else {
		int dequed_element = queue[front];
		front++;
		return dequed_element;
	}
}

//Front / Peek
int peek() {
	if ( front == -1 and rear == -1 ) {
		cout << "queue empty.." << endl;
		return -1;
	}
	return queue[front];
}


//Display
void display() {
	if (front == -1 and rear == -1) {
		cout << "queue empty.." << endl;
		return;
	}
	cout << "Queue size = " << qsize << ", Number of elements in queue = " << (rear - front + 1) << endl;
	cout << "Queue contents : ";
	for (int i = front ; i <= rear ; i++) {
		cout << " " << queue[i];
	}
	cout << endl;
}

//Is queue empty
bool isempty() {
	if ( -1 == front and -1 == rear) {
		return true;
	}
return false;
}

//Is queue full
bool isfull() {
	if ( qsize-1 == rear ) {
		return true;
	}
return false;
}
