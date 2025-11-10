// gfg : largest subarray with 0 sum

/*
methods:
1:Naive : get all the sub arrays, store all the sub arrays length whose sum was 0 and filter from their the sub array with largest length.->o(n^3)
2.maps:Approach: Use prefix sum and hashmap to track first occurrences of sums.If the same sum repeats, it means the subarray between them has sum 0 — update max length.
*/

class Solution {
  public:
    int maxLength(vector<int>& arr){
        unordered_map<int,int> mp;
        int csum = 0;
        int ans = 0; // max length of sub-arr with sum = 0
        
        for(int i = 0; i < arr.size(); i++){
            csum += arr[i];
            
            if(csum == 0){
                ans = max(ans, i + 1);
            }else if(mp.find(csum) == mp.end()){
                // store first occurrence of csum
                mp[csum] = i;
            }else{
                // csum already exists, update max length
                ans = max(ans, i - mp[csum]);
            }
        }
        return ans;
    }
};


// gfg : largest subarray of 0's and 1's

class Solution {
  public:
    int maxLen(vector<int> &arr) {
        
        
        unordered_map<int,int> mp;
        int csum = 0;
        int ans = 0; // max length of sub-arr with sum = 0
        
        for(int i = 0; i < arr.size(); i++){
            int val = arr[i] == 0 ? -1 : 1; // 0 ki jagha -1 daal do.
            csum += val; //uske hisab sai dekh lo
            if(csum == 0){
                ans = max(ans, i + 1);
            }else if(mp.find(csum) == mp.end()){
                // store first occurrence of csum
                mp[csum] = i;
            }else{
                // csum already exists, update max length
                ans = max(ans, i - mp[csum]);
            }
        }
        return ans;
        
    }
};