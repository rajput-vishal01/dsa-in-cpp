/*
GFG Ques::
Binary Tree to Doubly Linked List
*/


/*
Using RNL __ reverse inorder Traversal
*/
// This function should return head to the DLL
class Solution {
  public:
    void solve(Node* root, Node*& head) {
        if(root == NULL) {
            return;
        }
        //RNL 
        //R
        solve(root->right, head);
        //assume kr skte hu, k right part ki llbangyi hogi
        //and head right part ki ll k start node pr hoga 
        //N
        root->right = head;
        if(head != NULL) {
            head->left = root;
        }
        //yaha tk aapki N and Rn ki LL ban chuki h 
        //head ko update karna h 
        head = root;
        //ab Tree ka left part pending h 
        //L
        solve(root->left, head);
    }
    Node* bToDLL(Node* root) {
        Node* head = NULL;
        solve(root,head);
        return head;
               
    }
};


/*
Using LNR __ inorder Traversal
*/

// This function should return head to the DLL
class Solution {
    public:
      void solve(Node* root, Node*& head, Node*& tail) {
          if(root == NULL) {
              return ;
          }
          
          //LNR - inorder
          solve(root->left, head, tail);
          //assume krke chalra hu, k left me LL bangyi h 
          //root node ko left LL se connect krna hoga 
          //head and tail ko update krna hoga 
          if(tail != NULL) {
              //ab tk ki LL empty nahi h 
              tail->right = root;
              root->left = tail;
              //tail update
              tail = root;
          }
          else {
              ///ab tk ki LL empty h, yaani first node 
              //ab insert hogi
              head = root;
              tail = root;
          }
          //ab mujhe right part ko connect krna h 
          solve(root->right, head, tail);
      }
      Node* bToDLL(Node* root) {
          Node* head = NULL;
          Node* tail = NULL;
          solve(root, head, tail);
          return head;
      }
  };
  
