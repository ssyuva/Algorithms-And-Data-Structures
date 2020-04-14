//Bubble Sort Algorithm (Inplace Sort)
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
void bubble_sort_improvement_1(int dt[], int sz);
void bubble_sort_improvement_2(int dt[], int sz);

int main()
{
cout << "Bubble Sort Algorithm (Inplace Sort)" << endl;
cout << "------------------------------------" << endl;

int data[]     = {99, 5, 77, 50, 58, 23, 88, 11};
int data_size  = 8;

cout << "Unsorted Array : " << endl;
display(data, data_size);

cout << "Sorting Array : " << endl;
//bubble_sort(data, data_size);
bubble_sort_improvement_1(data, data_size);

cout << "Sorted Array : " << endl;
display(data, data_size);

int data_2[]     = {2, 5, 7, 15, 32, 38, 45, 66};
int data_size_2  = 8;
cout << "Sorting Second Array to test improved version (swapped flag)  : " << endl;
cout << "Unsorted Array 2 : " << endl;
display(data_2, data_size_2);

bubble_sort_improvement_2(data_2, data_size_2);
cout << "Sorted Array 2 : " << endl;
display(data_2, data_size_2);
}


//Bubble sort initial version
//Best case 	- O(n squared)
//Average case 	- O(n squared)
//Worst case	- O(n squared)
//Space complexity - O(1)
void bubble_sort(int dt[], int sz) {
	for( int i=0; i < sz-1; i++) {

		for (int j=0; j < sz -1 ; j++) {

			if( dt[j] > dt[j+1] ) {

				int temp = dt[j];
				dt[j] = dt[j+1];
				dt[j+1] = temp;
				usleep(1000 * 1000);
				display(dt, sz);
			}
		} 
		cout << "i = " << i << " done.." << endl;
	}
}

//improved version 1 - leave out the sorted list at the end so that each individual pass can shorten over the course
//Best case 	- O(n squared)
//Average case 	- O(n squared)
//Worst case	- O(n squared)
//Space complexity - O(1)
void bubble_sort_improvement_1(int dt[], int sz) {
	for( int i=0; i < sz-1; i++) {

		for (int j=0; j < sz -1-i ; j++) {

			if( dt[j] > dt[j+1] ) {

				int temp = dt[j];
				dt[j] = dt[j+1];
				dt[j+1] = temp;
				usleep(1000 * 1000);
				display(dt, sz);
			}
		} 
		cout << "i = " << i << " done.." << endl;
	}
}

//improved version 2 - leave out the sorted list at the end. use a swap flag to decide when to stop. The best case complexity improves to O(1)
//Best case 	- O(n)
//Average case 	- O(n squared)
//Worst case	- O(n squared)
//Space complexity - O(1)
void bubble_sort_improvement_2(int dt[], int sz) {
	for( int i=0; i < sz-1; i++) {

		bool swapped = false;
		for (int j=0; j < sz -1-i ; j++) {

			if( dt[j] > dt[j+1] ) {

				int temp = dt[j];
				dt[j] = dt[j+1];
				dt[j+1] = temp;
				swapped = true;
				usleep(1000 * 1000);
				display(dt, sz);
			}
		} 
		cout << "i = " << i << " done.." << endl;

		if(!swapped) {
		cout << "swap flag not set in this pass. the array is sorted" << endl;
		return;
		}
	}
}
