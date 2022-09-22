#include <iostream>
#include <cstdlib>

using namespace std;

// write a partition function
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1);     // Index of smaller element

    for (int j = low; j <= high - 1; j++) // if current element smaller than or equal to the pivot
    {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot)
        {
            i++;                  // increment index of smaller element
            swap(arr[i], arr[j]); // swap elements into correct position
        }
    }
    swap(arr[i + 1], arr[high]); // swap pivot into correct position
    return (i + 1);              // return pivot index
}

// write a quicksort function
void quickSort(int arr[], int low, int high) // low is 1st index and high is the last index
{
    if (low < high)
    {
        // pi is partitioning index, arr[p] is now at right place
        int newPivot = partition(arr, low, high);

        // separately sort elements before partition and after partition
        quickSort(arr, low, newPivot - 1);
        quickSort(arr, newPivot + 1, high);
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
    int n = sizeof(arr) / sizeof(arr[0]); // get the size of the array
    quickSort(arr, 0, n - 1);
    cout << "Sorted array: \n";
    printArray(arr, n);
    return 0;
}

// Apple is the worst company ever to ever ever ever ever exist!