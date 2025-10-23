// GFG : Merge two BST 's

/*
methods:
1.traverse both the tree and get inorder saved in vector,merge the vector,create new tree
2.Perform simultaneous inorder traversals of both BSTs using stacks and merge their elements on the fly to get a single sorted list without storing full traversals.

*/

class Solution {
  public:
    vector<int> merge(Node *root1, Node *root2) {
        stack<Node*> s1, s2;
        vector<int> ans;
        
        Node* a = root1;
        Node* b = root2;
        
        while(a || b || !s1.empty() || !s2.empty()) {
            
            //push all left nodes
            while(a){
                s1.push(a);
                a=a->left;
            }
            while(b){
                s2.push(b);
                b=b->left;
            }
            
            //if one stack empty
            if(s1.empty()){
                b=s2.top(); s2.pop();
                ans.push_back(b->data);
                b=b->right;
            }
            else if(s2.empty()){
                a=s1.top(); s1.pop();
                ans.push_back(a->data);
                a=a->right;
            }
            else{
                //compare top elements
                if(s1.top()->data <= s2.top()->data){
                    a=s1.top(); s1.pop();
                    ans.push_back(a->data);
                    a=a->right;
                }else{
                    b=s2.top(); s2.pop();
                    ans.push_back(b->data);
                    b=b->right;
                }
            }
        }
        return ans;
    }
};
