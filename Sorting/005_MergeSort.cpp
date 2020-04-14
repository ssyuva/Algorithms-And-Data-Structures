//Merge Sort Algorithm  - Divide and conquer
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


void merge(int dt[], int lower_bound, int mid, int upper_bound);

void merge_sort(int dt[], int lower_bound, int upper_bound);

int data_size  = 8;

int main()
{
	cout << "        Merge Sort Algorithm (Inplace Sort)" << endl;
	cout << "-------------------------------------------------------------" << endl;
	
	int data[]     = {99, 5, 77, 58, 50, 23, 3, 11};
	
	cout << "Unsorted Array : " << endl;
	display(data, data_size);
	
	cout << "Sorting Array : " << endl;
	merge_sort(data, 0, data_size-1);
	
	cout << "Sorted Array : " << endl;
	display(data, data_size);
}


//Merge sort 
//Best case 	- O(n log n)
//Average case 	- O(n log n)
//Worst case	- O(n log n)
//Space complexity - O(n)

//Merge is a divide & conquer strategy that divides the dataset at the median into two parts and recursively 
//applies mergesort to each part. Once the two parts are sorted, then they are merged using a merge routine. 
//key routines - a) merge_sort b) merge

void merge_sort(int dt[], int lower_bound, int upper_bound) {
	cout << "Called mergesort(dt, lb = " << lower_bound << ", ub = " << upper_bound << ")" << endl;
	usleep(1000 * 1000);
	if (lower_bound >= upper_bound) 
		return;
	
	int mid = ( lower_bound + upper_bound ) / 2;
	
	cout <<"mid = " << mid << endl;
	
	merge_sort(dt, lower_bound, mid);
	merge_sort(dt, mid+1, upper_bound);
	
	cout << "merging sorted partitions. lower_bound = " << lower_bound << ", mid = " << mid << ", upper_bound = " << upper_bound << endl;
	merge(dt, lower_bound, mid, upper_bound);

	display(dt, data_size);
	
}


void merge(int dt[], int lower_bound, int mid, int upper_bound){
	int sz = upper_bound - lower_bound + 1;
	int *merged_list = (int *) malloc(sizeof(int) * sz);
	
	int left_cur  = lower_bound;
	int right_cur = mid + 1;
	int k = 0;

	while(left_cur <= mid && right_cur <= upper_bound) {

		if(dt[left_cur] <= dt[right_cur]) {
			merged_list[k] = dt[left_cur];
			k++;
			left_cur++;
		}
		else {
			merged_list[k] = dt[right_cur];
			k++;
			right_cur++;

		}
	}
	while (left_cur <= mid) {
		merged_list[k] = dt[left_cur];
		k++;
		left_cur++;
	}
	while (right_cur <= upper_bound) {
		merged_list[k] = dt[right_cur];
		k++;
		right_cur++;
	}
	//copy the merged list to original list
	for(int i = 0; i < k; i++) {
		dt[lower_bound + i] = merged_list[i];
	}
}
