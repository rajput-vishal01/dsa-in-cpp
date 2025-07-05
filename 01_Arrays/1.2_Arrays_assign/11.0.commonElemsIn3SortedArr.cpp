/*
You are given three arrays sorted in increasing order. Find the elements that are common in all three arrays.
If there are no such elements return an empty array. In this case, the output will be -1.

Input: arr1 = [1, 5, 10, 20, 40, 80] , arr2 = [6, 7, 20, 80, 100] , arr3 = [3, 4, 15, 20, 30, 70, 80, 120]
Output: [20, 80]
Explanation: 20 and 80 are the only common elements in arr, brr and crr.

*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> findCommonElements(int arr1[], int n1, int arr2[], int n2, int arr3[], int n3) {
    vector<int> commonElements;
    int i = 0, j = 0, k = 0; // Pointers for arr1, arr2, arr3

    // Traverse all arrays until one of them is exhausted
    while (i < n1 && j < n2 && k < n3) {
        // If the elements are equal, add to result and move all pointers
        if (arr1[i] == arr2[j] && arr2[j] == arr3[k]) {
            commonElements.push_back(arr1[i]);
            i++;
            j++;
            k++;
        }
        // Move the pointer of the smallest element forward
        else if (arr1[i] < arr2[j]) {
            i++;
        } else if (arr2[j] < arr3[k]) {
            j++;
        } else {
            k++;
        }
    }

    return commonElements; // Return the list of common elements
}

int main() {
    // Example input arrays
    int arr1[] = {1, 5, 10, 20, 40, 80};
    int arr2[] = {6, 7, 20, 80, 100};
    int arr3[] = {3, 4, 15, 20, 30, 70, 80, 120};

    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int n3 = sizeof(arr3) / sizeof(arr3[0]);

    // Find common elements
    vector<int> result = findCommonElements(arr1, n1, arr2, n2, arr3, n3);

    // Print result
    cout << "Common elements: ";
    for (int elem : result) {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}
