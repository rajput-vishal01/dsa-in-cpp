/*

2D - DP ARRAYS:

-Knapsack Problem:

2 types: 
-- 0/1 knapsack -- DP
-- Fractional -- Greedy                         


*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knapsack(int W, const vector<int>& weights, const vector<int>& values, int n) {
    // Create a DP table with dimensions (n+1) x (W+1)
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Build the table in bottom-up manner
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (weights[i - 1] <= w) {
                // Choose the maximum between including or excluding the item
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][W];
}

int main() {
    // Problem parameters: 3 items, knapsack capacity 4.
    int n = 3;
    int W = 4;
    
    // Values and weights arrays for the 3 items.
    vector<int> values = {1, 2, 3};
    vector<int> weights = {4, 5, 1};
    
    // The knapsack function returns the maximum value achievable.
    int result = knapsack(W, weights, values, n);
    cout << "Maximum value: " << result << endl;
    
    return 0;
}
