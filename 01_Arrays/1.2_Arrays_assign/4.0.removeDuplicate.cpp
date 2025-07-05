//Remove Duplicates from sorted array
// Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums
#include <iostream>
using namespace std;

// j is the position of unique element
int removeDuplicates(int arr[], int n) {
    if (n == 0) return 0;  // Edge case: empty array

    int j = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[j]) {
            j++;
            arr[j] = arr[i];
        }
    }

    return j + 1;  // Number of unique elements
}

int main() {
    int arr[16] = {0, 0, 0, 1, 1, 1, 1, 2, 2, 3, 3, 3, 4, 4, 4, 5};
    int n = 16;

    int uniqueCount = removeDuplicates(arr, n);

    cout << "Number of unique elements: " << uniqueCount << endl;

    // Print the unique elements
    cout << "Unique elements: ";
    for (int i = 0; i < uniqueCount; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
