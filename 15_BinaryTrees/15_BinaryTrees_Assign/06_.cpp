// GFG:check bst has dead end


class Solution {
  public:
    void solve(Node *root,unordered_map<int,bool>visited,bool &ans){
        
        if(root==0) return;
        
        //NLR
        visited[root->data]=true;
        
        if(root->left==0 && root->right==0){
            //leaf node
            int xPlusOne=root->data+1;
            int xMinusOne=root->data -1 == 0 ? root->data : root->data-1; //so that 1 ho toh woh 0 nah ban jaaye as tree can only have whole numbers
            
            if(visited.find(xPlusOne)!=visited.end() && visited.find(xMinusOne)!=visited.end()){
                ans=true;
                return;
            }
        }
        
        solve(root->left,visited,ans);
        solve(root->right,visited,ans);
        
        
    }
    bool isDeadEnd(Node *root) {
        bool ans = false; //tells there is a DE or NOT
        unordered_map<int,bool>visited;
        
        solve(root,visited,ans);
        return ans;
    }
};