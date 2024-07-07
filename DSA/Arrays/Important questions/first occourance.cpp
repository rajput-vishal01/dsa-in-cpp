//First and last occurance of element using binary search

#include <iostream>
using namespace std;

int firstOcc(int arr[], int n, int key) {
    int ans = -1; // Initialize ans to -1, indicating key not found
    int s = 0, e = n - 1;
    int mid = s + (e - s) / 2;

    while (s <= e) {
        if (arr[mid] == key) {
            ans = mid; // Update ans when key is found
            e = mid - 1; // Look for key in the left half to find the first occurrence
        } else if (key > arr[mid]) {
            s = mid + 1; // Move to the right half
        } else {
            e = mid - 1; // Move to the left half
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int lastOcc(int arr[], int n, int key) {
    int ans = -1; // Initialize ans to -1, indicating key not found
    int s = 0, e = n - 1;
    int mid = s + (e - s) / 2;

    while (s <= e) {
        if (arr[mid] == key) {
            ans = mid; // Update ans when key is found
            s = mid + 1; // Look for key in the right half to find the last occurrence
        } else if (key > arr[mid]) {
            s = mid + 1; // Move to the right half
        } else {
            e = mid - 1; // Move to the left half
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int main() {
    int odd[5] = {1, 2, 3, 3, 5};

    cout << "First occurrence of 3 is at index: " << firstOcc(odd, 5, 3) << endl;
    cout << "Last occurrence of 3 is at index: " << lastOcc(odd, 5, 3) << endl;

    return 0;
}
