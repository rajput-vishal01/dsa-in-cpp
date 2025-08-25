//Leetcode 912 : Sort an Array

//Normal Merge Sort
class Solution {
public:
    void merge(vector<int>& arr, vector<int>& temp, int start, int mid, int end) {
        int i = start, j = mid + 1, k = start;

        while (i <= mid && j <= end) {
            if (arr[i] <= arr[j]) temp[k++] = arr[i++];
            else temp[k++] = arr[j++];
        }

        while (i <= mid) temp[k++] = arr[i++];
        while (j <= end) temp[k++] = arr[j++];

        for (int idx = start; idx <= end; idx++) {
            arr[idx] = temp[idx];
        }
    }

    void mergeSort(vector<int>& arr, vector<int>& temp, int start, int end) {
        if (start >= end) return;

        int mid = start + (end - start) / 2;
        mergeSort(arr, temp, start, mid);
        mergeSort(arr, temp, mid + 1, end);
        merge(arr, temp, start, mid, end);
    }

    vector<int> sortArray(vector<int>& nums) {
        vector<int> temp(nums.size(), 0);
        mergeSort(nums, temp, 0, nums.size() - 1);
        return nums;
    }
};

//MergeSort inplace => using two pointers + Quick Sort
class Solution {
public:
    void inplaceMerge(vector<int>& arr, int start, int mid, int end) {
        int i = start, j = mid + 1;
        
        while (i <= mid && j <= end) {
            if (arr[i] <= arr[j]) {
                i++;
            } else {
                int val = arr[j];
                int index = j;

                // Shift all elements between i and j-1 to the right
                while (index > i) {
                    arr[index] = arr[index - 1];
                    index--;
                }
                arr[i] = val;

                // Update pointers
                i++;
                mid++;
                j++;
            }
        }
    }

    void mergeSort(vector<int>& arr, int start, int end) {
        if (start >= end) return;

        int mid = start + (end - start) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);

        inplaceMerge(arr, start, mid, end);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};


//Merge Sort inplace => Gap Method.(BEST)-> Shell Sort style merge
class Solution {
public:
    void merge(vector<int>& arr, int start, int mid, int end) {
        int total_len = end-start+1;
        int gap = total_len/2+total_len%2;

        while(gap>0){ 
            int i=start,j=start+gap;
            while(j<=end){
                if(arr[i]>arr[j]) swap(arr[i],arr[j]);
                ++i,++j;
            }
            gap=gap<=1 ? 0 : (gap/2)+(gap%2);
        }
    }

    void mergeSort(vector<int>& arr, int start, int end) {
        if (start >= end) return;

        int mid = start + (end - start) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};
