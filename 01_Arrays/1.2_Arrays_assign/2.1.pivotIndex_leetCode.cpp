//RUN ON LEETCODE
// 724. Find Pivot Index

/*class Solution {
public:
    int prefixSumApproch(vector<int>& nums) {
        vector<int> lsum(nums.size(), 0);
        vector<int> rsum(nums.size(), 0);

        // Calculate lsum array
        for (int i = 1; i < nums.size(); ++i) {
            lsum[i] = lsum[i - 1] + nums[i - 1];
        }

        // Calculate rsum array
        for (int i = nums.size() - 2; i >= 0; --i) {
            rsum[i] = rsum[i + 1] + nums[i + 1];
        }

        // Find the pivot index
        for (int i = 0; i < nums.size(); ++i) {
            if (lsum[i] == rsum[i]) {
                return i; // Return pivot index
            }
        }

        return -1; // Return -1 if no pivot index is found
    }

    int pivotIndex(vector<int>& nums) {
        // Base case: empty array
        if (nums.empty()) {
            return -1;
        }

        return prefixSumApproch(nums);
    }
};*/
