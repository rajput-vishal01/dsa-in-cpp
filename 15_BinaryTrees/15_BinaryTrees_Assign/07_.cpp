// leetcode 938. Range Sum of BST

/*
methods:
1.traverse and add all the pairs within the range
2.just optimise the traversal as its a BST
*/

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root) return 0;
        
        //left mai jaake fyda nahi
        if(root->val < low)
            return rangeSumBST(root->right, low, high);

        //right mai jaake fyda nahi
        if(root->val > high)
            return rangeSumBST(root->left, low, high);

        return root->val +
               rangeSumBST(root->left, low, high) +
               rangeSumBST(root->right, low, high);
    }
};
