#include <iostream>
#include <algorithm>

using namespace std;

// T.C->O(n^2)
// int findkeyPair(int arr[], int n, int elem) {
//   for (int i = 0; i < n; i++) { // Fixed the loop condition
//     for (int j = i + 1; j < n; j++) { // Avoid duplicate pairs by starting j from i + 1
//       if (arr[i] + arr[j] == elem) {
//         cout << "Pairs are: " << arr[i] << " " << arr[j] << endl;
//       }
//     }
//   }
// }

// T.C->O(n)
void findkeyPair(int arr[], int n, int elem) {
    sort(arr, arr + n); // Sort the array

    // cout << "Sorted Array: ";
    // for (int i = 0; i < n; i++) {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    int low = 0;
    int high = n - 1;

    while (low < high) { // Fixed condition
        int currentSum = arr[low] + arr[high];
        if (currentSum == elem) {
            cout << "Pairs are: " << arr[low] << " and " << arr[high] << endl;
            return; // Exit after finding one pair (optional, depending on requirements)
        }
        // If currentSum is greater than the target, decrement high
        else if (currentSum > elem) {
            high--;
        }
        // If currentSum is less than the target, increment low
        else {
            low++;
        }
    }

    cout << "No pairs found!" << endl; // If no pair is found
}

int main() {
    int arr[5] = {0, 3, 2, 4, 1};
    int n = 5;
    int x = 7;

    findkeyPair(arr, n, x);

    return 0;
}
