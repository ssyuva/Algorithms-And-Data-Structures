//Radix Sort Algorithm - Sort based on digits. Comparisonless sorting algorithm
//Author: Yuvaraja Subramaniam ( www.linkedin.com/in/yuvaraja )

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



void radix_sort(int dt[], int size);



int main()
{
	cout << "        Radix Sort Algorithm (Sort Based On Values At Digit Positions)" << endl;
	cout << "----------------------------------------------------------------------" << endl;
	
	int data[]     = {99, 5, 77, 5888, 50, 23, 3, 11};
	int data_size  = 8;
	
	cout << "Unsorted Array : " << endl;
	display(data, data_size);
	
	cout << "Sorting Array : " << endl;
	radix_sort(data, data_size);
	
	cout << "Sorted Array : " << endl;
	display(data, data_size);
}



//Radix sort 
//Average case 	- O( d * (n + b) ) where d is the number of digits, n is the number of number, b is the base
//Space complexity - O(n)

// 1) Find the largest number
// 2) Find the number of digits in the larges number
// 3) Prefix the smaller numbers iwth zeroes and make all the numbers have same number of digits
// 4) Create N baskets where N is the base of the numbers
// 5) Start from the least significant digit and put the numbers in appropriate digit basket
// 6) Extract the numbers from the digit buckets and reconstruct the master list of numbers
// 7) Do steps 5 to 6 for all digits
// 8) Extract the final sorted list from the master list.


void radix_sort(int dt[], int size) {	

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
	int numdigits = 0;

	do {
		numdigits++;
		t = t / 10;
	} while ( t > 0);

	cout << "number of digits in largest number = " << numdigits << endl;
	vector< vector<int> > buckets = {
										{},
										{},
										{},
										{},
										{},
										{},
										{},
										{},
										{},
										{}
											};

	for(int i = 0, divisor = 1; i < numdigits; i++, divisor=divisor * 10) {

		cout << "digit = " << i + 1 << ", divisor = " << divisor << endl;
		//put the number as per the current digit bucket		
		for (int j = 0; j < size; j++) {
			//cout << "analysing number " << dt[j] << endl;
			int digitvalue = (dt[j] / divisor) % 10;
			//cout << "digitvalue = " << digitvalue << endl;
			buckets[digitvalue].push_back(dt[j]);
		}

		//pull the numbers out and reconstruct the array
		int n = 0;
		for (int k = 0; k <= 9; k++) {
			cout << "Bucket " << k << " : ";
			for( int m = 0; m < buckets[k].size(); m++) {
				dt[n] = buckets[k][m];
				cout << buckets[k][m] << " ";
				n++;
			}
			cout << endl;
			buckets[k].clear();
		}
	display(dt, size);
	}
}
