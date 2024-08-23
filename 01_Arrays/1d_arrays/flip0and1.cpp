#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;  
}

void flipArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            arr[i] = 1;
        } else {
            arr[i] = 0;
        }
    }
}

int main() {
    int arr[] = {0, 0, 1, 0, 1, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    flipArray(arr, size);
    printArray(arr, size);

    return 0;
}
