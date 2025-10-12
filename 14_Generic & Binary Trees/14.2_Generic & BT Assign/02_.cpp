//Leetcode 543 : diameter-of-binary-tree
// fastway to get the answer

#include<climits>

class Solution {
public:
    int D=INT_MIN;
    int height(TreeNode* root){
        if(!root) return 0;

        int lh=height(root->left);
        int rh=height(root->right);
        
        int currD=lh+rh;
        D=max(D,currD);
        return max(lh,rh)+1;

    }

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return D;
    }
};