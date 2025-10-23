// GFG:brothers from different roots or Find Sum Pairs Across Two BSTs

/*
1.brute force: pick node from a, then a-target=x,look for this x in b tree. O(n^2)
2.get inorder traversal of both and store it in vector,place i on 0th of a,and j on n-1 of b, and get all the pairs for the required target (array question)..also can use reverse
  inorder travsersal ob b,and get reverse arr,then place j on 0th...rather then on n-1.
3.similar as above Count pairs with sum `x` by simultaneously traversing one BST in-order and the other reverse in-order using stacks, avoiding extra arrays.
*/

class Solution {
  public:
    int countPairs(Node* root1, Node* root2, int x) {
        int ans=0;
        stack<Node*>s1,s2;
        
        Node* a = root1;
        Node* b = root2;
        
        while(1){
            while(a){
                //inorder
                s1.push(a);
                a=a->left;
            }
            
            while(b){
                //reverseInorder
                s2.push(b);
                b=b->right;
            }
            
            if(s1.empty() || s2.empty()) break;// traversal completed
            
            auto atop=s1.top();
            auto btop=s2.top();
            
            int sum = atop->data+btop->data;
            
            if(sum==x){
                ++ans;
                s1.pop();
                s2.pop();
                
                a=atop->right;
                b=btop->left;
            }else if(sum<x){
                s1.pop();
                a=atop->right;
            }else{
                s2.pop();
                b=btop->left;
            }
        }
        return ans;
    }
};