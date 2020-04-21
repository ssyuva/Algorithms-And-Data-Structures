//Quick Sort Algorithm (Inplace Sort) AKA Partition Exchange Sort.
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


int partition(int dt[], int lower_bound, int upper_bound);

void quick_sort(int dt[], int lower_bound, int upper_bound);

int data_size  = 8;

int main()
{
	cout << "Quick Sort (Partition-Exchange Sort) Algorithm (Inplace Sort)" << endl;
	cout << "-------------------------------------------------------------" << endl;
	
	int data[]     = {99, 5, 77, 58, 50, 23, 3, 11};
	
	cout << "Unsorted Array : " << endl;
	display(data, data_size);
	
	cout << "Sorting Array : " << endl;
	quick_sort(data, 0, data_size-1);
	
	cout << "Sorted Array : " << endl;
	display(data, data_size);
}


//Quick sort 
//Best case 	- O(n log n)
//Average case 	- O(n log n)
//Worst case	- O(n squared)
//Space complexity - O(1)

//Quick sort is a divide and conquer sorting algorithm. It has two main tasks represented by two routines 1) A partitioning routine that
//partitions the data set into two parts a) the left set that is lesser than the pivot b) the right set that is greater than the pivot
//2) A quicksort routine that repeately applies partitioning and quick-sort recursion to the left and right subsets.

void quick_sort(int dt[], int lower_bound, int upper_bound) {
	cout << "Called quicksort(dt, lb = " << lower_bound << ", ub = " << upper_bound << ")" << endl;
	usleep(1000 * 1000);
	int partition_location = partition(dt, lower_bound, upper_bound);
	display(dt, data_size);
	
	if ( partition_location -1 > lower_bound) {
		quick_sort(dt, lower_bound, partition_location - 1);
		//display(dt, data_size);
	}

	if (partition_location + 1 < upper_bound) {
		quick_sort(dt, partition_location + 1, upper_bound);
		//display(dt, data_size);
	}
}

int partition (int dt[], int lower_bound, int upper_bound) {
	int pivot_idx = lower_bound;
	int start = lower_bound;
	int end   = upper_bound;

	cout << "Called partition(dt, lb = " << lower_bound << ", ub = " << upper_bound << ")" << endl;
	usleep(1000 * 1000);
	while (start <= end) {
		//move start to the right as long as you see elements that are less than the pivot
		while(dt[start] <= dt[pivot_idx]) {
			start++;
		}
		
		//move end to the left as long as you see elements that are greater than the pivot
		while(dt[end] > dt[pivot_idx]) {
			end--;
		}
		
		if (start < end) {
			//keep partitioning
			int temp   = dt[start];
			dt[start]  = dt[end];
			dt[end]    = temp;
		}

		if (end < start) {
			//fix the location of the pivot element
			int temp   = dt[end];
			dt[end]  = dt[pivot_idx];
			dt[pivot_idx]    = temp;
		}
	}
	//return the pivot location
	cout << "partition() returning pivot location = " << end << endl;
	return end;
}
