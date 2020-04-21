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

	reverse()           - O(n)

	The operations in the end when there is no rear pointer takes O(n) time complexity.
	This can be reduced to O(1) complexity by keeping additional rear pointers ( need two rear
	pointers for delete_end() operation ) 

*/


#include <iostream>

using namespace std;

struct Node {
	int data;
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
bool reverse_method_A();
bool reverse_method_B();
Node * reverse_method_C(Node *list);


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
		cout <<" i) Reverse - single scan (build another list)"  << endl;
		cout <<" j) Reverse - single scan (inplace poiner swap)" << endl;
		cout <<" k) Reverse - recursive"                         << endl;
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
				bool res = reverse_method_A();
				cout << "Reversed list using method A (single scan, build another reversed list)" << endl;
				break;
			}
			case 'j' :
			{
				bool res = reverse_method_B();
				cout << "Reversed list using method B (insplace pointer swap)" << endl;
				break;
			}
			case 'k' :
			{
				head = reverse_method_C( head );
				cout << "Reversed list using method C (recursive)" << endl;
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

	if (nullptr == head and position > 1) {
		cout << "invalid insertion position = " << position << endl;
		return false;
	}
	if ( 1 == position )  {
		Node *newnode = new Node;
		newnode->data = item;
		newnode->next = head;
		head = newnode;
		return true;
	}

	int curpos = 1;
	Node *curr = head;
	Node *prev = head;

	while ( nullptr != curr and curpos < position ) {
		curpos++;
		prev = curr;
		curr = curr->next;
	}

	if (curpos == position) {
		Node *newnode = new Node;
		newnode->data = item;
		newnode->next = curr;
		prev->next    = newnode;
		return true;
	}
	else {
		cout << "invalid insertion position = " << position << endl;
		return false;
	}
}




//Delete a node at the beginning
int delete_begin() {

	if (nullptr == head) {
		cout << "list empty.." << endl;
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
		cout << "list empty.." << endl;
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
		cout << "list empty.." << endl;
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


//Reverse method 1 - Single scan (build another list)
bool reverse_method_A(){

	Node *revlist = nullptr;
	Node *tmp = head;
	while (nullptr != tmp) {
		Node *nextnode = tmp->next;
		tmp->next = revlist;
		revlist   = tmp;
		tmp = nextnode;
	}
head = revlist;
return true;
}



//Reverse method 2 - Single scan (inplace reversal)
bool reverse_method_B() {

	if (nullptr == head or nullptr == head->next ) {
		return true;
	}

	Node *prev     = nullptr;
	Node *curr     = head;
	Node *nextnode = head;
	while (nextnode != nullptr) {
		nextnode = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nextnode;
	}
	head = prev;
return true;
}


//Reverse method 3 - Recursive reversal
Node * reverse_method_C(Node *head) {

	if ( nullptr == head ) {
		return head;
	}
	if (nullptr == head->next) {
		return head;
	}

	Node *curr = head;
	Node *rest = head->next;
	Node *reverse_rest = reverse_method_C(rest);

	Node *prev = reverse_rest;
	Node *tmp  = reverse_rest;

	while (tmp != nullptr) {
		prev = tmp;
		tmp = tmp->next;
	}
	prev->next = curr;
	curr->next = nullptr;

	return reverse_rest;	
}


