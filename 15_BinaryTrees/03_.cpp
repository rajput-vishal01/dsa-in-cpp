/*
Leetcode :: 653
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
  
      void storeInorder(TreeNode* root,vector<int>& inorder){
          if(root==NULL){
              return;
          }
          //LNR
          storeInorder(root->left,inorder);
          inorder.push_back(root->val);
          storeInorder(root->right,inorder);
      }
  
  
      bool checkTwoSum(vector<int>& inorder, int target){
          int size = inorder.size();
          int start = 0;
          int end = size-1;
          while(!inorder.empty() && start<end){
              int sum = inorder[start]+inorder[end];
              if(sum == target){
                  return true;
              }
              if(sum>target){
                  end--;
              }
                if(sum<target){
                  start++;
              }
          }
              return false;
      }
      bool findTarget(TreeNode* root, int k) {
          vector<int> inorder;
          storeInorder(root,inorder);
          bool ans = checkTwoSum( inorder,k);
          return ans;
      }
  };