#include <iostream>
#include <vector>
using namespace std;

void wavePrint(vector<vector<int>> &matrix) {
    int rows = matrix.size();       
    int cols = matrix[0].size();    

    for (int col = 0; col < cols; ++col) {
        if (col % 2 == 0) {
            // Traverse top to bottom for even columns
            for (int row = 0; row < rows; ++row) {
                cout << matrix[row][col] << " ";
            }
        } else {
            // Traverse bottom to top for odd columns
            for (int row = rows - 1; row >= 0; --row) {
                cout << matrix[row][col] << " ";
            }
        }
    }
    cout << endl;
}

int main() {

    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Wave Print of the Matrix: ";
    wavePrint(matrix);

    return 0;
}
