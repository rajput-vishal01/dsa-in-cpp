//gfg:Array subset of another array


/*
methods:
M1->Pick elem from a2 search it in a1 and mark visited(to avoid duplicate elem collision)
M2->same as M1 just use Binary seach for  searching ->O(n log n{sort})+O(m log n)
M3->use HashMap :Traverse a2 and store value and occurance (to avoid duplicate elem collision) hen traverse a2 and subtract that occurance-->if all maping of a2 found in a1 return true else false
*/


class Solution {
  public:
    bool isSubset(vector<int> &a, vector<int> &b) {
        unordered_map<int,int>mp;
        
        for(int i=0;i<a.size();i++){
            mp[a[i]]++;
        }
        
        for(int i=0;i<b.size();i++){
            if(mp.find(b[i]) == mp.end()){
               return false;
                
            }else{
                if(mp[b[i]]>0){
                    mp[b[i]]--;
                }else{
                    return false;
                }
                
            }
        }
        return true;
    }
};