/*Leetcode Problem : -532. K-diff Pairs in an Array

Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.

A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:

0 <= i, j < nums.length
i != j
|nums[i] - nums[j]| == k
Notice that |val| denotes the absolute value of val.

 

Example 1:

Input: nums = [3,1,4,1,5], k = 2
Output: 2
Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
Although we have two 1s in the input, we should only return the number of unique pairs.

*/

// 1. BruteForce:
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int findPairs(vector<int>& nums, int k) {
    int count = 0;
    set<pair<int, int>> uniquePairs;


    for (int i = 0; i < nums.size(); ++i) {
        for (int j = i + 1; j < nums.size(); ++j) {
           
            if (abs(nums[i] - nums[j]) == k) {
                pair<int, int> p = minmax(nums[i], nums[j]); 
                if (uniquePairs.find(p) == uniquePairs.end()) {
                    uniquePairs.insert(p);
                    ++count;
                }
            }
        }
    }

    return count;
}

int main() {
    vector<int> nums = {3, 1, 4, 1, 5};
    int k = 2;
    cout << "Number of unique k-diff pairs: " << findPairs(nums, k) << endl;
    return 0;
}
