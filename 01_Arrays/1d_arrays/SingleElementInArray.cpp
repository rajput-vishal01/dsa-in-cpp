#include<iostream>
using namespace std;

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int singleElement(int arr[], int n) {
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans = ans ^ arr[i];
    }
    return ans;
}

int main() {
    int arr[] = {10, 10, 30, 40, 40};
    int size = 5;

    printArray(arr, size);

    int result = singleElement(arr, size);
    cout << "Single element is: " << result << endl;

    return 0;
}
