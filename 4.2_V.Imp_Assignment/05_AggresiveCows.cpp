#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Problem Explanation:
- You are given `stalls[]` containing unique positions of stalls and an integer `k` (number of cows).
- The task is to assign stalls to `k` cows such that the minimum distance between any two cows is maximized.

Approach:
1. Sort the `stalls[]` array to process positions in increasing order.
2. Use binary search to find the maximum minimum distance (`mid`) that satisfies the placement of `k` cows.
3. A helper function (`canPlaceCows`) checks if it's possible to place the cows with at least `mid` distance apart.
4. Adjust the binary search range (`low` and `high`) based on the feasibility of `mid`.
5. The final result is the largest value of `mid` where placement is feasible.
*/

bool canPlaceCows(const vector<int>& stalls, int k, int minDist) {
    int count = 1; // Place the first cow in the first stall
    int lastPosition = stalls[0]; // Position of the last placed cow

    for (int i = 1; i < stalls.size(); i++) {
        // Check if the current stall is at least `minDist` away from the last placed cow
        if (stalls[i] - lastPosition >= minDist) {
            count++; // Place another cow
            lastPosition = stalls[i]; // Update the last placed cow's position
            if (count == k) return true; // If all cows are placed, return true
        }
    }

    return false; // Not all cows could be placed
}

int aggressiveCows(vector<int>& stalls, int k) {
    // Step 1: Sort the stall positions
    sort(stalls.begin(), stalls.end());

    // Step 2: Initialize binary search range
    int low = 1; // Minimum possible distance
    int high = stalls.back() - stalls.front(); // Maximum possible distance
    int result = 0; // To store the maximum minimum distance

    // Step 3: Perform binary search
    while (low <= high) {
        int mid = low + (high - low) / 2; // Calculate the middle distance

        if (canPlaceCows(stalls, k, mid)) {
            result = mid; // Update the result as mid is feasible
            low = mid + 1; // Try for a larger distance
        } else {
            high = mid - 1; // Try for a smaller distance
        }
    }

    return result; // Return the largest minimum distance
}

int main() {
    // Example input
    vector<int> stalls1 = {1, 2, 4, 8, 9};
    int k1 = 3;
    cout << "Example 1: " << aggressiveCows(stalls1, k1) << endl; // Output: 3

    vector<int> stalls2 = {10, 1, 2, 7, 5};
    int k2 = 3;
    cout << "Example 2: " << aggressiveCows(stalls2, k2) << endl; // Output: 4

    vector<int> stalls3 = {2, 12, 11, 3, 26, 7};
    int k3 = 5;
    cout << "Example 3: " << aggressiveCows(stalls3, k3) << endl; // Output: 1

    return 0;
}
