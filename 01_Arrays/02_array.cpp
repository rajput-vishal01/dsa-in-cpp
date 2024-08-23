#include<iostream>
using namespace std;

void swapPairs(int arr[], int size) {
    for(int i = 0; i < size - 1; i += 2) { 
        int temp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = temp;
    }
    cout << "The array elements are: ";
    for(int i = 0; i < size; i++) {
        cout << " " << arr[i];
    }
    cout << endl;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60};
    int size = 6;

    swapPairs(arr, size);

    return 0;
}
