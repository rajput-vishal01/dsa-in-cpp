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
  
  // Leetcode Problem : 113

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
    void solve(TreeNode* root, int targetSum,int sum,vector<int> &path,vector<vector<int>> &ans){
        if(root == NULL) return ;

        //process the root
        sum=sum+root->val;
        path.push_back(root->val);
        
        //if leaf node and sum matches,store ans in ans and return;
        if(root->left==NULL && root->right==NULL && sum==targetSum){
            ans.push_back(path);
        }else {
            solve(root->left, targetSum, sum, path, ans);
            solve(root->right, targetSum, sum, path, ans);
        }
        // backtrack
        path.pop_back();
        

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int sum=0;
        vector<int> path;
        vector<vector<int>> ans;

        solve(root,targetSum,sum,path,ans);
        return ans;
        
    }
};