// leetcode 1008. Construct Binary Search Tree from Preorder Traversal
/*
methods:
1.brute force: simply select the elem and create node and put it where it is supposed to be using BST properties (n^2)
2.sort: as preorder give,sort arr and get inorder traversal and using both create tree.(n log n)
3.Build the BST from preorder by recursively inserting nodes only if they lie within valid min–max bounds, advancing the index as each node is placed.
*/

class Solution {
public:
    TreeNode* build(int &i,int &min,int &max,vector<int>& preorder) {
        if(i>=preorder.size()){
            return NULL;
        }

        TreeNode* root = NULL;
        if(preorder[i]>min && preorder[i]<max){
            root=new TreeNode(preorder[i++]);
            root->left=build(i,min,root->val,preorder);
            root->right=build(i,root->val,max,preorder);
        }

        return root;
        }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int min=INT_MIN, max=INT_MAX;
        int i=0;

        return build(i,min,max,preorder);
    }
};