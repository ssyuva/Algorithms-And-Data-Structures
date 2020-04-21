//Implementation of singly linked list
//Author: Yuvaraja Subramaniam ( www.linkedin.com/in/yuvaraja )

/* Singly linked list:

	Sequential access only data structure. No random access possible.
	
	insert_begin()      - O(1)
    insert_end()        - O(n)
    insert_middlepos()  - O(n/2) = O(n)

	delete_begin()      - O(1)
    delete_end()        - O(n)
    delete_middlepos()  - O(n/2) = O(n)

	display()           - O(n)
	isempty()           - O(1)

	The operations in the end when there is no rear pointer takes O(n) time complexity.
	This can be reduced to O(1) complexity by keeping additional rear pointers ( need two rear
	pointers for delete_end() operation ) 

*/


#include <iostream>

using namespace std;

//prototypes
bool insert_begin(int item); 
bool insert_end(int item); 
bool insert_middlepos(int item, int position); 

int delete_begin(); 
int delete_end(); 
int delete_middlepos(int position); 

void display();
bool isempty();

struct Node {
	int data;
	struct Node *next;
};


Node *head;


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
		}
		cout<<endl;
		//usleep( 1000 * 1000);
	} while (choice != 'q' or choice == 'Q');
}



//Insert at the beginning
bool insert_begin( int item ) {
	
	Node *newnode = new Node;
	newnode->data = item;
	newnode->next = head;
	head = newnode;
	return true;
}



//Insert at the end
bool insert_end( int item ) {
	
	Node *newnode = new Node;
	newnode->data = item;
	newnode->next = nullptr;

	if (nullptr == head) {
		head = newnode;
	} 
	else {
		Node *tmp = head;
		while( nullptr != tmp->next ) {
			tmp = tmp->next;
		}
		tmp->next = newnode;
	}
return true;
}



//Insert as a node at particular position
bool insert_middlepos( int item, int position ) {

	if ( nullptr == head and 1 == position )  {
		Node *newnode = new Node;
		newnode->data = item;
		newnode->next = nullptr;
		head = newnode;
		return true;
	}
	else if (nullptr == head and position > 1) {
		cout << "invalid insertion position = " << position << endl;
		return false;
	}
	else {
		int curpos = 1;
		Node *tmp = head;
		Node *prev = head;

		while ( nullptr != tmp and curpos < position ) {
			curpos++;
			prev = tmp;
			tmp  = tmp->next;
		}

		if (curpos == position) {
			Node *newnode = new Node;
			newnode->data = item;
			newnode->next = nullptr;
			prev->next    = newnode;
			return true;
		}
		else {
			cout << "invalid insertion position = " << position << endl;
			return false;
		}
	}
}




//Delete a node at the beginning
int delete_begin() {

	if (nullptr == head) {
		return -1;
	}
	else {
		Node *delnode = head;
		int  deldata  = delnode->data;

		head = head->next;
		delete delnode;
		return deldata;
	}
}




//Delete the node at the end
int delete_end() {

	if (nullptr == head) {
		return -1;
	}
	else if (nullptr == head->next) {
		Node *delnode = head;
		int  deldata  = delnode->data;

		head = head->next;
		delete delnode;
		return deldata;
	}
	else {
		Node *curr = head;
		Node *prev = head;

		while (nullptr != curr->next) {
			prev = curr;
			curr = curr->next;		
		}
	
		Node *delnode = curr;
		int  deldata  = delnode->data;

		prev->next = nullptr;
		delete delnode;
		return deldata;
	}
}


//Delete the node at a middle position
int delete_middlepos(int position) {
	if (nullptr == head) {
		return -1;
	}
	else if ( 1 == position ) {
		Node *delnode = head;
		int  deldata  = delnode->data;
		
		head = head->next;
		delete delnode;
		return deldata;
	}
	else {
		int curpos = 1;
		Node *curr = head;
		Node *prev = head;
		while (nullptr != curr->next and curpos < position) {
			curpos++;
			prev = curr;
			curr = curr->next;
		}
		
		if (curpos == position) {
			Node *delnode = curr;
			int deldata = delnode->data;

			prev->next = delnode->next;
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
