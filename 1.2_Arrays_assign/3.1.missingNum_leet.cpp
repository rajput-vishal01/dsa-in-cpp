// 268. Missing Number
//A^A =0  (XOR)


/*class Solution {
public:
    int findMissingNumberXor(vector<int>& nums) {
        int ans = 0;
        // XOR all values of the array
        for (int i = 0; i < nums.size(); i++) {
            ans ^= nums[i];
        }

        // XOR all numbers in the range [0, n]
        int n = nums.size();
        for (int i = 0; i <= n; i++) {
            ans ^= i;
        }

        return ans; // The missing number will be the only non-zero value
    }

    int missingNumber(vector<int>& nums) {
        return findMissingNumberXor(nums); // Call the renamed function
    }
};
*/