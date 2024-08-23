#include<iostream>
using namespace std;

// void sortZeroAndOne(int arr[], int size) {
//     int zeroCount = 0;
//     for(int i = 0; i < size; i++) {
//         if(arr[i] == 0) {
//             zeroCount++;
//         }
//     }
//     fill(arr, arr + zeroCount, 0);
//     fill(arr + zeroCount, arr + size, 1);
// }

// // void printArray(int arr[], int size) {
//     for(int i = 0; i < size; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }

// // void printPair(int arr[],int n){
//     for (int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             cout<<arr[i]<<","<<arr[j]<<" ";
//         }
//         cout<<endl;
//     }
// }

// void twoSome(int arr[],int n){
//     for (int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             cout<<arr[i]+arr[j]<<" ";
//         }
//         cout<<endl;
//     }
// }

// void threeSomeTarget(int arr[],int n,int target) {
//     for(int i = 0; i < n; i++) {
//         for(int j = 0; j < n; j++) {
//             for(int k = 0; k < n; k++) {
//                 if(arr[i] + arr[j] + arr[k] == target) {
//                     cout << arr[i] << ", " << arr[j] << ", " << arr[k] << endl;
//                 }
//             }
//         }
//         cout << endl;
//     }
// }

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = 4;
    int target = 80;

    // threeSomeTarget(arr, n, target);
    // twoSome(arr,n);
    // printPair(arr,n);
    // cout << "Original array: ";
    // printArray(arr, size);
    // sortZeroAndOne(arr, size);
    // cout << "Sorted array: ";
    // printArray(arr, size);

    return 0;
}
