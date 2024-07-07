#include<iostream>
using namespace std;

// //Row_traversal
//  void print2dArray( int arr[][4], int rowSize, int colSize){
//     for (int i = 0; i < rowSize; i++)
//     {
//         for (int j = 0; j < colSize; j++)
//         {
//             cout<<arr[i][j]<<","<<" ";
//         }
//         cout<<endl;
//     }
    
//  }

// //Col_traversal
//  void colPrint2dArray( int arr[][4], int rowSize, int colSize){
//     for (int j = 0; j < colSize; j++)
//     {
//         for (int i = 0; i < rowSize; i++)
//         {
//             cout<<arr[i][j]<<","<<" ";
//         }
//         cout<<endl;
//     }
    
//  }

// Find target element in a 2D array
void findTarget(int arr[][4], int rowSize, int colSize, int target) {
    bool found = false; 
    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < colSize; j++) {
            if (arr[i][j] == target) {
                cout << "Element present at the index of " << i << "," << j << endl;
                found = true; 
            }
        }
    }
    
    if (!found) {
        cout << "Element is absent" << endl;
    }
}

int main() {
    int arr[4][4] = {
        {10, 20, 30, 40},
        {10, 20, 30, 40},
        {10, 20, 30, 40},
        {10, 20, 30, 40}
    };

    int rowSize = 4;
    int colSize = 4;

    int target = 100;

    findTarget(arr, rowSize, colSize, target);

    // print2dArray(arr, rowSize, colSize);
    // cout << endl;
    // colPrint2dArray(arr, rowSize, colSize);

    return 0;
}
