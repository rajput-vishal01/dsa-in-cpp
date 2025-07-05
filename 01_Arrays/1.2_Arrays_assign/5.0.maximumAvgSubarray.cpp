// You are given an integer array nums consisting of n elements, and an integer k.
// Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value.
#include <iostream>
#include <climits>
#include <algorithm>

using namespace std; 

double findSubArray(int arr[], int n, int k) {
    int sum = INT_MIN;
    for (int i = 0; i < k; i++) {
        sum += arr[i];
    }
    int maxSum = INT_MIN;

    for (int i = k; i < n; i++) {
        sum += arr[i] - arr[i - k];
        maxSum = max(maxSum, sum);
    }

    return (double)maxSum / k;
}

int main() {
    int arr[6] = {1, 12, -5, -6, 50, 3};
    int n = 6;
    int k = 4;

    double maxAvg = findSubArray(arr, n, k);

    cout << "Maximum average of subarray of length " << k << " is: " << maxAvg << endl;

    return 0;
}
