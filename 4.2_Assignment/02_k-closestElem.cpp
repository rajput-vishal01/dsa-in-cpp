// 658. Find K Closest Elements

/*
class Solution {
public:

    vector<int> twoPtrMethod(vector<int>& arr, int k, int x) {
        int l = 0, h = arr.size() - 1;
        
        // Move the pointers until the window size is exactly k
        while (h - l >= k) {
            if (x - arr[l] > arr[h] - x) {
                l++; // Move left pointer right
            } else {
                h--; // Move right pointer left
            }
        }

        // Collect the k closest elements
        // vector<int> ans;
        // for (int i = l; i <= h; i++) { 
        //     // Inclusive of h
        //     ans.push_back(arr[i]);
        // }

        // return ans;


        return vector<int>(arr.begin()+l, arr.begin()+h+1);
    }

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        return twoPtrMethod(arr, k, x);
    }
};


//T.C:O(n-k)
//S.C:O(1)

*/