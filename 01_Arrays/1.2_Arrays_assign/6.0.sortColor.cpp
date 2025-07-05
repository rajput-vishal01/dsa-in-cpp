// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
#include <iostream> 
#include <algorithm>
using namespace std; 

/*
ways:
1.sort() //fn in algorithm library or simply sort them using any sort methods
2.count //count the number of occurrences of each value and fill the array with the number of occurrences
3.swap //inplace swap the array elements ---Here three pointer approch will be used
*/
void sortArrayUsingSort(int arr[], int n) {
    sort(arr, arr + n);
}

void sortArrayUsingCount(int arr[], int n) {
    int count0 = 0, count1 = 0, count2 = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) count0++;
        else if (arr[i] == 1) count1++;
        else if (arr[i] == 2) count2++;
    }
    for (int i = 0; i < count0; i++) arr[i] = 0;
    for (int i = count0; i < count0 + count1; i++) arr[i] = 1;
    for (int i = count0 + count1; i < n; i++) arr[i] = 2;
}

void sortArrayUsingThreePointers(int arr[], int n) {
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        } else if (arr[mid] == 1) {
            mid++;
        } else {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[10] = {0, 0, 2, 1, 2, 0, 2, 1, 1, 0};
    int n = 10;
    
    sortArrayUsingSort(arr, n);
    cout << "Sorted array using sort(): ";
    printArray(arr, n);

    int arr2[10] = {0, 0, 2, 1, 2, 0, 2, 1, 1, 0};
    sortArrayUsingCount(arr2, n);
    cout << "Sorted array using count(): ";
    printArray(arr2, n);

    int arr3[10] = {0, 0, 2, 1, 2, 0, 2, 1, 1, 0};
    sortArrayUsingThreePointers(arr3, n);
    cout << "Sorted array using three pointers: ";
    printArray(arr3, n);

    return 0;
}
