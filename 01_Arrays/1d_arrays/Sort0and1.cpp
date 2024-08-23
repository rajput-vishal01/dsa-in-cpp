#include <iostream>
#include<algorithm>
using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// void method01(int arr[], int n) {
//     int oneCount = 0;
//     int zeroCount = 0;

//     for (int i = 0; i < n; i++) {
//         if (arr[i] == 0) {
//             zeroCount++;
//         } else {
//             oneCount++;
//         }
//     }

//     fill(arr, arr + zeroCount, 0);
//     fill(arr + zeroCount, arr + n, 1);
// }

int main() {
    int arr[] = {0, 1, 0, 1, 0, 0};
    int size = 6;

    // method01(arr, size);
    // sort(arr,arr+size);
    printArray(arr, size);

    return 0;
}
