//Selection Sort Algorithm (Inplace Sort)
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

void selection_sort(int dt[], int sz);

int main()
{
	cout << "Selection Sort Algorithm (Inplace Sort)" << endl;
	cout << "---------------------------------------" << endl;
	
	int data[]     = {99, 5, 77, 58, 50, 23, 3, 11};
	int data_size  = 8;
	
	cout << "Unsorted Array : " << endl;
	display(data, data_size);
	
	cout << "Sorting Array : " << endl;
	selection_sort(data, data_size);
	
	cout << "Sorted Array : " << endl;
	display(data, data_size);
}


//Selection sort 
//Best case 	- O(n squared)
//Average case 	- O(n squared)
//Worst case	- O(n squared)
//Space complexity - O(1)

//Selection sort - inplace sorting algorithm that works by maintaig two lists i) a sorted list a the beginning ii) followed by unsorted list
//The algorithm works by selecting the smallest element from the unsorted list and placing it at the end of the sorted list repeatedly

void selection_sort(int dt[], int sz) {
	for( int i=0; i < sz-1; i++) {

		int min_index = i;
		cout << "selecting the smallest element from the unsorted list for location - " << i << endl;

		for (int j = i+1; j < sz; j++) {
			
			if ( dt[j] < dt[min_index] ) {
				min_index = j;
			}
		}
		//swap the value at min_index to i th location
		cout << "smallest element = " << dt[min_index] << endl;
		int temp = dt[i];
		dt[i] = dt[min_index];
		dt[min_index] = temp;

		display(dt, sz);
		cout << "selection of element for location " << i << " done.." << endl;
	}
}

