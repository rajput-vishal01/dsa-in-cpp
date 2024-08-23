#include<iostream>
using namespace std;

int findElement(int arr[], int size, int elemt) {
    for(int i = 0; i < size; i++) {
        if(elemt == arr[i]) {
            cout << "Element found" << endl;
            return i; // Return index if element is found
        }
    }
    cout << "Element not in the array" << endl;
    return -1; // Return -1 if element is not found
}

int main() {
    int arr[10];
    int size;
    int elemt;

    cout << "Enter the size of the array (max 10): " << endl;
    cin >> size;

    if (size > 10 || size <= 0) {
        cout << "Invalid size" << endl;
        return 1;
    }

    for(int i = 0; i < size; i++) {
        cout << "Enter the value of array element " << i+1 << ": ";
        cin >> arr[i];
    }

    cout << "The array elements are: ";
    for(int i = 0; i < size; i++) {
        cout << " " << arr[i];
    }
    cout << endl;

    cout << "Enter the element to look for: ";
    cin >> elemt;

    findElement(arr, size, elemt);

    return 0;
}
