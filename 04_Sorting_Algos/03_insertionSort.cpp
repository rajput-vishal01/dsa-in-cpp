/*
Insertion Sort Algorithm:

Insertion Sort is a simple sorting algorithm that works similar to the way you might sort playing cards in your hands. 
The array is conceptually divided into two parts: the sorted part and the unsorted part. Values from the unsorted 
part are picked one at a time and placed in their correct position in the sorted part.

Key Characteristics:
1. Insertion Sort is efficient for small datasets or arrays that are already nearly sorted.
2. It has a worst-case and average time complexity of O(n^2).
3. Best-case time complexity is O(n) when the array is already sorted.

Algorithm Steps:
1. Start from the second element (index 1), considering the first element (index 0) as already sorted.
2. Pick the current element and compare it with the elements in the sorted part of the array.
3. Shift all elements in the sorted part that are greater than the current element to one position to the right.
4. Insert the current element at its correct position in the sorted part.
5. Repeat steps 2-4 for all elements in the array.

Example:
Input: [12, 11, 13, 5, 6]
Pass 1: [11, 12, 13, 5, 6] (11 inserted in its correct position)
Pass 2: [11, 12, 13, 5, 6] (13 remains in its position)
Pass 3: [5, 11, 12, 13, 6] (5 inserted in its correct position)
Pass 4: [5, 6, 11, 12, 13] (6 inserted in its correct position)
Final Output: [5, 6, 11, 12, 13]


Time Complexity of Insertion Sort:
1. Best Case: O(n) - Occurs when the array is already sorted (requires no shifting).
2. Average Case: O(n^2) - Occurs when the array is partially sorted or unsorted.
3. Worst Case: O(n^2) - Occurs when the array is sorted in reverse order (maximum shifting needed).

Space Complexity:
1. Space Complexity: O(1) - In-place sorting, no extra space required.

*/

#include <iostream>
using namespace std;

// Insertion Sort Function
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i]; // Current element to be inserted
        int j = i - 1;

        // Move elements of arr[0..i-1] that are greater than 'key' one position to the right
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        
        // Place the key at its correct position
        arr[j + 1] = key;
    }
}


int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = 5;

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    insertionSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
