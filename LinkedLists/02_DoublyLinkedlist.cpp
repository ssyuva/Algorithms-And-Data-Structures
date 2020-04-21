//Implementation of doubly linked list
//Author: Yuvaraja Subramaniam ( www.linkedin.com/in/yuvaraja )

/* Singly linked list:

	Sequential access only data structure. No random access possible.
	Supports forward iteration as well as reverse iteration.
	
	insert_begin()      - O(1)
    insert_end()        - O(1) [ there exists a rear pointer, else this will be O(n) ]
    insert_middlepos()  - O(n/2) = O(n)

	delete_begin()      - O(1)
    delete_end()        - O(1) [ there exists a rear pointer, else this will be O(n) ]
    delete_middlepos()  - O(n/2) = O(n)

	display()           - O(n)
	isempty()           - O(1)

	reverse()           - O(n)

	The operations in the end when there is no rear pointer takes O(n) time complexity.
	This can be reduced to O(1) complexity by keeping additional rear pointers

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
bool isempty();


//reversal methods
bool reverse_iterative();


Node *head = nullptr;
Node *tail = nullptr;


int main() {

	cout << "                                   SINGLY LINKED LIST                               " << endl;
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
		cout <<" h) Is empty?"          << endl;
		cout <<" i) Reverse - single scan (inplace pointer swap)" << endl;
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
				bool mty = isempty();
				cout << "Is empty = " << (mty?"yes":"no") << endl;
				break;
			}
			case 'i' :
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

	if (nullptr == head and nullptr == tail) {
		head = newnode;
		tail = newnode;
		head->prev = nullptr;
		tail->next = nullptr;
	}
	else {
		newnode->next = head;
		head->prev    = newnode;
		newnode->prev = nullptr;
		head = newnode;
	}
	return true;
}



//Insert at the end
bool insert_end( int item ) {
	
	Node *newnode = new Node;
	newnode->data = item;

	if (nullptr == head and nullptr == tail) {
		head = newnode;
		tail = newnode;
		head->prev = nullptr;
		tail->next = nullptr;
	}
	else {
		newnode->next = nullptr;
		newnode->prev = tail;
		tail->next    = newnode;
		tail = newnode;
	}
return true;
}



//Insert as a node at particular position
bool insert_middlepos( int item, int position ) {

	if ( (nullptr == head and position > 1) or (position < 1) ) {
		cout << "invalid insertion position = " << position << endl;
		return false;
	}

	Node *curr     = head;
	Node *prevnode = head; 
	int curpos = 1;
	

	while (curr != nullptr and curpos < position) {
		curpos++;
		prevnode = curr;
		curr = curr->next;
	}

	if (curpos == 1 and position == 1) {
	
		Node *newnode = new Node;
		newnode->data = item;
		
		if (nullptr == head and nullptr == tail) {
			newnode->prev = nullptr;
			newnode->next = nullptr;
			head = tail = newnode;
		}
		else {
			newnode->prev = nullptr;
			newnode->next = head;
			head->prev    = newnode;
			head          = newnode;
		}
	}
	else if (curpos == position) {
		Node *newnode = new Node;
		newnode->data = item;
	
		if (prevnode == tail) {
			newnode->next = nullptr;
			newnode->prev = tail;
			tail->next    = newnode;
			tail          = newnode;
		}
		else {
			newnode->next = curr;
			newnode->prev = prevnode;
			curr->prev    = newnode;
			prevnode->next = newnode;
		}
	}
	else {
		cout << "invalid insertion position = " << position << endl;
		return false;
	}
return true;
}




//Delete a node at the beginning
int delete_begin() {

	if (nullptr == head) {
		cout << "list empty" << endl;
		return -1;
	}
	Node *delnode = head;
	int  deldata  = head->data;

	if (head == tail) {
		head = tail = nullptr;
	}
	else {
		head = head->next;
		head ->prev = nullptr;
	}

	delete delnode;
	return deldata;
}




//Delete the node at the end
int delete_end() {

	if (nullptr == head) {
		cout << "list empty.." << endl;
		return -1;
	}
	Node *delnode = tail;
	int  deldata  = tail->data;

	if (head == tail) {
		head = tail = nullptr;
	}
	else {
		tail = tail->prev;
		tail->next = nullptr;
	}

	delete delnode;
	return deldata;
}


//Delete the node at a middle position
int delete_middlepos(int position) {
	if (nullptr == head) {
		cout << "list empty.." << endl;
		return -1;
	}

	if (position < 1) {
			cout << "invalid deletion position = " << position << endl;
			return -1;
	}

	if (1 == position) {
		return delete_begin();
	}
	else {
		int curpos = 1;
		Node *curr     = head;
		Node *prevnode = head;

		while (curr != nullptr and curpos < position) {
			curpos++;
			prevnode = curr;
			curr = curr->next;
		}

		if (curpos == position and curr != nullptr) {
			
			Node *delnode = curr;
			int  deldata  = delnode->data;

			prevnode->next = curr->next;
			if (curr->next != nullptr) {
				curr->next->prev = prevnode;
			}
			else
			{
				tail = prevnode;
			}
			
			delete delnode;
			return deldata;
		}
		else {
			cout << "invalid deletion position = " << position << endl;
			return -1;
		}
	}
}



//Display the linked list
void display() {
	cout << "List contents : ";
	if (nullptr == head) {
		cout << "empty" << endl;
	}
	else {
		Node *tmp = head;
		while(tmp != nullptr) {
			cout << tmp->data << "-->";
			tmp = tmp->next;
		}
		cout << "nullptr" << endl;
	}
}



//Is empty
bool isempty() {
	return nullptr == head;
}


//Reverse iterative - Single scan (inplace reversal)
bool reverse_iterative() {

	if (nullptr == head or nullptr == head->next ) {
		return true;
	}

	Node *prev     = nullptr;
	Node *curr     = head;
	Node *nextnode = head;
	while (nextnode != nullptr) {
		nextnode = curr->next;
		curr->next = prev;
		if (prev != nullptr) {
			prev->prev = curr;
		}
		prev = curr;
		curr = nextnode;
	}
	tail = head;
	head = prev;
return true;
}

