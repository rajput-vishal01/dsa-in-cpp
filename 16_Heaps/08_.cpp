/*
GFG :: Merge K Sorted Arrays

algos:
1.Single array mai copy and then sort.
2.Min heap us ekr ke top elem daalte raho new array mai bas track krte raho kise use kiya hai and kise ni
*/

class Info{
  public:
      int data;
      int rIndex;
      int cIndex;
      
      Info(int x, int y, int z) {
          this->data = x;
          this->rIndex = y;
          this->cIndex = z;
      }
};

class compare{
public:
  bool operator()(Info* a, Info* b) {
      return a->data > b->data;
  }
};

class Solution
{
  public:
  //Function to merge k sorted arrays.
  vector<int> mergeKArrays(vector<vector<int>> arr, int K)
  {
      priority_queue<Info*, vector<Info*>, compare> pq;
      vector<int> ans;
      //process first k elements
      //hr array ka first element
      int totalRows = arr.size();
      int totalColumns = arr[0].size();
      for(int row=0; row<totalRows; row++) {
          int element = arr[row][0];
          Info* temp = new Info(element, row, 0);
          pq.push(temp);
      }
      
      //main logic
      while(!pq.empty()) {
          Info* front = pq.top();
          pq.pop();
          
          //include in answer
          int frontdata = front->data;
          int front_rIndex = front->rIndex;
          int front_cIndex = front->cIndex;
          ans.push_back(frontdata);
          
          //check if aage data h frontelement k , then push it inside the pq
          if(front_cIndex+1 < totalColumns) {
              int element = arr[front_rIndex][front_cIndex+1];
              Info* temp = new Info(element, front_rIndex,front_cIndex+1 );
              pq.push(temp);
          }
      }
      return ans;   
  }
};