/*
Dynamic programming (DP) isn’t a data structure—it’s a method for solving problems by breaking them into simpler,
overlapping subproblems and then combining their solutions. To effectively apply DP.

Problem must have two key properties:
1. Overlapping Subproblems:
The problem can be divided into subproblems that are reused multiple times. Instead of recomputing these subproblems,
DP stores their solutions (using memoization or tabulation) to save computation.

2. Optimal Substructure:
An optimal solution to the problem can be constructed from the optimal solutions of its subproblems.
This means that if you solve each subproblem optimally, you can combine those solutions to form an overall optimal solution.

For example, computing Fibonacci numbers recursively leads to recalculating the same values repeatedly.
Using dynamic programming, you store the results of these overlapping subproblems and reuse them, which drastically improves efficiency.


DP ques problem solving approches::
1.Top down-- Recur(solve) + memoization(then, store)(least best)
  Steps:: 1. find out-> 1d/2d/3d dp ->create dp array
     //how to select array-> check the no. of parameters which are chaing during recur.
     //i.e In fibo --> only value of n changes to n-1 and n-2 so --> 1d dp arr.

          2. ans in recursive code -> store and return dp array
          3. if ans already exists in dp array.No need to process again just return ans.

2.Bottom up --Loop+ Data Struct
  Steps:: 1. Create dp arr -> find out-> 1d/2d/3d dp
          2. Analyse base cases in recur approch-> update arr based on that
          3. Check params -> reverse it -> copy paste logic
          -> why reverse -> as in top down we go n to 0,in bottom we go 0 to n so we have reverse it to get n to 0. 

--In bottom up approch we add a initial state in the array first and on the basis of that initial state we calculate results.

3.Space optimization --if possible __ find pattern and optimized (best approch)
*/

/*
Leetcode :: 509 --fibonacci-number
*/

//Recur approch vs multiple dp approch
class Solution {
  public:
       //approch 1: Only recur.
       int ReursionSoln(int n){
          //base case
          if(n==0){
              return 0;
          }
          if(n==1){
              return 1;
          }
          int ans=ReursionSoln(n-1)+ReursionSoln(n-2);
          return ans;
       }
  
       //approch 2: dp- top down approch
       int solveUsingMemo(int n,vector<int>&dp){
           //base case
          if(n==0){
              return 0;
          }
          if(n==1){
              return 1;
          }
          //step 3: basecase ke baad check if ans already exists or not
          if(dp[n] != -1){
              return dp[n];
          }
  
          //step 2: dp arr mai ans store karo and return karo
          dp[n]=solveUsingMemo(n-1,dp)+solveUsingMemo(n-2,dp);
          return dp[n];
  
       }
  
     //approch 3: dp- bottom up approch
       int solveUsingTablulation(int n){
       //step 1: create vector :
         vector<int> dp(n+1,-1);
  
      //step 2: analyse base case and update dp
        dp[0]=0;
    
      //imp::
      //err-> as in n=0 we are trying access n=1 which we should not
        if(n==0){
          return 0;
        }
        dp[1]=1;
  
        //step 3: check params and reverse it and run a loop
        //recursive -> n-> 0
        //reverse -> 0 -> n
        //i ==2 as we already know for 0->0 and for 1 its ->1(base cases)
        for(int i=2;i<=n;i++){
          // copy-paste
          // dp[n]=dp[n-1]+dp[n-2];
          // as loop is on i
  
            dp[i]=dp[i-1]+dp[i-2];
        }
        //always there will a confusion what to return i or n
        //return the same elem which made the fn call
        //Hence n
        return dp[n];
       }
  
  
     //approch 4: dp- bottom up approch+ space optimization
       int solveUsingTablulationAndOptimization(int n){
       //step 1: create vector :
       //No more need of Vector
       //    vector<int> dp(n+1,-1);
  
      //step 2: analyse base case and update dp
      //   dp[0]=0;
      int prev =0;
    
      //imp::
      //err-> as in n=0 we are trying access n=1 which we should not
        if(n==0){
          return 0;
        }
      //   dp[1]=1;
      int curr = 1;
  
        //step 3: check params and reverse it and run a loop
        //recursive -> n-> 0
        //reverse -> 0 -> n
        //i ==2 as we already know for 0->0 and for 1 its ->1(base cases)
        for(int i=2;i<=n;i++){
          int ans = curr+prev;
          prev=curr;
          curr=ans;
        }
        return curr;
       }
  
      int fib(int n) {
          //Normal approch
          // int ans=ReursionSoln(n);
          // return ans;
           
          //approch 1:
          //step 1 :Create dp array and pass in fn :
          // vector<int> dp(n+1,-1);
          // return solveUsingMemo(n,dp);
          
          //approch 2:
          // return solveUsingTablulation(n);
  
          //approch 3:
          return solveUsingTablulationAndOptimization(n);
          
      }
  };