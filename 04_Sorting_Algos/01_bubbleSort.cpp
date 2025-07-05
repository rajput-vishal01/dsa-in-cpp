/*
Bubble Sort Algorithm:

Bubble Sort is a simple sorting algorithm that works by repeatedly stepping through the list,
comparing adjacent elements, and swapping them if they are in the wrong order. This process 
is repeated until the list is sorted.

Key Characteristics:
1. It gets its name because smaller elements "bubble" to the top (beginning) of the list.
2. In each pass, the largest unsorted element moves to its correct position.
3. It has a worst-case and average time complexity of O(n^2), making it inefficient for large datasets.

Algorithm Steps:
1. Start at the first element of the array.
2. Compare the current element with the next element.
3. If the current element is greater than the next, swap them.
4. Repeat steps 2-3 for the entire array (n-1 passes for an array of size n).
5. After each pass, the largest unsorted element is placed at the correct position.
6. Repeat until no swaps are needed or the array is fully sorted.

Example:
Input: [5, 2, 9, 1, 5, 6]
Pass 1: [2, 5, 1, 5, 6, 9]
Pass 2: [2, 1, 5, 5, 6, 9]
Pass 3: [1, 2, 5, 5, 6, 9]
Final Output: [1, 2, 5, 5, 6, 9]

Time Complexity of Bubble Sort:
1. Best Case: O(n) - Occurs when the array is already sorted (requires one pass, no swaps).
2. Average Case: O(n^2) - Occurs when the array is partially sorted or unsorted.
3. Worst Case: O(n^2) - Occurs when the array is sorted in reverse order.

Space Complexity:
1. Space Complexity: O(1) - In-place sorting, no extra space required.
*/

#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) { 
        for (int j = 0; j < n - i - 1; j++) { 
            if (arr[j] > arr[j + 1]) {
                // Swap the elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {5, 2, 9, 1, 5, 6};
    int n = 6;

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl; 
    bubbleSort(arr, n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
