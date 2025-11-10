// 692. Top K Frequent Words

class Solution {
  public:
  
    static bool cmp(pair<string,int>& a, pair<string,int>& b) {
        //if frequencies are equal -> sort lexicographically
        if(a.second == b.second)
            return a.first < b.first;
        
        //otherwise -> higher frequency comes first
        return a.second > b.second;
    }
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        unordered_map<string,int> freq;
        
        //store frequencies
        for(auto &w : words) {
            freq[w]++;
        }
        
        vector<pair<string,int>> vec(freq.begin(), freq.end());
        
        //sort using custom comparator
        sort(vec.begin(), vec.end(), cmp);
        
        vector<string> ans;
        
        //store top k words
        for(int i=0; i<k; i++) {
            ans.push_back(vec[i].first);
        }
        
        return ans;
    }
};
