/*
Implement Heap sort to sort given set of values using max or min heap.
*/
#include "iostream"
#include "cstdlib"

using namespace std;

void MaxHeapify(int a[], int i, int n) 
{
    int j;
    int temp;
    temp = a[i];
    j = 2 * i;

    while (j <= n) 
    {
        if (j < n && a[j + 1] > a[j]) 
        {
            j = j + 1;
        }
        if (temp > a[j]) 
        {
            break;
        } else if (temp <= a[j]) 
        {
            a[j / 2] = a[j];
            j = 2 * j;
        }
    }
    a[j / 2] = temp;
    return;
}

void Build_MaxHeap(int a[], int n) 
{
    int i;
    for (i = n / 2; i >= 1; i--) 
    {
        MaxHeapify(a, i, n);
    }
}

void Max_HeapSort(int a[], int n) 
{
    int i;
    int temp;
    for (i = n; i >= 2; i--) 
    {
        temp = a[i];
        a[i] = a[1];
        a[1] = temp;

        MaxHeapify(a, 1, i - 1);
    }
}

void min_heapify(int a[], int i, int n) 
{
    int j;
    int temp;
    temp = a[i];
    j = 2 * i;

    while (j <= n) 
    {
        if (j < n && a[j + i] < a[j]) 
        {
            j = j + 1;
        }
        if (temp < a[j]) 
        {
            break;
        } else if (temp >= a[j]) 
        {
            a[j / 2] = a[j];
            j = 2 * j;
        }
    }
    a[j / 2] = temp;
    return;
}

void build_minheap(int a[], int n) 
{
    int i;
    for (i = n / 2; i >= 1; i--) 
    {
        min_heapify(a, i, n);
    }
}

void Min_HeapSort(int a[], int n) 
{
    int i;
    int temp;
    for (i = n; i >= 2; i--) 
    {
        temp = a[i];
        a[i] = a[1];
        a[1] = temp;

        min_heapify(a, 1, i - 1);
    }
}

void print(int arr[], int n) 
{
    cout << "Sorted Data " << endl;

    for (int i = 1; i <= n; i++) 
    {
        cout << "->" << arr[i];
    }
    cout << endl;
    return;
}

int main() 
{
    int n;
    int i;
    int ch;
    cout << "Enter the number of data element to be sorted : " << endl;
    cin >> n;

    int arr[n];
    for (i = 1; i <= n; i++) 
    {
        cout << "Enter Element " << i << " : " << endl;
        cin >> arr[i];
    }

    do 
    {
        cout << "1) Heap Sort using Max Heap." << endl;
        cout << "2) Heap Sort using Min Heap." << endl;
        cout << "3) Exit." << endl;

        cout << "Enter your choice" << endl;
        cin >> ch;

        switch (ch) {
            case 1:
                Build_MaxHeap(arr, n);
                Max_HeapSort(arr, n);
                print(arr, n);
                break;
            case 2:build_minheap(arr, n);
                Min_HeapSort(arr, n);
                print(arr, n);
                break;
            case 3:
                return 0;
            default:
                cout << "!!! Invalid Choice !!!" << endl;
        }
    }
    while (ch!=3);

    return 0;
}