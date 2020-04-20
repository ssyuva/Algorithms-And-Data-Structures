//Queues - Implementation double ended queue (deque) using circular linked list
//Author: Yuvaraja Subramaniam ( www.linkedin.com/in/yuvaraja )

/* Double Ended Queue - Has bot FIFO & LIFO properties. Can be used as a stack as well as a queue
   Operations:
	 	 - insert_front() - O(1)
	 	 - delete_front() - O(1)
	 	 - insert_back()  - O(1)
	 	 - delete_back()  - O(1)
         - peek_front()   - O(1)
         - peek_back()    - O(1)
         - is_empty()     - O(1)
         - display()      - O(n)

	In linear array implementations, Once the rear pointer reaches the end of the queue, elements can no 
	longer be queued. 

	Various implementations - Arrays, LinkedList
*/

#include <iostream>
#include <unistd.h>

using namespace std;

struct Node {
	int data;
	struct Node *next;
};

Node *front = nullptr;
Node *rear  = nullptr;

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
	cout << "                 IMPLEMENTATION OF DOUBLE ENDED QUEUE USING LINKED LIST             " << endl;
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
		}
		cout<<endl;
		usleep( 1000 * 1000);
	} while (choice != 'q' or choice == 'Q');
}




//Insert at front  end
bool insert_front(int element) {

	Node *newnode = new Node;
	newnode->data = element;

	//check if empty
	if ( nullptr == front and nullptr == rear ) {
		front = rear = newnode;
	}
	else {
		newnode->next = front;
		front = newnode;
	}
	rear->next = front;
	return true;
}




//Insert at rear end
bool insert_back(int element) {

	Node *newnode = new Node;
	newnode->data = element;

	//check if empty
	if ( nullptr == front and nullptr == rear ) {
		front = rear = newnode;
	}
	else {
		rear->next = newnode;
		rear = newnode;
	}
	rear->next = front;
	return true;
}




//Delete from from front end
int  delete_front() {
	
	//check if empty
	if ( nullptr == front and nullptr == rear ) {
		cout << "deque empty.." << endl;
		return -1;
	}
	
	int deqd_elem = front->data;
	Node *delnode = front;

	if ( front == rear ) {
		//only one element
		front = rear = nullptr;
	}
	else {
		front = front->next;
		rear->next = front;
	}
	delete delnode;
	return deqd_elem;
}




//Delete from rear end
int  delete_back() {
	//check if empty
	if ( nullptr == front and nullptr == rear ) {
		cout << "deque empty.." << endl;
		return -1;
	}
	
	int deqd_elem = rear->data;
	Node *delnode = rear;
	if ( front == rear ) {
		//only one element
		front = rear = nullptr;
	} 
	else {
		Node *prev = front;
		Node *tmp  = front;
		while (tmp != rear) {
			prev = tmp;
			tmp = tmp->next;
		}
		prev->next = rear->next;
		rear = prev;
	}
	delete delnode;
	return deqd_elem;
}



//Peek at the front element
int  peek_front() {
	//check if empty
	if ( nullptr == front and nullptr == rear ) {
		cout << "deque empty.." << endl;
		return -1;
	}
	return front->data;
}



//Peek at the rear element
int  peek_back() {
	//check if empty
	if ( nullptr == front and nullptr == rear ) {
		cout << "deque empty.." << endl;
		return -1;
	}
	return rear->data;
}



//Display the deque
void display() {
	//check if empty
	if ( nullptr == front and nullptr == rear ) {
		cout << "deque empty.." << endl;
		return;
	}

	cout << "Deque contents : ";
	for ( Node *curr = front ; curr != rear ; curr = curr->next ) {
		cout << curr->data << " ";
	}
	cout << rear->data << endl;
}




//Is deque empty?
bool isempty() {
	return (nullptr == front and nullptr == rear);
}

