#include<iostream>
using namespace std;

void ExtremePrint(int arr[], int size) {
    for(int i = 0; i < size / 2; i++) {
        cout << arr[i] << " " << arr[size - 1 - i] << " ";
    }
    if (size % 2 != 0) {
        cout << arr[size / 2]; // Print the middle element if the array size is odd
    }
    cout << endl;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60};
    int size =6;

    ExtremePrint(arr, size);

    return 0;
}
