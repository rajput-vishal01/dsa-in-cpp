// leetcode 115. 115. Distinct Subsequences

class Solution {
public:
    int solve(string &s,string &t,int i,int j){
        if(j==t.size()) return 1; //matched
        if(i==s.size()) return 0; //not matched
        int ans=0;
        if(s[i]==t[j]) ans+=solve(s,t,i+1,j+1); //pick
        ans+=solve(s,t,i+1,j);//not pick
        return ans;
    }

    int solveTD(string &s,string &t,int i,int j,vector<vector<int>>&dp){
        if(j==t.size()) return 1; //matched
        if(i==s.size()) return 0; //not matched
        
        if(dp[i][j]!=-1) return dp[i][j];

        int ans=0;
        if(s[i]==t[j]){
            ans+=solveTD(s,t,i+1,j+1,dp);//pick
             dp[i][j]=ans;
        } 
        ans+=solveTD(s,t,i+1,j,dp);//not pick
        dp[i][j]=ans;
        return dp[i][j];
    }

    int solveBU(string &s, string &t) {
    int n = s.size();
    int m = t.size();

    vector<vector<unsigned long long>>dp(n+1,vector<unsigned long long>(m+1,0));

    // base case: empty t->1 way
    for (int i = 0; i <= n; i++)
        dp[i][m] = 1;

    for (int i=n-1;i>=0;i--){
        for (int j=m-1;j>=0;j--) {
            if(s[i] == t[j])
                dp[i][j] = dp[i+1][j+1]+dp[i+1][j];// pick + skip
            else
                dp[i][j] = dp[i+1][j];// only skip
        }
    }
    return dp[0][0];
}


    int numDistinct(string s, string t) {
        // return solve(s,t,0,0);

        // vector<vector<int>>dp(s.size()+1,vector<int>(t.size(),0));
        // return solveTD(s,t,0,0,dp);

       return solveBU(s,t);


    }
};