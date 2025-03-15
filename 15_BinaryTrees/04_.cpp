/*
Leetcode :: 1038 && 538  --same ques and same soln.
---------for 538 just change the main fn name which leetcode is accepting in backend
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
      void storeInorder(TreeNode* root, vector<int>& inorder) {
          if (root == NULL) {
              return;
          }
          // LNR
          storeInorder(root->left, inorder);
          inorder.push_back(root->val);
          storeInorder(root->right, inorder);
      }
  
      void updateTree(TreeNode* root, vector<int>& inorder, int &index) {
          if (root == NULL) {
              return;
          }
          // LNR
          updateTree(root->left, inorder, index);
          root->val = inorder[index];
          index++;
          updateTree(root->right, inorder, index);
      }
  
      TreeNode* bstToGst(TreeNode* root) {
          if (root == NULL) {
              return NULL;
          }
  
          if (root->left == NULL && root->right == NULL) {
              return root;
          }
  
          // Step 1: store inorder
          vector<int> inorder;
          storeInorder(root, inorder);
  
          // Step 2: update inorder as per ques
          int n = inorder.size();
          for (int i = n - 2; i >= 0; i--) {
              inorder[i] += inorder[i + 1];
          }
  
          int index = 0;
          // Step 3: update tree using inorder
          updateTree(root, inorder, index);
  
          return root;
      }
  };
  