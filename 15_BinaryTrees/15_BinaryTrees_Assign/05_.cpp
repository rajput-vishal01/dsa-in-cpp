// leetcode 1382. Balance a Binary Search Tree

class Solution {
public:
    void inOrder(TreeNode* root, vector<int>&inOrderTraversal) {
       if(root == NULL) return;
       //LNR
       inOrder(root->left,inOrderTraversal);
       inOrderTraversal.push_back(root->val);
       inOrder(root->right,inOrderTraversal);
    }

    TreeNode* buildTree(vector<int>&inOrderTraversal,int start,int end){
        if(start>end){
            return NULL;
        }
        
        int mid = (start+end)/2;
        TreeNode* root = new TreeNode(inOrderTraversal[mid]);
        root->left = buildTree(inOrderTraversal,start,mid-1);
        root->right = buildTree(inOrderTraversal,mid+1,end);
        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int>inOrderTraversal;
        inOrder(root,inOrderTraversal);
        int start = 0;
        int end = inOrderTraversal.size()-1;
        return buildTree(inOrderTraversal,start,end);
    }
};