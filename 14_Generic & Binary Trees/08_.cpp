/*
IMP ques:: Construct a tree from inorder and preorder traversal
Leetcode Problem 105
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
      // Helper function to get the index of the target element in inorder traversal.
      int getIndexInorder(const vector<int>& inorder, int target) {
          for (int i = 0; i < inorder.size(); i++) {
              if (inorder[i] == target) {
                  return i;
              }
          }
          return -1;
      }
      
      // Constructs the tree recursively.
      // Note: preOrderIndex is passed by reference to keep track of the current index in preorder traversal.
      TreeNode* constructTree(vector<int>& preorder, vector<int>& inorder, int &preOrderIndex, int inOrderStartIndex, int inOrderEndIndex) {
          // Base condition: if there are no elements to construct the tree.
          if (inOrderStartIndex > inOrderEndIndex || preOrderIndex >= preorder.size()) {
              return NULL;
          }
          
          // Process preorder element for root element.
          int elem = preorder[preOrderIndex];
          preOrderIndex++;
          TreeNode* root = new TreeNode(elem);
          
          // Step 2: Find this element inside inorder traversal.
          int elemIndexInsideInorder = getIndexInorder(inorder, elem);
          
          // Inorder left part -> indices: inOrderStartIndex to elemIndexInsideInorder - 1.
          root->left = constructTree(preorder, inorder, preOrderIndex, inOrderStartIndex, elemIndexInsideInorder - 1);
          
          // Inorder right part -> indices: elemIndexInsideInorder + 1 to inOrderEndIndex.
          root->right = constructTree(preorder, inorder, preOrderIndex, elemIndexInsideInorder + 1, inOrderEndIndex);
          
          return root;
      }
      
      TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
          int preOrderIndex = 0;
          int inOrderStartIndex =0;
          return constructTree(preorder, inorder, preOrderIndex, inOrderStartIndex, inorder.size() - 1);
      }
  };
   