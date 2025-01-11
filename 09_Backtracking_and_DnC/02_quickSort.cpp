/*
Quicksort Algorithm 

This program demonstrates the Quicksort algorithm using the Lomuto partition scheme. 
The algorithm follows these steps:

1. **Partitioning**:
   - **Pivot Selection**: The last element of the array is chosen as the pivot.
   - **Indexing**:
     - `i` starts from `low - 1`.
     - `j` iterates from `low` to `high - 1`.
   - **Comparison and Swapping**:
     - For each element `arr[j]`:
       - If `arr[j]` is less than or equal to the pivot:
         - Increment `i`.
         - Swap `arr[i]` with `arr[j]`.
   - **Placing the Pivot**: After the loop, the pivot is placed in its correct position by swapping `arr[i + 1]` with `arr[high]`.
   - **Return Value**: The function returns the index `i + 1`, which is the new position of the pivot.

2. **Quicksort Function**:
   - **Recursive Sorting**:
     - If `low` is less than `high`:
       - Partition the array to get the pivot index.
       - Recursively apply Quicksort to the subarrays:
         - From `low` to `pivotIndex - 1`.
         - From `pivotIndex + 1` to `high`.

3. **Main Function**:
   - An example array is defined and printed.
   - The `quickSort` function is called to sort the array.
   - The sorted array is printed.

This implementation uses the `std` namespace for standard library functions and types.
*/

#include <iostream>
#include <vector>
#include <algorithm> // For std::swap

using namespace std;

// Function to partition the array and return the pivot index
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Quicksort function
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

// Utility function to print the array
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {9, 4, 8, 3, 7, 1, 6, 2, 5};
    int n = arr.size();
    cout << "Original array: ";
    printArray(arr);
    quickSort(arr, 0, n - 1);
    cout << "Sorted array: ";
    printArray(arr);
    return 0;
}
