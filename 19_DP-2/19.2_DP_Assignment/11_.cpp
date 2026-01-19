// leetcode 1406. Stone Game III

class Solution {
public:
    int solve(vector<int>& sv, int i) {
        if (i == sv.size()) return 0;

        int ans = INT_MIN;
        int total = 0;

        for (int X = 1; X <= 3; X++) {
            if (i + X - 1 >= sv.size()) break;

            total += sv[i + X - 1];
            ans = max(ans, total - solve(sv, i + X));
        }
        return ans;
    }

    int solveTD(vector<int>& sv, int i, vector<int>& dp) {
        if (i == sv.size()) return 0;

        if (dp[i] != INT_MIN) return dp[i];

        int ans = INT_MIN;
        int total = 0;

        for (int X = 1; X <= 3; X++) {
            if (i + X - 1 >= sv.size()) break;

            total += sv[i + X - 1];
            ans = max(ans, total - solveTD(sv, i + X, dp));
        }
        return dp[i] = ans;
    } 

    string stoneGameIII(vector<int>& stoneValue) {
        // int ans = solve(stoneValue, 0); //ans = alice score - bob score

        vector<int> dp(stoneValue.size(), INT_MIN);
        int ans = solveTD(stoneValue, 0, dp); //ans = alice score - bob score

        if (ans > 0) return "Alice";
        if (ans < 0) return "Bob";
        return "Tie";
    }
};
