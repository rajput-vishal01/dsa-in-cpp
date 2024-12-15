//assumption : NO need to maintain the order of numbers
//Dutch National Flag Algorithm (2 pointers approch)
#include <iostream> 
using namespace std; 

int sortTheNumbers(int arr[], int n) {
    int low = 0;
    int high = n - 1;

    // Two-pointer approach
    while (low <= high) {
        if (arr[low] < 0) {
            // If the current number at low is already negative, move to the next
            low++;
        } else if (arr[high] >= 0) {
            // If the current number at high is already non-negative, move to the previous
            high--;
        } else {
            // Swap negative and non-negative numbers
            swap(arr[low], arr[high]);
            low++;
            high--;
        }
    }

    // Print the array
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    
    return 0;
}

int main() {
    int arr[6] = {1, 3, -1, 5, -8, -2};
    int n = 6;

    sortTheNumbers(arr, n);
    return 0; 
}
