/*
This program uses binary search to find the first occurrence, last occurrence, 
and total occurrences of a given element in a sorted array. It calculates the 
total occurrences using the formula: lastIndex - firstIndex + 1.
*/


#include <iostream>
using namespace std;

void firstOccurrence(int arr[], int n, int elem, int &ansFirstIndex) {
    int start = 0;
    int end = n - 1;
    int mid;

    while (start <= end) {
        mid = start + (end - start) / 2;

        if (arr[mid] == elem) {
            ansFirstIndex = mid; 
            end = mid - 1;  // Search in the left part for the first occurrence
        } else if (arr[mid] > elem) {
            end = mid - 1; 
        } else {
            start = mid + 1; 
        }
    }
}

void lastOccurrence(int arr[], int n, int elem, int &ansLastIndex) {
    int start = 0;
    int end = n - 1;
    int mid;

    while (start <= end) {
        mid = start + (end - start) / 2;

        if (arr[mid] == elem) {
            ansLastIndex = mid; 
            start = mid + 1;  // Search in the right part for the last occurrence
        } else if (arr[mid] > elem) {
            end = mid - 1; 
        } else {
            start = mid + 1; 
        }
    }
}

int main() {
    int arr[11] = {0, 10, 10, 20, 20, 20, 20, 30, 30, 40, 50};
    int n = 11;
    int elem = 20;
    int ansFirstIndex = -1;
    int ansLastIndex = -1;

   
    firstOccurrence(arr, n, elem, ansFirstIndex);
    lastOccurrence(arr, n, elem, ansLastIndex);

    // Calculate total occurrences
    int totalOccurrences = 0;
    if (ansFirstIndex != -1 && ansLastIndex != -1) {
        totalOccurrences = ansLastIndex - ansFirstIndex + 1;
    }

    cout << "First occurrence index: " << ansFirstIndex << endl;
    cout << "Last occurrence index: " << ansLastIndex << endl;
    cout << "Total occurrences: " << totalOccurrences << endl;

    return 0;
}
