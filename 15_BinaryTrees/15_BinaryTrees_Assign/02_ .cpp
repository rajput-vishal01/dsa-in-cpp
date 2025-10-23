//GFG : Inorder Successor in BST
/*
Methods:
1.store traversal in vector and return the target using either linear search or binary search.
2.traverse using inorder and return the first greater value then target
*/

class Solution {
  public:
    int inOrderSuccessor(Node *root, Node *x) {
        Node* succ = NULL;
        Node* curr = root;

        while(curr){
            if(curr->data > x->data){
                succ = curr;
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }

        if(succ) return succ->data; 
        return -1;                  
    }
};
