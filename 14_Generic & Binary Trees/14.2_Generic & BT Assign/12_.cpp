//gfg : Sum of nodes on the longest path
class Solution {
public:
    // Returns {height, sum of longest path}
    pair<int,int> getHeight(Node* root) {
        if(!root) return {0, 0};
        
        pair<int,int> lh = getHeight(root->left);
        pair<int,int> rh = getHeight(root->right);
        
        int sum = root->data;
        
        if(lh.first == rh.first){
            sum += max(lh.second, rh.second);
        } else if(lh.first > rh.first){
            sum += lh.second;
        } else {
            sum += rh.second;
        }
        
        return {max(lh.first, rh.first) + 1, sum};
    }

    int sumOfLongRootToLeafPath(Node *root) {
        pair<int,int> res = getHeight(root);
        return res.second;
    }
};
