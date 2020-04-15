//Shell Sort Algorithm
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



void shell_sort(int dt[], int size);



int main()
{
	cout << "        Shell Sort Algorithm (Inplace Sort)" << endl;
	cout << "-------------------------------------------------------------" << endl;
	
	int data[]     = {99, 5, 77, 58, 50, 23, 3, 11};
	int data_size  = 8;
	
	cout << "Unsorted Array : " << endl;
	display(data, data_size);
	
	cout << "Sorting Array : " << endl;
	shell_sort(data, data_size);
	
	cout << "Sorted Array : " << endl;
	display(data, data_size);
}



//Shell sort 
//Best case 	- 
//Average case 	- 
//Worst case	- 
//Space complexity - O(1)

//Shell sort works by moving larger elements towards the right and smaller elements to the left. 
//The move-gap starts from n/2 and goes all the way upto 1 halving in every move iteration.


void shell_sort(int dt[], int size) {	
	
	for (int gap = size/2 ; gap > 0 ; gap = gap / 2) {

		int i = 0;
		cout << "size = " << size << ", gap = " << gap << endl;

		while ( i + gap < size ) {

			int first_idx = i;
			int secnd_idx = i + gap;

			if ( dt[first_idx] > dt[secnd_idx]) {

				int t = dt[first_idx];
				dt[first_idx] = dt[secnd_idx];
				dt[secnd_idx] = t;

				//display the walk forward swaps
				cout << "walk forward =>  " << "Exchange (" << dt[secnd_idx] << ", " << dt[first_idx] << ")" << endl;;
				display(dt, size);

				int curr_idx = first_idx;
				int prev_idx = curr_idx - gap;

				while (curr_idx >= 0 && prev_idx >= 0 && dt[curr_idx] < dt[prev_idx]) {
					//propagate smaller elements towards the farthest left when found
					int t = dt[prev_idx];
					dt[prev_idx] = dt[curr_idx];
					dt[curr_idx] = t;

					//display the walk backward swaps
					cout << "walk backward =>  " << "Exchange (" << dt[curr_idx] << ", " << dt[prev_idx] << ")" << endl;;
					display(dt, size);

					curr_idx = prev_idx;
					prev_idx = curr_idx - gap;
				}
			}
			i++;
		}
	}
}
