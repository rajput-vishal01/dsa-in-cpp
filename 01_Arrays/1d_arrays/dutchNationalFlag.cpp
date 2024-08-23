#include <iostream>
#include <algorithm>
using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void method01(int arr[], int n) {
    int oneCount = 0;
    int zeroCount = 0;
    int twoCount = 0; // Just for the logic there is no need to create twoCount Variable

    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            zeroCount++;
        } 
        else if (arr[i] == 1) {
            oneCount++;
        }
        else {
            twoCount++; // Just for the logic there is no need to create twoCount Variable
        }
    }

    fill(arr, arr + zeroCount, 0);
    fill(arr + zeroCount, arr + zeroCount + oneCount, 1);
    fill(arr + zeroCount + oneCount, arr + n, 2);
}

int main() {
    int arr[] = {0, 1, 0, 1, 0, 0, 2, 0, 2, 2};
    int size = 10;

    method01(arr, size);
    printArray(arr, size);

    return 0;
}
