// GFG : Stream First Non-repeating


class Solution {
  public:
    string firstNonRepeating(string &s) {
        unordered_map<char,int> freq;
        string ans="";
         queue<char> q;
       
        for(int i=0;i<s.size();i++){
            char ch = s[i];
            freq[ch]++;
           
            q.push(ch);
           
            while(!q.empty()){
                char frontElem = q.front();
               
                if(freq[frontElem]==1){
                    ans.push_back(frontElem);
                    break;
                }
                else{
                    q.pop();
                }
            }
            if(q.empty()){
          ans.push_back('#');
        }
        }
        return ans;
    }
};
