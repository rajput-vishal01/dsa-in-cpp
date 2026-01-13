// gfg : 0-1 knapsack problem
class Solution {
  public:
  /*
    int solve( vector<int> &val, vector<int> &wt, int capacity, int index) {
        //base case
        if(index==0){
            if(wt[index]<=capacity) return val[index];
            else return 0;
        }
       
       
        int include=0;
        if(wt[index]<= capacity){
            include=val[index]+solve(val,wt,capacity - wt[index],index-1);
        }
        int exclude=solve(val,wt,capacity,index-1);
        return max(include,exclude);
    }
   

    //using DP__Memoisation
    int solve( vector<int> &val, vector<int> &wt, int capacity, int index,vector<vector<int>>&dp) {
        //base case
        if(index==0){
            if(wt[index]<=capacity) return val[index];
            else return 0;
        }
       
        if( dp[index][capacity] != -1) return  dp[index][capacity];
       
        int include=0;
        if(wt[index]<= capacity){
            include=val[index]+solve(val,wt,capacity - wt[index],index-1,dp);
        }
        int exclude=solve(val,wt,capacity,index-1,dp);
       
        dp[index][capacity] = max(include,exclude);
        return dp[index][capacity];
    }

    //Using Tabulation
    int solve(vector<int> &val, vector<int> &wt, int capacity) {
        int n = val.size();  
        vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));  

        for (int w=wt[0]; w<=capacity;w++) {
            dp[0][w] = val[0];
        }

        for (int index = 1; index < n; index++) {
            for (int weight=0; weight<=capacity;weight++) {
                int include=0;
                if (wt[index]<=weight) {
                    include=val[index]+dp[index-1][weight-wt[index]];
                }
                int exclude=dp[index-1][weight];
                dp[index][weight] = max(include,exclude);
            }
        }
        return dp[n-1][capacity];
    }
*/
    //Using Tabulation + Space Optimization--Only 2 arrays needed
    int solve(vector<int> &val, vector<int> &wt, int capacity) {
        int n = val.size();  
        vector<int>prev(capacity+1,0);
        vector<int>curr(capacity+1,0);

        for (int w=wt[0]; w<=capacity;w++) {
            prev[w] = val[0];
        }

        for (int index=1;index<n;index++) {
            for (int weight=0; weight<=capacity;weight++) {
                int include=0;
                if (wt[index]<=weight) {
                    include=val[index]+prev[weight-wt[index]];
                }
                int exclude=prev[weight];
                curr[weight] = max(include,exclude);
               
            }
            //shifting
            prev=curr;
        }
        return prev[capacity];
    }
   
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
       
        int capacity = W;
        int n = val.size();
        int index = n-1;
        // return solve(val,wt,capacity,index);
       
        // vector<vector<int>>dp(n,vector<int>(W+1,-1));
        // return solve(val,wt,capacity,index,dp);
       
        return solve(val, wt, capacity);
       
    }
};
