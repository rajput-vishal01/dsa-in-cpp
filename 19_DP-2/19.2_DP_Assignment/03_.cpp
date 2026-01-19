// leetcode 712 : Minimum ASCII Delete Sum for Two Strings

class Solution {
public:

    int solve(string s1, string s2,int i,int j) {

        int cost = 0;
        
        if(i==s1.size() || j==s2.size()){
            for(int x=i;x<=s1.size()-1;x++) cost += s1[x];
            for(int y=j;y<=s2.size()-1;y++) cost += s2[y];
        }else if(s1[i]==s2[j]){
            cost=solve(s1,s2,i+1,j+1);
        }else{
            int cost1 = s1[i] + solve(s1,s2,i+1,j);
            int cost2 = s2[j] + solve(s1,s2,i,j+1);
            cost = min(cost1,cost2);
        }
        return cost;
    }

    int solveTD(string s1, string s2,int i,int j, vector<vector<int>>&dp) {

        int cost = 0;
        
        if(dp[i][j]!=-1) return dp[i][j];

        if(i==s1.size() || j==s2.size()){
            dp[i][j] = 0; // as -1 init vector
            for(int x=i;x<=s1.size()-1;x++) dp[i][j] += s1[x];
            for(int y=j;y<=s2.size()-1;y++) dp[i][j] += s2[y];
        }else if(s1[i]==s2[j]){
            dp[i][j]=solveTD(s1,s2,i+1,j+1,dp);
        }else{
            int cost1 = s1[i] + solveTD(s1,s2,i+1,j,dp);
            int cost2 = s2[j] + solveTD(s1,s2,i,j+1,dp);
            dp[i][j] = min(cost1,cost2);
        }
        return dp[i][j];
    }

    int solveBU(string s1, string s2,int i,int j, vector<vector<int>>&dp) {
        int n = s1.size();
        int m = s2.size();

        // Initialize dp table with 0
        for (int i = 0; i <= n; i++) dp[i][m] = 0;
        for (int j = 0; j <= m; j++) dp[n][j] = 0;

        // Base case: when one string is exhausted
        for (int i = n - 1; i >= 0; i--) {
            dp[i][m] = s1[i] + dp[i + 1][m];
        }
        for (int j = m - 1; j >= 0; j--) {
            dp[n][j] = s2[j] + dp[n][j + 1];
        }

        // Fill table bottom-up
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (s1[i] == s2[j]) {
                    dp[i][j] = dp[i + 1][j + 1];
                } else {
                    int cost1 = s1[i] + dp[i + 1][j];
                    int cost2 = s2[j] + dp[i][j + 1];
                    dp[i][j] = min(cost1, cost2);
                }
            }
        }
        return dp[0][0];
    }

    int minimumDeleteSum(string s1, string s2) {
        // return solve(s1,s2,0,0);
        
        vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,-1));
        // return solveTD(s1,s2,0,0,dp);
        return solveBU(s1,s2,0,0,dp);
        
    }
};