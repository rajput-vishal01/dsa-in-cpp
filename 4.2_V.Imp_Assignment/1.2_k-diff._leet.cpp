/*Leetcode Problem : -532. K-diff Pairs in an Array
2.Two pointer approch:-

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());  
        set<pair<int, int>> ans;
        int i = 0, j = 1;   
        while (j < nums.size()) {
            int diff = nums[j] - nums[i];
            
            if (diff == k) {
                ans.insert({nums[i], nums[j]});
                ++i, ++j;
            }
            else if (diff > k) {
                ++i;
            }
            else {
                ++j;
            }
            if (i == j) {
                ++j;
            }
        }       
        return ans.size();
    }
};
*/