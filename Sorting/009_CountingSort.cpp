//Counting Sort Algorithm - Sort based on keys trying to figure out the starting index of every keyset. Comparisonless sorting algorithm
//Author: Yuvaraja Subramaniam

#include <iostream>
#include <unistd.h>
#include <vector>
#include <algorithm>

using namespace std;

int display(int dt[], int sz) {
	for (int i=0; i <sz-1; i++) {
		cout << dt[i] << " -> ";
	}
	cout << dt[sz-1] << endl;
}



void counting_sort(int dt[], int size);



int main()
{
	cout << "   Counting Sort Algorithm (Sort Based On Count Of Small Values)" << endl;
	cout << "----------------------------------------------------------------------" << endl;
	
	int data[]     = {1, 5, 2, 3, 5, 2, 9, 4, 23, 3, 1, 0, 1, 5, 3, 1, 3};
	int data_size  = 17;
	
	cout << "Unsorted Array : " << endl;
	display(data, data_size);
	
	cout << "Sorting Array : " << endl;
	counting_sort(data, data_size);
	
	cout << "Sorted Array : " << endl;
	display(data, data_size);
}



//Counting sort 
//Average case 	- O(N + K)
//Space complexity - O(N + K)

// 1) Find the base of K-value. i.e the maximum value in the array
// 2) Create a count array of size K
// 3) Initialize all count to zero
// 4) Scan the input array and increment corresponding number's count as and when the numebrs are seen
// 5) Calculate the accumulative index value of the counts (i.e cumulative sum)
// 6) Start scanning the input array backwards and check the cumulative index array for the index. 
// 7) Decrement the index and put the value in position n the sorted array


void counting_sort(int dt[], int size) {	

	int maxnum = dt[0];

	//find largest  number
	for (int i = 0; i < size; i++) {
		if (dt[i] > maxnum) {
			maxnum = dt[i];
		}
	}

	cout << "largest num = " << maxnum << endl; 
	
	//count the number of digits in the largest number
	int t = maxnum;

	vector<int> count(maxnum+1);

	//initialize the count to zero
	for (int i = 0; i < maxnum + 1; i++) {
		count[i] = 0;
	}

	//scan the input list and increment the counts
	for (int i = 0; i < size; i++) {
		count[dt[i]]++;
	}

	for (int i = 0; i < maxnum + 1; i++) {
		cout << "count[" << i << "] = " << count[i] << endl;
	}
	//calculate the cumulative count
	for (int i = 1; i < maxnum+1; i++) {
		count[i] = count[i] + count[i-1];
	}

	for (int i = 0; i < maxnum + 1; i++) {
		cout << "cumulative count[" << i << "] = " << count[i] << endl;
	}
	//fill the results array
	vector<int> sortedlist(size);

	cout << "size = " << size << endl;
	display(dt, size);
	cout << "scanning in reverse..." << endl;
	for (int i = size-1; i >= 0; i--) {
		int idx = --count[dt[i]];
		sortedlist[idx] = dt[i];
		cout << "seen  "<< dt[i] << ". storing at idx " << idx << endl;
	}

	//copy the reults back into initial list
	for (int i = 0; i < size; i++ ) {
		dt[i] = sortedlist[i];
	}
}
