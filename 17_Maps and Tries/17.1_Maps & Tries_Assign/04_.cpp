// gfg : sum equals to sum or Pairs of equals Sum

/*
methods:
1.using nested 4 loops and then matching the pair condition
2.look for a+b paired sum and then store it in map, at the same time look in the map if the pair is already present in the map or not   
*/

class Solution {
  public:
    bool findPairs(vector<int>& arr) {
        unordered_map<int,bool>mp;
        
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                int sum = arr[i]+arr[j];
                
                if(mp.find(sum) != mp.end()){
                    return true;
                }else{
                    mp[sum]=true;
                }
            }
        }
        return false;
    }
};