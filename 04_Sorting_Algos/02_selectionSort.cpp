/*
Selection Sort Algorithm:

Selection Sort is a simple comparison-based sorting algorithm. It divides the input array into two parts: 
the sorted part and the unsorted part. Initially, the sorted part is empty, and the unsorted part contains 
the entire array. The algorithm repeatedly selects the smallest (or largest, depending on sorting order) 
element from the unsorted part and moves it to the sorted part.

Key Characteristics:
1. Selection Sort repeatedly selects the smallest remaining element.
2. It places the smallest element at its correct position in each iteration.
3. The algorithm has a time complexity of O(n^2), making it inefficient for large datasets.

Algorithm Steps:
1. Start with the first element in the array.
2. Find the smallest element in the unsorted part of the array.
3. Swap the smallest element with the first element of the unsorted part.
4. Move the boundary of the sorted part one element to the right.
5. Repeat steps 2-4 until the array is fully sorted.

Example:
Input: [64, 25, 12, 22, 11]
Pass 1: [11, 25, 12, 22, 64] (11 is the smallest)
Pass 2: [11, 12, 25, 22, 64] (12 is the smallest in the remaining array)
Pass 3: [11, 12, 22, 25, 64] (22 is the smallest)
Pass 4: [11, 12, 22, 25, 64] (25 is the smallest)
Final Output: [11, 12, 22, 25, 64]

Time Complexity of Selection Sort:
1. Best Case: O(n^2) - Selection Sort does not optimize for already sorted arrays.
2. Average Case: O(n^2) - Always makes n*(n-1)/2 comparisons regardless of array state.
3. Worst Case: O(n^2) - Same as average case, as comparisons are always performed.

Space Complexity:
1. Space Complexity: O(1) - In-place sorting, no extra space required.

*/

#include <iostream>
using namespace std;


void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Find the index of the smallest element in the unsorted part
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the smallest element with the first element of the unsorted part
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = 5;
    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    selectionSort(arr, n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
