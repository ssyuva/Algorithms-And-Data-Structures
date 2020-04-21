//Insertion Sort Algorithm (Inplace Sort)
//Author: Yuvaraja Subramaniam ( www.linkedin.com/in/yuvaraja )

#include <iostream>
#include <unistd.h>
using namespace std;

int display(int dt[], int sz) {
	for (int i=0; i <sz-1; i++) {
		cout << dt[i] << " -> ";
	}
	cout << dt[sz-1] << endl;
}

void insertion_sort(int dt[], int sz);

int main()
{
	cout << "Insertion Sort Algorithm (Inplace Sort)" << endl;
	cout << "---------------------------------------" << endl;
	
	int data[]     = {99, 5, 77, 50, 58, 23, 88, 11};
	int data_size  = 8;
	
	cout << "Unsorted Array : " << endl;
	display(data, data_size);
	
	cout << "Sorting Array : " << endl;
	insertion_sort(data, data_size);
	
	cout << "Sorted Array : " << endl;
	display(data, data_size);
}


//Insertion sort 
//Best case 	- O(n)
//Average case 	- O(n squared)
//Worst case	- O(n squared)
//Space complexity - O(1)

//Insertion sort is an inplace sorting algorithm that works by partitioning the dataset into two parts - a sorted part and and unsorted part
//The initial size of the sorted part is one (i.e just the first element). The algorithm picks one element from the unsorted part at a time
//and finds the right place for the item to insert into the sorted array. This way the sorted list keeps expanding and the unsorted list keeps
//shrinking. The algorithm stops when all the items from the unsorted array has been inserted into the sorted array. The algorithm finds the 
//right place for each unsorted element by shoving the items towards the right in the sorted list as long as the items in the sorted list are
//greater than the unsorted element that needs to be inserted into the sorted list.

void insertion_sort(int dt[], int sz) {
	for( int i=1; i < sz; i++) {

		int item = dt[i];
		int j = i - 1;
		int holevalue = 0;
		cout << "finding place to insert element - " << item << endl;

		while ( j  >= 0 && dt[j] > item ) {

			dt[j+1] = dt[j];
			dt[j] = holevalue;
			usleep(1000 * 1000);
			display(dt, sz);
			j--;
		}
		dt[j+1] = item; 
		display(dt, sz);
		cout << "i = " << i << " done.." << endl;
	}
}

