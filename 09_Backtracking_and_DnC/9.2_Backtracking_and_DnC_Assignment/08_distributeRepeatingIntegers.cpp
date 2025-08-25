// Leetcode 1655. Distribute Repeating Integers

class Solution {
public:
    bool canDistribute_helper(
        vector<int>&counts,vector<int>& quantity,int ithCustomer){
        //base condition
        if(ithCustomer == quantity.size()) return true;

        for(int i=0;i<counts.size();i++){
            if(counts[i]>=quantity[ithCustomer]){
                counts[i]-=quantity[ithCustomer];
                if(canDistribute_helper(counts,quantity,ithCustomer+1)){
                    return true;
                }
                counts[i]+=quantity[ithCustomer];
            }
        }

        return false;

  

    }
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int,int>countMap;

        for(auto num:nums){
            countMap[num]++;
        }
        vector<int>counts;
        for(auto it:countMap){
            counts.push_back(it.second);
        }
        sort(quantity.rbegin(),quantity.rend()); //sort to get false faster and avoid TLE
        return canDistribute_helper(counts,quantity,0);
    }
};