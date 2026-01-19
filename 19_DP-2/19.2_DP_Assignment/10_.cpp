// leetcode 1140 : 1140. Stone Game II

class Solution {
public:
    
    int solve(vector<int>& piles, int i, int M, bool isAliceTurn) {
        if (i >= piles.size()) return 0;

        int ans;
        if (isAliceTurn) ans = INT_MIN;
        else ans = INT_MAX;

        int total = 0;

        for (int X = 1; X <= 2 * M && i + X <= piles.size(); X++) {
            total += piles[i + X - 1];

            if (isAliceTurn) {
                // Alice wants to maximize her stones
                ans = max(ans,
                          total + solve(piles, i + X, max(M, X), false));
            } else {
                // Bob wants to minimize Alice's stones
                ans = min(ans,
                          solve(piles, i + X, max(M, X), true));
            }
        }

        return ans;
    }

    int solveTD(vector<int>& piles, int i, int M, bool isAliceTurn, 
                vector<vector<vector<int>>>& dp, int n) {
        if (i >= n) return 0;

        int turn = isAliceTurn ? 1 : 0;
        if (dp[i][M][turn] != -1) return dp[i][M][turn];

        int ans = isAliceTurn ? INT_MIN : INT_MAX;
        int total = 0;

        for (int X = 1; X <= 2 * M && i + X <= n; X++) {
            total += piles[i + X - 1];

            if (isAliceTurn) {
                ans = max(ans,
                          total + solveTD(piles, i + X, max(M, X), false, dp, n));
            } else {
                ans = min(ans,
                          solveTD(piles, i + X, max(M, X), true, dp, n));
            }
        }

        return dp[i][M][turn] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        // return solve(piles, 0, 1, true);

        int n = piles.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n + 1, vector<int>(2, -1)));
        return solveTD(piles, 0, 1, true, dp, n);
    }
};