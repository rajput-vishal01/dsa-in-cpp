/*
Leetcode :: 230
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
  
      int kthSmallest(TreeNode* root, int k) {
          vector<int> inorder;
          storeInorder(root,inorder);
  
          return inorder[k-1];
  
      }
  };

  /*Another Way -- recurr.*/

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
      void solve(TreeNode* root, int k, int &count, int &ans) {
          if (root == NULL) {
              return;
          }
          // LNR
          solve(root->left, k, count, ans);
          count++;
          if (count == k) {
              ans = root->val;
              return;
          }
          solve(root->right, k, count, ans);
      }
  
      int kthSmallest(TreeNode* root, int k) {
          int count = 0;
          int ans = -1; // Default value if k is out of bounds
          solve(root, k, count, ans);
          return ans;
      }
  };
  