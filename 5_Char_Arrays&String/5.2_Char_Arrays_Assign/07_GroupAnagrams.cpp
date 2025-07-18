//Leetcode 49. Group Anagrams
 
// t.c o(n k log k) n->strs length and k=max string length
//s/c->o(nk)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
     map<string,vector<string>> mp;

     for(auto str:strs){
        string s = str;
        sort(s.begin(),s.end());
        mp[s].push_back(str);
     }

     //append result
     vector<vector<string>>ans;
     for(auto it=mp.begin();it!=mp.end();it++ ){
        ans.push_back(it->second);
     }
     return ans;

    }
};

//without sort
// t.c o(nk) n->strs length and k=max string length
//s/c->o(nk+mapSize) //map enteries and storage is ignored
class Solution {
public:
    std::array<int,256>hash(string s){
        std::array<int,256>hash={0};
        for(int i=0;i<s.length();i++){
            hash[s[i]]++;
        }
        return hash;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
     map<std::array<int,256>,vector<string>> mp;

     for(auto str:strs){
        mp[hash(str)].push_back(str);
     }

     //append result
     vector<vector<string>>ans;
     for(auto it=mp.begin();it!=mp.end();it++ ){
        ans.push_back(it->second);
     }
     return ans;

    }
};