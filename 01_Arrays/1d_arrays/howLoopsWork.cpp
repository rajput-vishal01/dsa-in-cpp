#include<iostream>
using namespace std;

// Loop 1: All Pairs
void allPairs(int arr[], int n) {
    cout << "All Pairs:" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << "(" << arr[i] << "," << arr[j] << ") ";
        }
        cout << endl;
    }
    cout << endl;
}

// Loop 2: Upper Triangle
void upperTrianglePairs(int arr[], int n) {
    cout << "Upper Triangle Pairs:" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            cout << "(" << arr[i] << "," << arr[j] << ") ";
        }
        cout << endl;
    }
    cout << endl;
}

// Loop 3: Random Pair (with error fixed)
void randomPairs(int arr[], int n) {
    cout << "Random Pairs (Fixed):" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << "(" << arr[i] << "," << arr[j] << ") ";
        }
        cout << endl;
    }
    cout << endl;
}

// Loop 4: Reverse j Printing
void reverseJPairs(int arr[], int n) {
    cout << "Reverse j Pairs:" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = n-1; j >= 0; j--) {
            cout << "(" << arr[i] << "," << arr[j] << ") ";
        }
        cout << endl;
    }
    cout << endl;
}

// Loop 5: Lower Triangle
void lowerTrianglePairs(int arr[], int n) {
    cout << "Lower Triangle Pairs:" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = n-1; j > i; j--) {
            cout << "(" << arr[i] << "," << arr[j] << ") ";
        }
        cout << endl;
    }
    cout << endl;
}

// Loop 6: Pairs with i+1
void pairsWithIPlusOne(int arr[], int n) {
    cout << "Pairs with i+1:" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            cout << "(" << arr[i] << "," << arr[j] << ") ";
        }
        cout << endl;
    }
    cout << endl;
}

// Additional Loop 1: Diagonal Elements Only
void diagonalPairs(int arr[], int n) {
    cout << "Diagonal Pairs:" << endl;
    for(int i = 0; i < n; i++) {
        cout << "(" << arr[i] << "," << arr[i] << ") ";
    }
    cout << endl << endl;
}

// Additional Loop 2: Pairs with Fixed First Element
void fixedFirstElementPairs(int arr[], int n, int fixedIndex) {
    cout << "Pairs with Fixed First Element (" << arr[fixedIndex] << "):" << endl;
    for(int j = 0; j < n; j++) {
        cout << "(" << arr[fixedIndex] << "," << arr[j] << ") ";
    }
    cout << endl << endl;
}

// Additional Loop 3: Pairs with Fixed Second Element
void fixedSecondElementPairs(int arr[], int n, int fixedIndex) {
    cout << "Pairs with Fixed Second Element (" << arr[fixedIndex] << "):" << endl;
    for(int i = 0; i < n; i++) {
        cout << "(" << arr[i] << "," << arr[fixedIndex] << ") ";
    }
    cout << endl << endl;
}

// Additional Loop 4: Pairs with Step Size
void stepSizePairs(int arr[], int n, int step) {
    cout << "Pairs with Step Size (" << step << "):" << endl;
    for(int i = 0; i < n; i += step) {
        for(int j = 0; j < n; j += step) {
            cout << "(" << arr[i] << "," << arr[j] << ") ";
        }
        cout << endl;
    }
    cout << endl;
}

// Additional Loop 5: Pairs with Wrap Around
void wrapAroundPairs(int arr[], int n) {
    cout << "Pairs with Wrap Around:" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int wrapIndex = (i + j) % n;
            cout << "(" << arr[i] << "," << arr[wrapIndex] << ") ";
        }
        cout << endl;
    }
    cout << endl;
}

// Additional Loop 6: Pairs with Increasing Difference
void increasingDifferencePairs(int arr[], int n) {
    cout << "Pairs with Increasing Difference:" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            cout << "(" << arr[i] << "," << arr[j] << ") ";
        }
        cout << endl;
    }
    cout << endl;
}

// Additional Loop 7: Pairs with Decreasing Difference
void decreasingDifferencePairs(int arr[], int n) {
    cout << "Pairs with Decreasing Difference:" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            cout << "(" << arr[i] << "," << arr[j] << ") ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60};
    int size = 6;

    allPairs(arr, size);
    upperTrianglePairs(arr, size);
    randomPairs(arr, size);
    reverseJPairs(arr, size);
    lowerTrianglePairs(arr, size);
    pairsWithIPlusOne(arr, size);
    diagonalPairs(arr, size);
    fixedFirstElementPairs(arr, size, 2); // Example with fixed element at index 2
    fixedSecondElementPairs(arr, size, 3); // Example with fixed element at index 3
    stepSizePairs(arr, size, 2); // Example with step size 2
    wrapAroundPairs(arr, size);
    increasingDifferencePairs(arr, size);
    decreasingDifferencePairs(arr, size);

    return 0;
}
