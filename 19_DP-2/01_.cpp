/*


--DON'T 100% sure about these statements-- 

When applying space optimization in dynamic programming (DP) , the order of loops must respect the dependency order of the computed values.

Conditions:

--When there is no need to interchange the loops:
If, in the tabulation method, each element in a row depends only on previously computed elements in the same row (or each element in a column depends
 only on previously computed elements in the same column), then the loops can remain in their original order.

--When the loops need to be interchanged:
If an element in a row depends on an element from a previous column (or an element in a column depends on an element from a previous row) that might 
be overwritten during space optimization, you must interchange the loops or adjust the processing order. This ensures that all required dependency values are computed before they are used.

*/

/*

Leetcode :: 1143

*/

class Solution {
  public:
  
       int solveUsingRec(string text1, string text2, int i, int j) {
          //base case
          if(i >= text1.length()){
              return 0;
          }
          if(j >= text2.length()){
              return 0;
          }
  
          //1 case:
          int ans = 0;
          //match 
          if(text1[i] == text2[j]){
              ans = 1 + solveUsingRec(text1, text2, i+1, j+1);
          } else {
              //not match
              ans = max(solveUsingRec(text1, text2, i+1, j), solveUsingRec(text1, text2, i, j+1));
          }
          return ans;
       }
  
      //2d dp
      //agar string ko by reference ni bhejoge to TLE maarega
      int solveUsingMemo(string &text1, string &text2, int i, int j, vector<vector<int>> &dp) {
          //base case
          if(i >= text1.length()){
              return 0;
          }
          if(j >= text2.length()){
              return 0;
          }
  
          if(dp[i][j] != -1){
              return dp[i][j];
          }
  
          //1 case:
          int ans = 0;
          //match 
          if(text1[i] == text2[j]){
              ans = 1 + solveUsingMemo(text1, text2, i+1, j+1, dp);
          } else {
              //not match
              ans = max(solveUsingMemo(text1, text2, i+1, j, dp), solveUsingMemo(text1, text2, i, j+1, dp));
          }
          dp[i][j] = ans;
          return dp[i][j];
       }
  
      int solveUsingTabu(string &text1, string &text2) {
          vector<vector<int>> dp(text1.length()+1, vector<int>(text2.length()+1, 0));
  
          for(int i = text1.length()-1; i >= 0; i--){
               for(int j = text2.length()-1; j >= 0; j--){
                  int ans = 0;
                  //match 
                  if(text1[i] == text2[j]){
                      ans = 1 + dp[i+1][j+1];
                  } else {
                      //not match
                      ans = max(dp[i+1][j], dp[i][j+1]);
                  }
                  dp[i][j] = ans;
               }
          }
  
          return dp[0][0];
      }
  
          int solveUsingTabuSO(string &text1, string &text2) {
          // vector<vector<int>> dp(text1.length()+1, vector<int>(text2.length()+1, 0));
          vector<int> prev(text2.length()+1,0);
          vector<int> curr(text2.length()+1,0);
  
          for(int i = text1.length()-1; i >= 0; i--){
               for(int j = text2.length()-1; j >= 0; j--){
                  int ans = 0;
                  //match 
                  if(text1[i] == text2[j]){
                      ans = 1 + prev[j+1];
                  } else {
                      //not match
                      ans = max(prev[j], curr[j+1]);
                  }
                  curr[j] = ans;
               }
  
               //shift
               prev = curr;
          }
  
          return prev[0];
      }
      
      
      int longestCommonSubsequence(string text1, string text2) {
          int i = 0;
          int j = 0;
          vector<vector<int>> dp(text1.length()+1, vector<int>(text2.length()+1, -1));
          return solveUsingTabuSO(text1, text2);
      }
  };
  