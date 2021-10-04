// A C++ program to find k'th smallest element using min heap

#include <climits>
#include <iostream>
using namespace std;


void swap(int* x, int* y);

class MinHeap {
	int* harr; 
	int capacity; 
	int heap_size; 

public:
	MinHeap(int a[], int size); 
	void MinHeapify(int i); 
	int parent(int i) { return (i - 1) / 2; }
	int left(int i) { return (2 * i + 1); }
	int right(int i) { return (2 * i + 2); }

	int extractMin(); 
	int getMin() { return harr[0]; } 
};

MinHeap::MinHeap(int a[], int size)
{
	heap_size = size;
	harr = a; // store address of array
	int i = (heap_size - 1) / 2;
	while (i >= 0) {
		MinHeapify(i);
		i--;
	}
}


int MinHeap::extractMin()
{
	if (heap_size == 0)
		return INT_MAX;

	
	int root = harr[0];

	if (heap_size > 1) {
		harr[0] = harr[heap_size - 1];
		MinHeapify(0);
	}
	heap_size--;

	return root;
}

void MinHeap::MinHeapify(int i)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if (l < heap_size && harr[l] < harr[i])
		smallest = l;
	if (r < heap_size && harr[r] < harr[smallest])
		smallest = r;
	if (smallest != i) {
		swap(&harr[i], &harr[smallest]);
		MinHeapify(smallest);
	}
}


void swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}


int kthSmallest(int arr[], int n, int k)
{
	
	MinHeap mh(arr, n);

	for (int i = 0; i < k - 1; i++)
		mh.extractMin();

	return mh.getMin();
}


int main()
{
	int arr[] = { 12, 3, 5, 7, 19 };
	int n = sizeof(arr) / sizeof(arr[0]), k = 2;
	cout << "K'th smallest element is " << kthSmallest(arr, n, k);
	return 0;
}

/*
OUTPUT :

K'th smallest element is 5

*/


