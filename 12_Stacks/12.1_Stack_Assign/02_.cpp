// GFG : The Celebrity Problem
//V.IMP Ques.

class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
       stack<int>st;
       int size=mat[0].size();
       
       //step 1: push all person in stack
       for(int i=0;i<size;i++){
           st.push(i);
       }
       
       //step 2:check who might be a celeb
       while(st.size()!=1){
           int personA = st.top(); st.pop();
           int personB = st.top(); st.pop();
           
           if(mat[personA][personB]){
               //B could be a celeb
               st.push(personB);
           }else{
               //A could be a celeb
               st.push(personA);
           }
           
       }
       
       int mightBeACeleb=st.top(); st.pop();
       
       //Celeb should not know anyone
       for(int i=0;i<size;i++){
           if(i!=mightBeACeleb && mat[mightBeACeleb][i]!=0)
            return -1;
       }
       
       //everyone should know celeb
       for(int i=0;i<size;i++){
             if(i!=mightBeACeleb && mat[i][mightBeACeleb]==0)
            return -1;
       }
       
       return mightBeACeleb;
       
       
        
    }
};