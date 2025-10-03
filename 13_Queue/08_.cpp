// GFG : First negative in every window of size k


//sliding window
class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        deque<long long int>q;
        vector<int> ans;
       
        //step 1: process the window
        for(int i=0;i<k;i++){
            int elem = arr[i];
             
            if(elem < 0){
                q.push_back(i);
            }
        }
       
       
        //above will store indexes of the -ve number from the first window;
        //step:2 process the remaining window;
       
        // put the data of first window
        if(q.empty()){
            ans.push_back(0);
        }else{
            int index=q.front();
            int elem=arr[index];
            ans.push_back(elem);
        }
       
       
        for(int i=k;i<arr.size();i++){
            // slide the window
            //removal of prev elem
            if(!q.empty() &&  i-q.front()>=k){
                q.pop_front();
            }
           
            //addition of new elem
            int elem=arr[i];
            if(elem<0){
                q.push_back(i);
            }
           
            // put the data of current window
            if(q.empty()){
                ans.push_back(0);
            }else{
                int index=q.front();
                int elem=arr[index];
                ans.push_back(elem);
            }
        }
       
        return ans;
    }
};

