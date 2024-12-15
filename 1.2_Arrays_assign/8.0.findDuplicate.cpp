/*Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
There is only one repeated number in nums,but the number can repeat itself, return this repeated number.
Input: nums = [1,3,4,2,2,2]
Output: 2
*/

/*
ways todo the ques.
1.sort and check i and i+1 are equal or not
2.Negative marking : for each index the element with same index value is present(visit them and mark visited) .if index repeated/ already visited twice that number is repeated.
3.Positioning method :sort the elements in a way that index and value both are equal then the element present at 0th index is repeated element.

*/




#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

/*
//method:1:T.C= n log n (because of sort fn)
int findDuplicate(vector<int>& nums) {
    sort(nums.begin(), nums.end()); 
    for (int i = 0; i < nums.size() - 1; i++) {
        if (nums[i] == nums[i + 1]) {
            return nums[i]; 
        }
    }
    return -1; 
}
*/

/*
//method:2:T.C= n
int findDuplicate(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        // Calculate index using absolute value
        int index = (nums[i] > 0 ? nums[i] : -nums[i]) - 1;
        // Check if the value at this index is already visited
        if (nums[index] < 0) {
            return abs(nums[i]); // Duplicate found
        }
        // Mark the index as visited by making the value at nums[index] negative
        nums[index] = -nums[index];
    }

    return -1; // Shouldn't reach here since there's always a duplicate
}
*/

//method:3:T.C= n
int findDuplicate(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        while (nums[i] != nums[nums[i] - 1]) {
            swap(nums[i], nums[nums[i] - 1]);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (nums[i] != i + 1) {
            return nums[i];
        }
    }
    return -1;
}

int main() {
    vector<int> nums = {1, 3, 4, 2, 2, 2};
    
    cout << "The duplicate number is: " << findDuplicate(nums) << endl;
    return 0;
}
