// Pivot index: The pivot index is the index where the sum of all the numbers 
// strictly to the left of the index is equal to the sum of all the numbers 
// strictly to the index's right.

// If the index is on the left edge of the array, then the left sum is 0 
// because there are no elements to the left. This also applies to the right edge of the array.

#include <iostream>
#include <numeric> 
using namespace std;

// Brute force approach: O(n^2)
int findPivotIndex(int arr[], int size) {
    for (int i = 0; i < size; i++) { 
        int leftsum = 0;
        int rightsum = 0;

        // Calculate left sum (strictly to the left of i)
        for (int j = 0; j < i; j++) {
            leftsum += arr[j];
        }

        // Calculate right sum (strictly to the right of i)
        for (int k = i + 1; k < size; k++) {
            rightsum += arr[k];
        }

        // Check if left sum equals right sum
        if (leftsum == rightsum) {
            return i; 
        }
    }

    return -1; 
}

// Efficient prefix sum approach: O(n)
int findPivotIndexPrefix(int arr[], int size) {
    // Step 1: Calculate the total sum of the array
    int totalSum = accumulate(arr, arr + size, 0);

    // Step 2: Initialize left sum
    int leftSum = 0;

    // Step 3: Iterate through the array to check for pivot index
    for (int i = 0; i < size; i++) {
        // Right sum is calculated as: totalSum - leftSum - arr[i]
        int rightSum = totalSum - leftSum - arr[i];

        if (leftSum == rightSum) {
            return i; // Return the pivot index
        }
        leftSum += arr[i];
    }

    return -1; 
}

int main() {
    int arr[6] = {1, 7, 3, 6, 5, 6};
    int n = 6;

    // Using the brute force approach
    int pivotIndex = findPivotIndex(arr, n);
    if (pivotIndex != -1) {
        cout << "Brute force: Pivot index is: " << pivotIndex 
             << " and element is: " << arr[pivotIndex] << endl;
    } else {
        cout << "Brute force: No pivot index found!" << endl;
    }

    // Using the prefix sum approach
    int pivotIndexPrefix = findPivotIndexPrefix(arr, n);
    if (pivotIndexPrefix != -1) {
        cout << "Prefix sum: Pivot index is: " << pivotIndexPrefix 
             << " and element is: " << arr[pivotIndexPrefix] << endl;
    } else {
        cout << "Prefix sum: No pivot index found!" << endl;
    }

    return 0;
}
