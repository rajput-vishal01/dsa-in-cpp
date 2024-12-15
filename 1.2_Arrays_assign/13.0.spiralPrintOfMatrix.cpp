#include <iostream>
#include <vector>
using namespace std;

void spiralPrint(vector<vector<int>> &matrix) {
    int rows = matrix.size();     
    int cols = matrix[0].size();  

  
    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;

    // Traverse the matrix in spiral order
    while (top <= bottom && left <= right) {
        // Traverse from left to right along the top row
        for (int col = left; col <= right; ++col) {
            cout << matrix[top][col] << " ";
        }
        top++; // Move down the top boundary

        // Traverse from top to bottom along the right column
        for (int row = top; row <= bottom; ++row) {
            cout << matrix[row][right] << " ";
        }
        right--; // Move left the right boundary

        // Traverse from right to left along the bottom row
        if (top <= bottom) {
            for (int col = right; col >= left; --col) {
                cout << matrix[bottom][col] << " ";
            }
            bottom--; // Move up the bottom boundary
        }

        // Traverse from bottom to top along the left column
        if (left <= right) {
            for (int row = bottom; row >= top; --row) {
                cout << matrix[row][left] << " ";
            }
            left++; // Move right the left boundary
        }
    }

    cout << endl;
}

int main() {
    
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };    
    cout << "Spiral Print of the Matrix: ";
    spiralPrint(matrix);
    return 0;
}
