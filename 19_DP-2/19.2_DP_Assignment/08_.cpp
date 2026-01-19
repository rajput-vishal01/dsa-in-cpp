//Leetcode Problem : 337. House Robber III

class Solution {
public:
    int solve(TreeNode* root){
        if(!root) return 0;

        int robThisHouse = 0, dontRobThisHouse = 0;
        
        //curr house robbed
        robThisHouse = root->val;
        if(root->left){
            robThisHouse += solve(root->left->left) + solve(root->left->right);
        }
        if(root->right){
            robThisHouse += solve(root->right->left) + solve(root->right->right);
        }

        //don't rob curr house
        dontRobThisHouse = solve(root->left) + solve(root->right);

        return max(robThisHouse, dontRobThisHouse);
    }

    int solveTD(TreeNode* root, unordered_map<TreeNode*,int>&dp){
        if(!root) return 0;

        if(dp.find(root) != dp.end()) return dp[root];

        int robThisHouse = 0, dontRobThisHouse = 0;
        
        //curr house robbed
        robThisHouse = root->val;
        if(root->left){
            robThisHouse += solveTD(root->left->left, dp) + solveTD(root->left->right, dp);
        }
        if(root->right){
            robThisHouse += solveTD(root->right->left, dp) + solveTD(root->right->right, dp);
        }
        
        //don't rob curr house
        dontRobThisHouse = solveTD(root->left, dp) + solveTD(root->right, dp);

        dp[root] = max(robThisHouse, dontRobThisHouse);
        return dp[root];
    }


    int rob(TreeNode* root) {
        // return solve(root);
        
        unordered_map<TreeNode*,int>dp;
        return solveTD(root, dp);
    }
};