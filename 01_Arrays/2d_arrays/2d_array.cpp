#include <iostream>
#include <vector>

using namespace std;
pair<int, int> SearchElement(const vector<vector<int>>& arr, int rowSize, int colSize, int target) {
    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < colSize; j++) {
            if (arr[i][j] == target) {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

int main() {
    vector<vector<int>> arr(3, vector<int>(4));

    int rowSize = arr.size();
    int colSize = arr[0].size();

    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < colSize; j++) {
            cout << "Enter the element of index " << i << "," << j << " :- ";
            cin >> arr[i][j];
        }
    }

    cout << "Printing 2D array" << endl;
    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < colSize; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    int target;
    cout << "Enter the element you want to search: ";
    cin >> target;

    pair<int, int> result = SearchElement(arr, rowSize, colSize, target);

    // Output the result
    if (result.first != -1) {
        cout << "Element found at index: (" << result.first << ", " << result.second << ")" << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}
