/*
GFG: Aggressive Cows
*/
class Solution {
  public:
    bool canBePlaced(vector<int> &stalls, int totalCows,int mid){
        //place one on 0th index
        int pos=stalls[0];
        int cowsPlaced=1;
        
        for(int i=1;i<stalls.size();i++){
            if(stalls[i]-pos>=mid){
                cowsPlaced++;
                pos=stalls[i];
            }
            
            if(cowsPlaced == totalCows) return true;
            
        }
        return false;
    }
    
    int aggressiveCows(vector<int> &stalls, int totalCows) {
        sort(stalls.begin(),stalls.end());
        int start=0;
        int end=stalls[stalls.size()-1]-stalls[0];
        int ans=-1;
        
        while(start<=end){
            int mid= start+(end-start)/2;
            if(canBePlaced(stalls,totalCows,mid)){
                ans=mid;
                start=mid+1;
                
            }
            else{
                end=mid-1;
            }
        }
        return ans;
    }
};