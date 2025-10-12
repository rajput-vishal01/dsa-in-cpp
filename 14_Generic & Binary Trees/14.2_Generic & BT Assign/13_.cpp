//GFG : maximum sum of non-adjacent nodes

class Solution {
  public:
    pair<int,int> getMaxSum_Helper(Node *root) {
        if(!root) return {0,0};
        
        auto left=getMaxSum_Helper(root->left);
        auto right=getMaxSum_Helper(root->right);
        
        //included sum
        int a = root->data+left.second+right.second;
        
        //excluded sum
        int b = max(left.first,left.second)+max(right.first,right.second);
        
        return {a,b};
    }
    
    int getMaxSum(Node *root) {
        auto a =getMaxSum_Helper(root);
        return max(a.first,a.second);
    }
};