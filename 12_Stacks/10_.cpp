// LeetCode 84. Largest Rectangle in Histogram

class Solution {
public:
    void nextSmallestElem(vector<int>&heights,vector<int>&nextAns){
        stack<int>st;
        st.push(-1);
        int n = heights.size();

        for(int i=n-1;i>=0;i--){
            int elem = heights[i];
              ///corner case -> = wala main bhul jata
            while(st.top() !=-1 && heights[st.top()]>=elem){
                st.pop();
            }
            nextAns.push_back(st.top());
            st.push(i);
        }
    }

    void prevSmallestElem(vector<int>&heights,vector<int>&prevAns){
        stack<int>st;
        st.push(-1);
        int n = heights.size();

        for(int i=0;i<=n-1;i++){
            int elem = heights[i];
              ///corner case -> = wala main bhul jata
            while(st.top() !=-1 && heights[st.top()]>=elem){
                st.pop();
            }
            prevAns.push_back(st.top());
            st.push(i);
        }
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nextAns;
        vector<int> prevAns;
        nextSmallestElem(heights,nextAns);
        reverse(nextAns.begin(), nextAns.end());

        //incase of nextSmallestElem -1 in arr means the actual size of 
        //arr else we will never get the correct width
        for(int i=0 ;i<nextAns.size(); i++) {
            if(nextAns[i] == -1) {
                nextAns[i] = nextAns.size(); 
            }
        }
        
        //incase of prevSmallestElem -1 in arr means the no prev exists which is cprrect
        prevSmallestElem(heights, prevAns);

        vector<int>area;
        for(int i=0;i<nextAns.size();i++){
            int width = nextAns[i]-prevAns[i]-1;
            int height=heights[i];
            int currArea = width*height;
            area.push_back(currArea);
        }

        int MaxArea = INT_MIN;
        for(int i=0;i<area.size();i++){
            MaxArea=max(MaxArea,area[i]);
        }
        return MaxArea;
    }
};