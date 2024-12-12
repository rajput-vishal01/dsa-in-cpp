#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int search(vector<int>& nums, int target) {
    int s = 0;
    int e = nums.size() - 1;
    
    while (s <= e) {
        int mid = s + (e - s) / 2;
        
        if (nums[mid] == target) {
            return nums[mid];
        } else if (target > nums[mid]) {
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    
    return -1;
}

int main() {
    vector<int> nums = {1, 3, 5, 7, 9};
    int target = 5;

    int result = search(nums, target);
    cout << result << endl;

     bool found = binary_search(nums.begin(), nums.end(), target);
    if (found) {
        cout << "Element found using binary_search method" << endl;
    } else {
        cout << "Element not found using binary_search method" << endl;
    } 
    
    return 0;
}
