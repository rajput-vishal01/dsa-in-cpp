#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to get max of each window of size k
    vector<int> getMax(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;

        for(int i = 0; i < nums.size(); i++) {
            // Remove indices out of current window
            if(!dq.empty() && dq.front() <= i - k) dq.pop_front();

            // Remove smaller elements from back
            while(!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();

            dq.push_back(i);

            // Add max to answer when first window is complete
            if(i >= k - 1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }

    // Function to get min of each window of size k
    vector<int> getMin(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;

        for(int i = 0; i < nums.size(); i++) {
            // Remove indices out of current window
            if(!dq.empty() && dq.front() <= i - k) dq.pop_front();

            // Remove larger elements from back
            while(!dq.empty() && nums[dq.back()] > nums[i]) dq.pop_back();

            dq.push_back(i);

            // Add min to answer when first window is complete
            if(i >= k - 1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }

    // Function to get sum of min and max of all windows
    int sumOfMinMax(vector<int>& nums, int k) {
        vector<int> maxVals = getMax(nums, k);
        vector<int> minVals = getMin(nums, k);

        int sum = 0;
        for(int i = 0; i < maxVals.size(); i++) {
            sum += maxVals[i] + minVals[i];
        }
        return sum;
    }
};

int main() {
    vector<int> arr = {2, 5, -1, 7, -3, -1, -2};
    int k = 4;
    Solution sol;
    cout << sol.sumOfMinMax(arr, k) << endl; // Output: 18
}
