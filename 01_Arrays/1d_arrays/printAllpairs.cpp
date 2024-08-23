#include<iostream>
using namespace std;

void pair2x2(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << "(" << arr[i] << "," << arr[j] << ") ";
        }
        cout << endl;
    }
}

void pair3x3(int arr[], int n) {
    int count = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                cout << "(" << arr[i] << "," << arr[j] << "," << arr[k] << ") ";
                count++;
            }
        }
    }
    cout << endl;
    cout << "Total count of elements: " << count << endl;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60};
    int size = 6;

    pair2x2(arr, size);
    cout << endl;
    pair3x3(arr, size);

    return 0;
}
