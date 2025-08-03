/*
GFG-1535:The Painter's Partition Problem-II
--same as book allocation
*/
class Solution {
  public:
    
    bool canBePainted(vector<int>& arr, int painter,int maxTime,int noOfBoards){
        int timeSum=0;
        int countOfPainter=1;
        
        for(int i=0;i<noOfBoards;i++){
            if(arr[i]>maxTime) return false;
            
            if(timeSum+arr[i]>maxTime){
                countOfPainter++;
                timeSum=arr[i];
                
                if(countOfPainter>painter) return false;
                
            }else{
                timeSum+=arr[i];
            }
        }
        return true;
    }
    
    int minTime(vector<int>& arr, int painter) {
       int noOfBoards=arr.size(); 
       
       int start=0;
       int end=accumulate(arr.begin(),arr.end(),0);
       int ans=-1;
      
       while(start<=end){
           int mid=start+(end-start)/2;
           
           if(canBePainted(arr,painter,mid,noOfBoards)){
               ans=mid;
               end=mid-1;
           }else{
               start=mid+1;
           }
       }
    return ans;
    }
};