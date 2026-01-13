/*
GFG :: Painting the Fence
*/
class Solution {
  public:
  
  /*
    long long solve(int n,int k){
        //base cases
        //same color:
        if(n==1) return k;
        
        //different color:
        if(n==2) return (k+k*(k-1));
        
        int ans=(k-1) * (solve(n-1,k)+solve(n-2,k));
        return ans;
    }

    //solve using memoisation
    long long solve(int n,int k,vector<int>&dp){
        //base cases
        //same color:
        if(n==1) return k;
        
        //different color:
        if(n==2) return (k+k*(k-1));
        
        if(dp[n]!=-1) return dp[n];
        
        dp[n]=(k-1) * (solve(n-1,k,dp)+solve(n-2,k,dp));
        return dp[n];
    }
    

    //solve using tabulation
    long long solve(int n,int k){
        vector<int>dp(n+1,-1);
        
        dp[1]=k;
        dp[2]=(k+k*(k-1));
        
        for(int i=3;i<=n;i++){
            long long ans=((k-1)*((dp[i-1]+ dp[i-2])));
            dp[i] = ans;
        }
        return dp[n];
        
    }
*/  
    //Space  optimised approch
    long long solve(int n, long long k ) {
        long long prev2 = k;
        if(n==1)  return prev2;

        long long prev1 =  (k + k*(k-1));
        
        if(n==2)   return prev1; 
        
        for(int i=3; i<=n; i++) {
            long long curr =((k-1)*((prev1 + prev2)));
            //shifting
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
    
    
    int countWays(int n, int k) {
        // return solve(n,k);
        // vector<int>dp(n+1,-1);
        // return solve(n,k,dp);
        
        return solve(n,k);
    }
};