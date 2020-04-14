//Insertion Sort Algorithm (Inplace Sort)
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

