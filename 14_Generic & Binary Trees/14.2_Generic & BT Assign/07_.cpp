// GFG : Diagonal Tree Traversal

//first way:

class Solution {
  public:
  
    void solve(Node *root,int d,map<int, vector<int>> &mp){
        if(!root) return;
        
        //map:d->rootData
        mp[d].push_back(root->data);
        
        //left call
        solve(root->left,d+1,mp);
        //right call
        solve(root->right, d, mp);
    }
    
    vector<int> diagonal(Node *root) {
        map<int, vector<int>> mp;
        vector<int>ans;
        
        solve(root,0,mp);
        
        for(auto &it:mp){
            for(int val:it.second){
                ans.push_back(val);
            }
        }
        
        return ans;
    }
};

//more effective way
class Solution {
  public:
    vector<int> diagonal(Node *root) {
        vector<int> ans;
        if(!root) return ans;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            Node* temp = q.front(); 
            q.pop();
            while(temp){
                ans.push_back(temp->data);
                if(temp->left){
                    q.push(temp->left);
                }
                temp = temp->right;
            }
        }
        return ans;
    }
};
