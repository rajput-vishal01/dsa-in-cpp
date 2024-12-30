//Exponential Search is also known as doubling search, galloping search, strazilc search
//--applied on sorted array only -- 
/*
Exponential Search :
Exponential search is an efficient algorithm for finding an element in a sorted array.
It works by first checking an element at an exponentially increasing index (i.e., 1, 2, 4, 8, 16, ...) and then performing a binary search between the last valid index and
the first index where the element may potentially be.

Key Points:
Sorted Array: Exponential search only works on a sorted array.
Initial Step: The algorithm finds the range where the target element could be by exponentially increasing the bounds.
Binary Search: Once the range is found, binary search is applied within that range to locate the target element.
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


int binarySearch(const vector<int>& arr, int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1; 
    }
    return -1;
}

int exponentialSearch(const vector<int>& arr, int target) {
    int n = arr.size();

    // Edge case: If array is empty
    if (n == 0)
        return -1;
    // If the target is the first element
    if (arr[0] == target)
        return 0;
    // Step 1: Find the range using exponential growth
    int i = 1;
    while (i < n && arr[i] <= target) {
        i = i * 2;  // Doubling the index
    }
    // Step 2: Apply binary search in the range [i/2, min(i, n-1)]
    return binarySearch(arr, i / 2, min(i, n - 1), target);
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25};
    int target = 15;

    int result = exponentialSearch(arr, target);
    if (result != -1) {
        cout << "Element " << target << " found at index " << result << endl;
    } else {
        cout << "Element " << target << " not found!" << endl;
    }
    return 0;
}
