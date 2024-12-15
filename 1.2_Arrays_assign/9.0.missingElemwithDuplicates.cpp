//find missing elements from the duplicate of an array.
//constrain : N - size of array,a[i] belongs to [1,N]

/*
ways:
1.positioning method : as previous.
 */

#include <iostream> 
using namespace std;

void findMissingElements(int arr[], int n) {
    // Move each element to its correct position (arr[i] = i + 1)
    for (int i = 0; i < n; ++i) {
        while (arr[i] > 0 && arr[i] <= n && arr[i] != arr[arr[i] - 1]) {
            swap(arr[i], arr[arr[i] - 1]);
        }
    }

    // Now, check for the missing elements
    for (int i = 0; i < n; ++i) {
        if (arr[i] != i + 1) {
            cout << "Missing element: " << i + 1 << endl;
        }
    }
}

int main() {
    int arr[] = {1, 3, 5, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    findMissingElements(arr, n);
    
    return 0; 
}
