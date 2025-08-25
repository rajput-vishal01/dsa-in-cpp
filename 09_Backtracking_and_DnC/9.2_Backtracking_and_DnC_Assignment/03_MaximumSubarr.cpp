// Leetcode 53. Maximum Subarray

/* M1: 3 for loops->
Time: O(n³)
Space: O(1)

int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    int maxSum = INT_MIN;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int sum = 0;
            for (int k = i; k <= j; k++) {
                sum += nums[k];
            }
            maxSum = max(maxSum, sum);
        }
    }
    return maxSum;
}
 

//Still generate all subarrays using (i, j).
//Instead of a third loop, use a running sum:

int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    int maxSum = INT_MIN;

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += nums[j]; // running sum
            maxSum = max(maxSum, sum);
        }
    }
    return maxSum;
}

*/

// Divide & Conquer approach for Maximum Subarray.
// Divide & Conquer: O(n log n)
class Solution {
public:
    int maxSubArrayHelper(vector<int>& v, int s, int e) {
        if (s == e) return v[s];  // base case: single element

        int mid = s + (e - s) / 2;

        // left & right half
        int maxLeftSum = maxSubArrayHelper(v, s, mid);
        int maxRightSum = maxSubArrayHelper(v, mid + 1, e);

        // cross-border sum
        int leftBorderSum = 0, maxLeftBorderSum = INT_MIN;
        for (int i = mid; i >= s; i--) {
            leftBorderSum += v[i];
            maxLeftBorderSum = max(maxLeftBorderSum, leftBorderSum);
        }

        int rightBorderSum = 0, maxRightBorderSum = INT_MIN;
        for (int i = mid + 1; i <= e; i++) {
            rightBorderSum += v[i];
            maxRightBorderSum = max(maxRightBorderSum, rightBorderSum);
        }

        int maxCrossBorderSum = maxLeftBorderSum + maxRightBorderSum;

        return max({maxLeftSum, maxRightSum, maxCrossBorderSum});
    }

    int maxSubArray(vector<int>& nums) {
        return maxSubArrayHelper(nums, 0, nums.size() - 1);
    }
};


// 3. Optimal Approach (Kadane’s Algorithm – O(n))
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = nums[0];   // sum of current subarray
        int maxSum = nums[0];    // best found so far

        for (int i = 1; i < nums.size(); i++) {
            // either extend current subarray or start new from nums[i]
            currSum = max(nums[i], currSum + nums[i]);  
            maxSum = max(maxSum, currSum);  
        }
        return maxSum;
    }
};
