//Queues - Implementation double ended queue (deque) using circular arrays
//Author: Yuvaraja Subramaniam ( www.linkedin.com/in/yuvaraja )

/* Double Ended Queue - Has bot FIFO & LIFO properties. Can be used as a stack as well as a queue
   Operations:
	 	 - insert_front() - O(1)
	 	 - delete_front() - O(1)
	 	 - insert_back()  - O(1)
	 	 - delete_back()  - O(1)
         - peek_front()   - O(1)
         - peek_back()    - O(1)
         - is_full()      - O(1)
         - is_empty()     - O(1)
         - display()      - O(n)

	In linear array implementations, Once the rear pointer reaches the end of the queue, elements can no 
	longer be queued. Hence we use circular arrays for implementing deque.

	Various implementations - Arrays, LinkedList
*/

#include <iostream>
#include <unistd.h>

using namespace std;

const int qsize = 8;

int front = -1;
int rear  = -1;
int deque[qsize];

//prototypes
bool insert_front(int element) ;
bool insert_back(int element) ;
int  delete_front() ;
int  delete_back() ;
int  peek_front() ;
int  peek_back() ;
void display() ;
bool isempty() ;
bool isfull() ;

int main() {
	cout << "                 IMPLEMENTATION OF DOUBLE ENDED QUEUE USING ARRAY                   " << endl;
	cout << "------------------------------------------------------------------------------------" << endl;

	char choice;

	//menu
	do {
		cout <<" a) Insert_front" 	<< endl;
		cout <<" b) Insert_back" 	<< endl;
		cout <<" c) Delete_front" 	<< endl;
		cout <<" d) Delete_back" 	<< endl;
		cout <<" e) Peek_front" 	<< endl;
		cout <<" f) Peek_back" 		<< endl;
		cout <<" g) Display" 		<< endl;
		cout <<" h) Is empty?" 		<< endl;
		cout <<" i) Is full?" 		<< endl;
		cout <<" q) Quit" 			<< endl;

		cout << endl;
		cout << "Enter choice : ";
		cin  >> choice;

		switch (choice) {
			case 'a' :
			{
				int element;
				cout << "Enter element : ";
				cin >> element;
				insert_front(element);
				break;
			}
			case 'b' :
			{
				int element;
				cout << "Enter element : ";
				cin >> element;
				insert_back(element);
				break;
			}
			case 'c' :
			{
				int element = delete_front();
				if (-1 != element) {
					cout << "deleted front element = " << element << endl;
				}
				break;
			}
			case 'd' :
			{
				int element = delete_back();
				if (-1 != element) {
					cout << "deleted back element = " << element << endl;
				}
				break;
			}
			case 'e' :
			{
				int element = peek_front();
				if (-1 != element) {
					cout << "peek front element = " << element << endl;
				}
				break;
			}
			case 'f' :
			{
				int element = peek_back();
				if (-1 != element) {
					cout << "peek back element = " << element << endl;
				}
				break;
			}
			case 'g' :
			{
				display();
				break;
			}
			case 'h' :
			{
				bool mty = isempty();
				cout << "Is empty = " << (mty?"yes":"no") << endl;
				break;
			}
			case 'i' :
			{
				bool mty = isfull();
				cout << "Is full = " << (mty?"yes":"no") << endl;
				break;
			}
		}
		cout<<endl;
		//usleep( 1000 * 1000);
	} while (choice != 'q' or choice == 'Q');

}




//Insert at front  end
bool insert_front(int element) {

	if ( (rear + 1) % qsize == front ) {
		cout << "deque full to capacity..  qsize = " << qsize << ", front = " << front << ", rear = " << rear << endl;
		return false;
	}

	//check if empty
	if ( -1 == front and -1 == rear ) {
		front = rear = 0;
	}
	else if ( 0 == front ) {
		front = qsize - 1;
	}
	else {
		front--;
	}
	deque[front] = element;
	return true;
}




//Insert at rear end
bool insert_back(int element) {

	if ( (rear + 1) % qsize == front ) {
		cout << "deque full to capacity..  qsize = " << qsize << ", front = " << front << ", rear = " << rear << endl;
		return false;
	}
	
	//check if empty
	if ( -1 == front and -1 == rear ) {
		front = rear = 0;
	}
	else {
		rear = (rear + 1) % qsize;
	}
	deque[rear] = element;
	return true;
}




//Delete from from front end
int  delete_front() {
	
	//check if empty
	if ( -1 == front and -1 == rear ) {
		cout << "deque empty..  qsize = " << qsize << ", front = " << front << ", rear = " << rear << endl;
		return -1;
	}
	
	int deqd_elem = deque[front];
	if ( front == rear ) {
		//only one element
		front = rear = -1;
	}
	else {
		front = (front + 1) % qsize;
	}
	return deqd_elem;
}




//Delete from rear end
int  delete_back() {
	//check if empty
	if ( -1 == front and -1 == rear ) {
		cout << "deque empty..  qsize = " << qsize << ", front = " << front << ", rear = " << rear << endl;
		return -1;
	}
	
	int deqd_elem = deque[rear];
	if ( front == rear ) {
		//only one element
		front = rear = -1;
	}
	else if ( 0 == rear ) {
		rear = qsize - 1;
	}
	else {
		rear--;
	}
	return deqd_elem;
}



//Peek at the front element
int  peek_front() {
	//check if empty
	if ( -1 == front and -1 == rear ) {
		cout << "deque empty..  qsize = " << qsize << ", front = " << front << ", rear = " << rear << endl;
		return -1;
	}

	return deque[front];
}



//Peek at the rear element
int  peek_back() {
	//check if empty
	if ( -1 == front and -1 == rear ) {
		cout << "deque empty..  qsize = " << qsize << ", front = " << front << ", rear = " << rear << endl;
		return -1;
	}

	return deque[rear];
}



//Display the deque
void display() {
	//check if empty
	if ( -1 == front and -1 == rear ) {
		cout << "deque empty..  qsize = " << qsize << ", front = " << front << ", rear = " << rear << endl;
		return;
	}

	cout << "Deque contents : qsize = " << qsize << ", front = " << front << ", rear = " << rear << endl;
	cout << "Deque contents : ";
	for ( int i = front ; i != rear ; i = (i+1) % qsize ) {
		cout << deque[i] << " ";
	}
	cout << deque[rear] << endl;
}




//Is deque empty?
bool isempty() {
	return (-1 == front and -1 == rear);
}


//Is deque full?
bool isfull() {
	return ( (rear + 1) % qsize == front );
}

