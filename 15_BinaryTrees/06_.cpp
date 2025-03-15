/*
Leetcode :: 235
*/

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
      TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
          if(root ==NULL){
              return NULL;
          }
  
          if(root->val ==p->val){
              return p;
          }
  
          if(root->val ==q->val){
              return q;
          }
  
          TreeNode* left = lowestCommonAncestor(root->left,p,q);
          TreeNode* right = lowestCommonAncestor(root->right,p,q);
  
          //4 cases:: 
  
          if(left ==NULL && right == NULL){
              return NULL;
          }
          
          else if(left !=NULL && right == NULL){
              return left;
          }
  
         else  if(left ==NULL && right != NULL){
              return right;
          }
          else{
              return root;
          }
  
  
      }
  };


  /*
  Optimised approch ONLy for BST
  */

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
      TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
          
          if(root == NULL) {
              return NULL;
          }
          //case A: 
          //p and q are both on left side 
          //right -> neglect and left -> select
          if(p->val < root-> val && q->val < root-> val) {
              TreeNode* leftAns = lowestCommonAncestor(root->left, p , q);
              if(leftAns != NULL) {
                  return leftAns;
              }
          }
          //case B:
          //p and q are both on right side 
          if(p->val > root->val && q->val > root->val) {
              TreeNode* rightAns = lowestCommonAncestor(root->right,p,q);
              if(rightAns != NULL) {
                  return rightAns;
              }
          }
          //case C:
          //p in left subtree and q in right subtree
          //case D:
          // q in left subtree and p in right subtree
          return root;
      }
  };