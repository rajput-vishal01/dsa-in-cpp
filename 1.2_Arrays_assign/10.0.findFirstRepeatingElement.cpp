
/*
Problem:
Given an array arr[], find the first repeating element. The element should occur more than once,
and the index of its first occurrence should be the smallest.

Example:
Input: arr[] = [1, 5, 3, 4, 3, 5, 6]
Output: 1
Explanation: Both 5 and 3 are repeated, but 5's first occurrence (index 1) is smaller than 3's first occurrence (index 2).
*/

/*
Approaches:

1. Brute-force:
   - Compare each element with all other elements in the array.
   - If a match is found, return the index of the first occurrence.
   - Time Complexity: O(n^2)

2. Optimized Approach (Using Hash Map):
   - Use an unordered map to store the count of each element in the array.
   - Traverse the array again to find the first element with count > 1.
   - This ensures the smallest index of the repeating element is returned.
   - Time Complexity: O(n)
*/

#include <iostream>
#include <unordered_map>
using namespace std;


// Brute-force approach: Time Complexity - O(n^2)
int findFirstRepeatingBruteForce(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[i] == arr[j]) {
                return i; 
            }
        }
    }
    return -1;
}

// Optimized approach using a hash map: Time Complexity - O(n)
int findFirstRepeatingOptimized(int arr[], int n) {
    unordered_map<int, int> count; 
    for (int i = 0; i < n; ++i) {
        count[arr[i]]++;
    }
    for (int i = 0; i < n; ++i) {
        if (count[arr[i]] > 1) {
            return i;
        }
    }
    return -1; 
}

int main() {
    // Input array
    int arr[] = {1, 5, 3, 4, 3, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Brute-force solution
    int result1 = findFirstRepeatingBruteForce(arr, n);
    cout << "Index of first repeating element (Brute Force): " << result1 << endl;

    // Optimized solution
    int result2 = findFirstRepeatingOptimized(arr, n);
    cout << "Index of first repeating element (Optimized): " << result2 << endl;

    return 0;
}
