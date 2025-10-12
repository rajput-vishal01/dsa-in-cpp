// GFG : transform to sum tree

class Solution {
  public:

    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    
    int solve(Node *root){
        if(!root) return 0;
        
        if(root->left==NULL && root->right==NULL){
            //its a leaf node
            int temp=root->data;
            root->data=0;
            return temp;
        }
        
        int leftSum=solve(root->left);
        int rightSum=solve(root->right);
        
        int temp = root->data;
        root->data=leftSum+rightSum;
        return root->data+temp;
        
    }
    
    void toSumTree(Node *node) {
       solve(node);
    }
};