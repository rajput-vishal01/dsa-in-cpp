// leetcode 140. Word Break II
class Solution {
public:
   
   vector<string> solve(string s,unordered_map<string,bool>mp,int i) {
        if(i==s.size()) return {""};
        vector<string>ans;
        string word;

        for(int j=i;j<s.size();j++){
            word.push_back(s[j]);
            if(mp.find(word)==mp.end()) continue;

            auto right = solve(s,mp,j+1);

            for(auto eachRightPart:right){
                if(eachRightPart == "") 
                    ans.push_back(word);
                else 
                    ans.push_back(word + " " + eachRightPart);
            }
        }
        return ans;

        
    }

    vector<string> solveTD(string s, unordered_map<string,bool> mp, int i, unordered_map<int,vector<string>> &dp) {
        if(i==s.size()) return {""};

        if(dp.find(i)!=dp.end()) return dp[i];

        vector<string>ans;
        string word;

        for(int j=i;j<s.size();j++){
            word.push_back(s[j]);
            if(mp.find(word)==mp.end()) continue;

            auto right = solveTD(s,mp,j+1,dp);

            for(auto eachRightPart:right){
                if(eachRightPart == "") 
                    ans.push_back(word);
                else 
                    ans.push_back(word + " " + eachRightPart);
            }
        }
        return dp[i] = ans;
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,bool>mp;
        for(auto word:wordDict) mp[word]=true;

        // return solve(s,mp,0);
        unordered_map<int,vector<string>> dp;
        return solveTD(s,mp,0,dp);
    }
};