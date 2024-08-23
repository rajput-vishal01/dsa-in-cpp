#include<iostream>
using namespace std;

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void swapArray(int arr[], int n) {
    for (int i = 0; i < n / 2; i++) {
        swap(arr[i], arr[n - i - 1]);
    }
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60};
    int size = 6;

    swapArray(arr, size);
    printArray(arr, size);
    
    return 0;
}
