/*
GFG-937: Book allocation problem 
*/
class Solution {
  public:
    
    bool isPossibleSoln(vector<int> &arr, int noOfstudents,int MaxNoOfPages,int noOfBooks){
        int pageSum=0;
        int countOfstundents=1;
        
        for(int i=0;i<noOfBooks;i++){
            if(arr[i]>MaxNoOfPages) return false;
            
            if(pageSum+arr[i]>MaxNoOfPages){
                countOfstundents++;
                pageSum=arr[i];
                if(countOfstundents>noOfstudents) return false;
            }
            else{
                pageSum+=arr[i];
            }
        }
        return true;
    }
  
    int findPages(vector<int> &arr, int noOfstudent) {
        int noOfBooks=arr.size();
        int start=0;
        int end= accumulate(arr.begin(),arr.end(),0);
        int ans=-1;
        
        if(noOfstudent>noOfBooks) return -1;
        
        while(start<=end){
            int mid=start+(end-start)/2;
            
            if(isPossibleSoln(arr,noOfstudent,mid,noOfBooks)){
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }
};