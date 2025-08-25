// Leetcode 40. Combination Sum II

class Solution {
public:
        void combinationSum_helper(vector<int> &candidates,int target,vector<int>v,vector<vector<int>>&ans,int index){
        //base
        if(target==0){
            ans.push_back(v);
            return ;
        }

        if(target<0) return ;
        
        for(int i=index;i<candidates.size();i++){
            //To overcome TLE add a check - as arr sorted stop picking duplicates
            if(i>index && candidates[i] ==candidates[i-1]) continue;

            v.push_back(candidates[i]);
             combinationSum_helper(candidates,target-candidates[i],v,ans,i+1);
             v.pop_back();
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>v;

        combinationSum_helper(candidates,target,v,ans,0);

        //TLE : Because of this
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