// leetcode 139. Word Break

class Solution {
public:

    bool checkForMatch(vector<string>& wordDict,string &word){
        for(auto i:wordDict){
            if(word==i) return true;
        }
        return false;

    }

    bool solve(string &s, vector<string>& wordDict,int wordStart) {
        if(wordStart == s.size()) return true;

        string word = "";
        bool flag = false;

        for(int i=wordStart;i<s.size();i++){
            word+=s[i];
            if(checkForMatch(wordDict,word)){
                flag=flag || solve(s,wordDict,i+1); //save the matched word but also look for next i.e cat matched but need to look for cats as well
            }
        }
        return flag;
        
    }

    bool solveTD(string &s, vector<string>& wordDict,int wordStart,vector<int>&dp) {
        if(wordStart == s.size()) return true;

        string word = "";
        bool flag = false;

        if(dp[wordStart]!=-1) return dp[wordStart];

        for(int i=wordStart;i<s.size();i++){
            word+=s[i];
            if(checkForMatch(wordDict,word)){
                flag = flag || solveTD(s,wordDict,i+1,dp); //save the matched word but also look for next i.e cat matched but need to look for cats as well
            }
        }
        dp[wordStart] = flag;
        return dp[wordStart];
        
    }

    bool solveBU(string &s, vector<string>& wordDict,int wordStart,vector<int>&dp) {
        
        dp[s.size()]=1;

        for(int i=s.size()-1;i>=0;i--){
            string word = "";
            bool flag = false;
            for(int end = i ;end <s.size(); end++){
                word+=s[end];
                if(checkForMatch(wordDict,word)){
                    flag = flag || dp[end+1]; //save the matched word but also look for next i.e cat matched but need to look for cats as well
                }
            }
            dp[i] = flag;
        }
        return dp[0];
        
    }


    bool wordBreak(string s, vector<string>& wordDict) {
        // return solve(s,wordDict,0);
        // vector<int>dp(s.size(),-1);
        // return solveTD(s,wordDict,0,dp); 
        vector<int>dp(s.size()+1,0);
        return solveBU(s,wordDict,0,dp); 
        
    }
};