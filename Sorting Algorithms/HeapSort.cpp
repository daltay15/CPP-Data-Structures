#include <iostream>
#include <cstdlib>

using namespace std;

// heapify function
void heapify(int arr[], int n, int i)
{
    int largest = i;   // initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // if left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // if right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // if largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        // recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// write a heap sort function
void heapSort(int arr[], int n)
{
    // build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // one by one extract an element from heap
    for (int i = n - 1; i >= 0; i--)
    {
        // move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// print the array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

// main function
int main()
{
    int arr[] = {5, 13, 2, 25, 7, 17, 20, 8, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n);

    cout << "Sorted array is \n";
    printArray(arr, n);
}