#include <iostream>
#include <vector>

using namespace std;

int linearSearch(vector<int>& nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == target) {
            return nums[i];
        }
    }
    return -1;
}

int main() {
    vector<int> nums = {4, 2, 9, 7, 5, 6};
    int target = 7;

    int result = linearSearch(nums, target);
    cout << result << endl;

    return 0;
}
