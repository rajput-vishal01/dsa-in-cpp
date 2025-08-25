// Leetcode 47. Permutations II

class Solution {
public:
    void permuteUnique_helper(vector<int>& nums, vector<vector<int>>& ans, int start) {
        // base
        if(start==nums.size()) {
            ans.push_back(nums);
            return;
        }
        
        unordered_map<int,bool>visited;
        for(int i=start;i<nums.size();i++) {
            
            if(visited.find(nums[i]) != visited.end()) continue;
            visited[nums[i]]=true;
            swap(nums[start],nums[i]);
            permuteUnique_helper(nums,ans,start+1);
            swap(nums[start],nums[i]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        permuteUnique_helper(nums,ans,0);
        
        //May be TLE : Because of this
        // set<vector<int>>st;
        // for(auto e:ans){
        //     st.insert(e);
        // }
        // ans.clear();
        // for(auto e:st){
        //     ans.push_back(e);
        // }

        return ans;
    }
};