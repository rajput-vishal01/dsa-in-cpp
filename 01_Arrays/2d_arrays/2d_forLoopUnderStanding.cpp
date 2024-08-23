#include <iostream>
#include <vector>

using namespace std;

// Function to print 2D array row-wise
void rowWise(const vector<vector<int>>& arr, int rowSize, int colSize) {
    cout << "Printing 2D array row-wise" << endl;
    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < colSize; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to print 2D array column-wise
void colWise(const vector<vector<int>>& arr, int rowSize, int colSize) {
    cout << "Printing 2D array column-wise" << endl;
    for (int j = 0; j < colSize; j++) {
        for (int i = 0; i < rowSize; i++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to print the right diagonal (top-left to bottom-right)
void rightDiagonal(const vector<vector<int>>& arr, int size) {
    cout << "Printing the right diagonal" << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i][i] << " ";
    }
    cout << endl;
}

// Function to print the left diagonal (top-right to bottom-left)
void leftDiagonal(const vector<vector<int>>& arr, int rowSize, int colSize) {
    cout << "Printing the left diagonal" << endl;
    for (int i = 0; i < rowSize; i++) {
        cout << arr[i][colSize - i - 1] << " ";
    }
    cout << endl;
}

int main() {
    // Correct initialization of the 2D vector
    vector<vector<int>> arr = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    int rowSize = arr.size();       // Number of rows
    int colSize = arr[0].size();    // Number of columns in the first row

    // Calling the functions
    rowWise(arr, rowSize, colSize);
    colWise(arr, rowSize, colSize);
    rightDiagonal(arr, min(rowSize, colSize)); // Assuming a square matrix or rectangular matrix
    leftDiagonal(arr, rowSize, colSize);

    return 0;
}
