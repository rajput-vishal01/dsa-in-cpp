// Leetcode Problem : 112


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
  public:
      bool hasPathSum(TreeNode* root, int targetSum) {
          if (!root)
              return false;
          // If it's a leaf node, check if the remaining sum equals node's value
          if (!root->left && !root->right)
              return targetSum == root->val;
          // Recursively check the left and right subtrees with the updated sum
          return hasPathSum(root->left, targetSum - root->val) ||
                 hasPathSum(root->right, targetSum - root->val);
      }
  };
  