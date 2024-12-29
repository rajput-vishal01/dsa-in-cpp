//leetcode :- 852. Peak Index in a Mountain Array

/*
You are given an integer mountain array arr of length n where the values increase to a peak element and then decrease.
Return the index of the peak element.
Your task is to solve it in O(log(n)) time complexity.

Example 1:
Input: arr = [0,1,0]
Output: 1


class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int s = 0;
        int e = arr.size() - 1;
        int mid;

        while (s < e) { 
            // Loop until the search space reduces to one element
            mid = s + (e - s) / 2;

            if (arr[mid] < arr[mid + 1]) {
                // Move to the right part of the array
                s = mid + 1;
            } else {
                // Move to the left part, as we might be at the peak or need to move left
                e = mid;
            }
        }
        // When the loop ends, 's' and 'e' will point to the peak index
        return s;
    }
};

*/