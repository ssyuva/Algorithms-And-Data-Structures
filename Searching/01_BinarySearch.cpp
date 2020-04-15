//Binary Search
//Author: Yuvaraja Subramaniam

#include <iostream>
#include <unistd.h>
using namespace std;

int display(int dt[], int sz) {
	for (int i=0; i <sz-1; i++) {
		cout << dt[i] << " -> ";
	}
	cout << dt[sz-1] << endl;
}


void bubble_sort(int dt[], int sz);
int binary_search_recursive(int dt[], int lbound, int ubound, int item);
int binary_search_iterative(int dt[], int size, int item);


int main()
{
	cout << "            Binary Search           " << endl;
	cout << "------------------------------------" << endl;
	
	int data[]     = {99, 5, 77, 50, 58, 23, 88, 11};
	int data_size  = 8;
	
	cout << "Unsorted Array : " << endl;
	display(data, data_size);
	
	cout << "Sorting Array : " << endl;
	bubble_sort(data, data_size);
	
	cout << "Sorted Array : " << endl;
	display(data, data_size);
	
	cout << "--- Recusive version ---" << endl;
	cout << "Searching for 77  : " << binary_search_recursive(data, 0, data_size-1, 77) << endl;
	cout << "Searching for 100 : " << binary_search_recursive(data, 0, data_size-1, 100) << endl;
	cout << "Searching for 5   : " << binary_search_recursive(data, 0, data_size-1, 5) << endl;
	cout << "Searching for 99  : " << binary_search_recursive(data, 0, data_size-1, 99) << endl;
	cout << "--- Iterative version ---" << endl;
	cout << "Searching for 77  : " << binary_search_iterative(data, data_size, 77) << endl;
	cout << "Searching for 100 : " << binary_search_iterative(data, data_size, 100) << endl;
	cout << "Searching for 5   : " << binary_search_iterative(data, data_size, 5) << endl;
	cout << "Searching for 99  : " << binary_search_iterative(data, data_size, 99) << endl;
}


//Binary Search 
//Best case 	- O(1)
//Average case 	- O(log n)
//Worst case	- O(log n)
//Space complexity - O(1)
int binary_search_recursive(int dt[], int lbound, int ubound, int item) {
	int mid = (lbound + ubound) / 2;

	if (ubound < lbound) {
		return -1;
	}

	if (dt[mid] == item) {
		return mid;
	}	
	else if (item < dt[mid]) {
		return binary_search_recursive(dt, lbound, mid-1, item);
	}
	else {
		return binary_search_recursive(dt, mid+1, ubound, item);
	}
}


int binary_search_iterative(int dt[], int size, int item) {
	int lbound = 0;
	int ubound = size - 1;
	
	while (lbound <= ubound) {

		int mid = (lbound + ubound) / 2;

		if (dt[mid] == item) {
			return mid;
		}	
		else if (item < dt[mid]) {
			ubound = mid - 1;
		}
		else {
			lbound = mid + 1;
		}
	}
	return -1;
}


//bubble sort algorithm
void bubble_sort(int dt[], int sz) {
	for( int i=0; i < sz-1; i++) {

		bool swapped = false;
		for (int j=0; j < sz -1-i ; j++) {

			if( dt[j] > dt[j+1] ) {

				int temp = dt[j];
				dt[j] = dt[j+1];
				dt[j+1] = temp;
				swapped = true;
			}
		} 

		if(!swapped) {
		return;
		}
	}
}
