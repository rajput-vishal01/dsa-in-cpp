/*class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 0;  // Pointer to track the position of unique elements
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[j]) {
                j++;
                nums[j] = nums[i];
            }
        }
        return j + 1;  // Return the number of unique elements
    }
};
*/