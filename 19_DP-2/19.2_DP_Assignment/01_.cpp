/* Leetcode 279. Perfect Squares */

class Solution {
public:
    int solve(int n) {
        // base case
        if (n == 0) return 1; 
        if (n < 0) return 0;

        int ans = INT_MAX;
        int i = 1;

        while (i * i <= n) {
            int perfectSquare = i * i;
            int numberOfPerfectSquare = 1 + solve(n - perfectSquare);
            ans = min(ans, numberOfPerfectSquare);
            i++;
        }

        return ans;
    }

    int solveMemo(int n, vector<int>& dp) {
        // base case
        if (n == 0) return 0; 
        if (n < 0) return INT_MAX;

        if (dp[n] != -1) return dp[n];

        int ans = INT_MAX;
        int i = 1;
       
        while (i * i <= n) {
            int perfectSquare = i * i;
            int numberOfPerfectSquare = 1 + solveMemo(n - perfectSquare, dp);
            ans = min(ans, numberOfPerfectSquare);
            i++;
        }

        dp[n] = ans;
        return dp[n];
    }

    int solveTabulation(int n) {
        vector<int> dp(n + 1, INT_MAX);

        // base case
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            int start = 1;

            while (start * start <= i) {
                int perfectSquare = start * start;
                dp[i] = min(dp[i], 1 + dp[i - perfectSquare]);
                start++;
            }
        }

        return dp[n];
    }

    int numSquares(int n) {
        // return solve(n)-1;

        // vector<int>dp(n+1,-1);
        // return solveMemo(n,dp);

        return solveTabulation(n);
    }
};
