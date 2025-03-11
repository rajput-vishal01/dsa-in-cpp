/*
Leetcode : 543
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
  public:
  
      int getHeight(TreeNode* root){
          if(root==NULL){
              return 0;
          }
  
          int leftHeight = getHeight(root->left);
          int rightHeight = getHeight(root->right);
         
          int MaxHeight=max(leftHeight,rightHeight);
          int totalHeight = MaxHeight+1;
  
          return totalHeight;
  
      }
      int diameterOfBinaryTree(TreeNode* root) {
          
          if(root==NULL){
              return 0;
          }
  
          int rightSubTree = diameterOfBinaryTree(root->right);
          int leftSubTree = diameterOfBinaryTree(root->left);
          int combination = getHeight(root->left)+ getHeight(root->right);
          int maxDiameter = max(rightSubTree,max(leftSubTree,combination));
  
          return maxDiameter;
      }
  };