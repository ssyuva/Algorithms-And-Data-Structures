//Implementation of doubly linked circular list
//Author: Yuvaraja Subramaniam ( www.linkedin.com/in/yuvaraja )

/* Doubly linked circular list:

	Sequential access only data structure. No random access possible. Both forward and reverse iteration possible.
	
	insert_begin()      - O(1)
    insert_end()        - O(n)
    insert_middlepos()  - O(n/2) = O(n)

	delete_begin()      - O(1)
    delete_end()        - O(n)
    delete_middlepos()  - O(n/2) = O(n)

	display()           - O(n)
	isempty()           - O(1)

	reverse()           - O(n)

	There are implementations of cicular list that use both head and tail pointers. But this implementation of circular 
	list uses only tail pointer and not head pointer. 
*/


#include <iostream>

using namespace std;

struct Node {
	int data;
	struct Node *prev;
	struct Node *next;
};

//prototypes
bool insert_begin(int item); 
bool insert_end(int item); 
bool insert_middlepos(int item, int position); 

int delete_begin(); 
int delete_end(); 
int delete_middlepos(int position); 

void display();
void display_reverse();
bool isempty();


//reversal methods
bool reverse_iterative();

Node *tail;


int main() {

	cout << "       DOUBLY LINKED CICULAR LIST (Implemented using only one pointer - Tail)       " << endl;
	cout << "------------------------------------------------------------------------------------" << endl;

	char choice;

	//menu
	do {
		cout <<" a) Insert_begin"       << endl;
		cout <<" b) Insert_end"         << endl;
		cout <<" c) Insert_position"    << endl;
		cout <<" d) Delete_begin"       << endl;
		cout <<" e) Delete_end"         << endl;
		cout <<" f) Delete_position"    << endl;
		cout <<" g) Display"            << endl;
		cout <<" h) Display_reverse"    << endl;
		cout <<" i) Is empty?"          << endl;
		cout <<" j) Reverse - iterative (inplace pointer swap)" << endl;
		cout <<" q) Quit"               << endl;

		cout << endl;
		cout << "Enter choice : ";
		cin  >> choice;

		switch (choice) {
			case 'a' :
			{
				int element;
				cout << "Enter element : ";
				cin >> element;
				insert_begin(element);
				break;
			}
			case 'b' :
			{
				int element;
				cout << "Enter element : ";
				cin >> element;
				insert_end(element);
				break;
			}
			case 'c' :
			{
				int element;
				int pos;
				cout << "Enter element : ";
				cin >> element;
				cout << "Enter insert position (start = 1): ";
				cin >> pos;
				insert_middlepos(element, pos);
				break;
			}
			case 'd' :
			{
				int element = delete_begin();
				if (-1 != element) {
					cout << "deleted begining element = " << element << endl;
				}
				break;
			}
			case 'e' :
			{
				int element = delete_end();
				if (-1 != element) {
					cout << "deleted end element = " << element << endl;
				}
				break;
			}
			case 'f' :
			{
				int pos;
				cout << "Enter delete position (start = 1): ";
				cin >> pos;
				int element = delete_middlepos(pos);
				if (-1 != element) {
					cout << "deleted element = " << element << endl;
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
				display_reverse();
				break;
			}
			case 'i' :
			{
				bool mty = isempty();
				cout << "Is empty = " << (mty?"yes":"no") << endl;
				break;
			}
			case 'j' :
			{
				bool res = reverse_iterative();
				cout << "Reversed list using iterative method (insplace pointer swap)" << endl;
				break;
			}
		}
		cout<<endl;
		//usleep( 1000 * 1000);
	} while (choice != 'q' or choice == 'Q');
}



//Insert at the beginning
bool insert_begin( int item ) {

	Node *newnode = new Node;
	newnode->data = item;

	if (nullptr == tail) {
		newnode->next = newnode;
		newnode->prev = newnode;
		tail = newnode;
	}
	else {
		newnode->next = tail->next;
		newnode->prev = tail;
		tail->next    = newnode;
		newnode->next->prev = newnode;
	}
return true;
}



//Insert at the end
bool insert_end( int item ) {
	
	Node *newnode = new Node;
	newnode->data = item;

	if (nullptr == tail) {
		newnode->next = newnode;
		newnode->prev = newnode;
		tail = newnode;
	}
	else {
		newnode->next = tail->next;
		newnode->prev = tail;
		tail->next    = newnode;
		newnode->next->prev = newnode;
		tail = newnode;
	}
return true;
}



//Insert as a node at particular position
bool insert_middlepos( int item, int position ) {

	if (position < 1) {
		cout << "invalid insertion position = " << position << endl;
		return false;
	}

	if ( position == 1) {
		insert_begin(item);
		return true;
	}

	Node *newnode = new Node;
	newnode->data = item;

	int curpos = 1;
	Node *curr = tail->next;

	while (curr != tail and curpos < position) {
		curpos++;
		curr = curr->next;
	}
	
	//position located
	if (curpos == position) {
		newnode->next        = curr;
		newnode->prev        = curr->prev;
		newnode->prev->next  = newnode;
		curr->prev           = newnode;
	}
	else if ( (curpos + 1) == position and curr == tail) {
		//inserting beyond the tail position
		newnode->next    = tail->next;
		newnode->prev    = tail;
		tail->next       = newnode;
		newnode->next->prev = newnode;
		tail = newnode;
	}
	else {
		cout << "invalid insertion position = " << position << endl;
		return false;
	}
return true;
}



//Delete a node at the beginning
int delete_begin() {

	if (nullptr == tail) {
		cout << "list empty.." << endl;
		return -1;
	}

	Node *delnode = tail->next;
	int  deldata  = delnode->data;

	if (tail->next == tail) {
		//only one node present
		tail = nullptr;
	}else {
		tail->next = delnode->next;
		delnode->next->prev = tail;
	}
	delete delnode;
	return deldata;
}




//Delete the node at the end
int delete_end() {

	if (nullptr == tail) {
		cout << "list empty.." << endl;
		return -1;
	}
	Node *delnode = tail;
	int  deldata  = delnode->data;

	if (tail->next == tail) {
		//only one node present
		tail = nullptr;
	}else {
		//locate the node previous to tail
		Node *prevnode = tail->prev;

		prevnode->next = tail->next;
		prevnode->next->prev = prevnode;
		tail = prevnode;
	}
	delete delnode;
	return deldata;
}



//Delete the node at a middle position
int delete_middlepos(int position) {

	if (position < 1) {
		cout << "invalid deletion position = " << position << endl;
		return -1;
	}

	if (nullptr == tail) {
		cout << "list empty.." << endl;
		return -1;
	}

	if ( position == 1) {
		return delete_begin();
	}

	int curpos = 1;
	Node *curr = tail->next;

	while (curr != tail and curpos < position) {
		curpos++;
		curr = curr->next;
	}

	if ( curr != tail and curpos == position ) {
		Node *delnode = curr;
		int  deldata  = delnode->data;

		curr->prev->next = curr->next;
		curr->next->prev = curr->prev;
		delete delnode;
		return deldata;
	} 
	else if ( curr == tail and curpos == position) {
		Node *delnode = curr;
		int  deldata  = delnode->data;

		curr->prev->next = curr->next;
		curr->next->prev = curr->prev;
		tail = curr->prev;

		delete delnode;
		return deldata;
	}
	else {
		cout << "invalid deletion position = " << position << endl;
		return -1;
	}
}



//Display the linked list
void display() {
	cout << "List contents : ";
	if (nullptr == tail) {
		cout << "empty" << endl;
	}
	else {
		Node *tmp = tail->next;
		while(tmp != tail) {
			cout << tmp->data << "-->";
			tmp = tmp->next;
		}
		cout << tail->data << endl;
	}
}

//Display the linked list
void display_reverse() {
	cout << "Reverse iteration : ";
	if (nullptr == tail) {
		cout << "empty" << endl;
	}
	else {
		Node *tmp = tail;
		while(tmp != tail->next) {
			cout << tmp->data << "-->";
			tmp = tmp->prev;
		}
		cout << tail->data << endl;
	}
}



//Is empty
bool isempty() {
	return nullptr == tail;
}


//Reverse iterative method - Single scan (inplace reversal)
bool reverse_iterative() {

	if (nullptr == tail or tail == tail->next ) {
		return true;
	}

	Node *prev     = tail;
	Node *curr     = tail->next;
	Node *nextnode;
	while (curr != tail) {
		nextnode = curr->next;
		curr->next = prev;
		curr->prev = nextnode;
		prev = curr;
		curr = nextnode;
	}
	tail = curr->next;
	curr->next = prev;
	curr->prev = nextnode;
return true;
}

