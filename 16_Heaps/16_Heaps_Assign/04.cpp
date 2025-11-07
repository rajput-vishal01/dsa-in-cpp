// Leetcode 2163. Minimum Difference in Sums After Removal of Elements

#include <vector>
#include <queue>
#include <limits>

class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int m = nums.size();
        int n = m / 3;
        
        vector<long long> prefix(m, 0), suffix(m + 2, 0);
        
        // Minimize sum of first part: keep n smallest from first 2n elements
        priority_queue<int> maxHeap;
        long long sumLeft = 0;
        for (int i = 0; i < 2 * n; ++i) {
            sumLeft += nums[i];
            maxHeap.push(nums[i]);
            if (maxHeap.size() > n) {
                sumLeft -= maxHeap.top();
                maxHeap.pop();
            }
            if (maxHeap.size() == n) {
                prefix[i] = sumLeft;
            }
        }
        
        // Maximize sum of second part: keep n largest from last 2n elements (scan backwards)
        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long sumRight = 0;
        for (int i = m - 1; i >= n; --i) {
            sumRight += nums[i];
            minHeap.push(nums[i]);
            if (minHeap.size() > n) {
                sumRight -= minHeap.top();
                minHeap.pop();
            }
            if (minHeap.size() == n) {
                suffix[i] = sumRight;
            }
        }
        
        long long answer = numeric_limits<long long>::max();
        for (int i = n - 1; i < 2 * n; ++i) {
            // split point: prefix uses up to i, suffix uses from i+1
            long long leftSum = prefix[i];
            long long rightSum = suffix[i + 1];
            answer = min(answer, leftSum - rightSum);
        }
        
        return answer;
    }
};
