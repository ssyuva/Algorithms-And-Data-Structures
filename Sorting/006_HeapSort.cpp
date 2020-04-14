//Heap Sort Algorithm
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



void heap_sort(int dt[], int size);

void max_heapify(int dt[], int heapsize, int root_of_heap);



int main()
{
	cout << "        Heap Sort Algorithm (Inplace Sort)" << endl;
	cout << "-------------------------------------------------------------" << endl;
	
	int data[]     = {99, 5, 77, 58, 50, 23, 3, 11};
	int data_size  = 8;
	
	cout << "Unsorted Array : " << endl;
	display(data, data_size);
	
	cout << "Sorting Array : " << endl;
	heap_sort(data, data_size);
	
	cout << "Sorted Array : " << endl;
	display(data, data_size);
}



//Heap sort 
//Best case 	- O(n log n)
//Average case 	- O(n log n)
//Worst case	- O(n log n)
//Space complexity - O(n)

//Heap sort works in two steps:
// 1) Build a complete or almost complete binary tree. Make a max heap out of the binary tree.
// 2) Remove largest element at the root of the heap. Make the remainig tree almost-complete by moving
//    the last element to the root. Store the largest element just removed at the end of the remaining tree.
// 3) Re-heapify the remaining tree. Repeat steps 2, 3 until there is no more element in the heap.

// Key routines - heap_sort(), heapify()

void heap_sort(int dt[], int size) {

	//build initial max heap
	int last_non_leaf_node = size / 2;

	for (int i = last_non_leaf_node; i > 0; i--) {
		max_heapify(dt, size, i);
	}

	//remove max element, re-heapify after reducing heap size
	for (int i = size; i > 0; i--) {

		max_heapify(dt, i, 1);

		int max_element = dt[0];

		dt[0] = dt[i-1];

		dt[i-1] = max_element;

		cout << "max element = " << max_element << ", heap size = " << i << endl;
		display(dt, size);
	}
}



//heapify routine - start from n/2 th node and walk upwards towards the root repeatedly heapifying
void max_heapify(int dt[], int heapsize, int root_of_heap) {


		int largest      = root_of_heap;
		int left_child   = root_of_heap * 2 ;
		int right_child  = root_of_heap * 2 + 1;

		if (left_child <= heapsize && dt[left_child - 1] > dt [largest -1]) {
			largest = left_child;
		}

		if (right_child <= heapsize && dt[right_child - 1] > dt [largest -1]) {
			largest = right_child;
		}

		if (largest != root_of_heap) {
			int temp = dt[root_of_heap -1];
			dt[root_of_heap-1] = dt[largest -1];
			dt[largest-1] = temp;

			max_heapify(dt, heapsize, largest);
		}
}
