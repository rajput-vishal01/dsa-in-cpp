// 643. Maximum Average Subarray 

// used sliding window technique :
/*
sum = sum-num[i]
sum=sum+num[j]
i++; j++;
 */

// Can also be written as :
/*
sum = sum-num[i++]
sum=sum+num[++j] 
*/

/*
class Solution {
public:
    double slidingWindow(vector<int>& nums, int k) {
        int sum = 0;  
        // Calculate the sum of the first 'k' elements
        for (int i = 0; i < k; ++i) {
            sum += nums[i];
        }
        int maxSum = sum;
        // Slide the window
        for (int i = k; i < nums.size(); ++i) {
            sum += nums[i] - nums[i - k];  // Add the new element and remove the old one
            maxSum = max(maxSum, sum);  // Update maxSum if needed
        }
        return (double)maxSum / k;
    }
    double findMaxAverage(vector<int>& nums, int k) {
        return slidingWindow(nums, k);
    }
};
*/