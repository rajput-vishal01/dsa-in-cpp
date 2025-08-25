// GFG : Count Inversions


//Method 1: But RunTIme error

class Solution {
public:
    int inversionCount(vector<int> &arr) {
        int count = 0;
        for (int i = 0; i < arr.size(); i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                count = arr[i] > arr[j] ? count + 1 : count;
            }
        }
        return count;
    }
};


//Merge Sort -> o(n log n)
class Solution {
public:
    long long merge(vector<int>& arr, vector<int>& temp, int start, int mid, int end) {
        int i = start;
        int j = mid + 1;
        int k = start;
        long long c = 0;

        while (i <= mid && j <= end) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
              //case: count inversion case
                temp[k++] = arr[j++];
                c += (mid - i + 1);  // count inversions
            }
        }

        while (i <= mid) {
            temp[k++] = arr[i++];
        }

        while (j <= end) {
            temp[k++] = arr[j++];
        }

        for (int idx = start; idx <= end; idx++) {
            arr[idx] = temp[idx];
        }

        return c;
    }

    long long mergeSort(vector<int>& arr, vector<int>& temp, int start, int end) {
        if (start >= end) return 0;

        long long c = 0;
        int mid = start + (end - start) / 2;

        c += mergeSort(arr, temp, start, mid);
        c += mergeSort(arr, temp, mid + 1, end);
        c += merge(arr, temp, start, mid, end);

        return c;
    }

    long long inversionCount(vector<int>& arr) {
        vector<int> temp(arr.size(), 0);
        return mergeSort(arr, temp, 0, arr.size() - 1);
    }
};
