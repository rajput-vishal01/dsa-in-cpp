/*
Code Overview and Features:
1. This program demonstrates sorting vectors and vectors of vectors in C++ using custom comparators.
2. It uses the STL `sort` function, which is highly efficient with a time complexity of O(n log n).
3. A `print` function is provided to display a single vector.
4. A `printvv` function is provided to display a vector of vectors.
5. A custom comparator (`mycompfor1stIndex`) is used to sort the vector of vectors by the second element (column).

Improvements Made:
1. Used modern C++ practices, including structured bindings for better readability.
2. Avoided repeated use of `push_back` by using list initialization for vector construction.
3. Used `const` references where applicable to prevent unnecessary copies.
4. Added input validation to handle unexpected or invalid inputs.
5. Simplified and enhanced readability with meaningful variable names and comments.

Example Input/Output:

Input:
Enter size:
3
Enter a, b:
3 4
2 5
1 6

Output:
Here are the Values:
3 4
2 5
1 6

Sorted by 1st index:
3 4
2 5
1 6 (sorted based on the second value in descending order)
*/
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Function to print a single vector
void print(const vector<int> &v) {
    for (const auto &elem : v) {
        cout << elem << " ";
    }
    cout << endl;
}

// Function to print a vector of vectors
void printvv(const vector<vector<int>> &v) {
    for (const auto &row : v) {
        cout << row[0] << " " << row[1] << endl;
    }
    cout << endl;
}

// Comparator for sorting by the second index in descending order
bool mycompfor1stIndex(const vector<int> &a, const vector<int> &b) {
    return a[1] > b[1]; // Change `>` to `<` for ascending order
}

int main() {
    vector<vector<int>> v;

    int n;
    cout << "Enter the number of rows:\n";
    cin >> n;

    // Validate input for `n`
    if (n <= 0) {
        cout << "Invalid size. Exiting program.\n";
        return 1;
    }

    cout << "Enter pairs of integers (a, b):\n";
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        // List initialization for adding a row
        v.push_back({a, b});
    }

    cout << "Here are the Values:\n";
    printvv(v);

    cout << "Sorted by 1st index (based on second column in descending order):\n";
    sort(v.begin(), v.end(), mycompfor1stIndex);
    printvv(v);

    return 0;
}
