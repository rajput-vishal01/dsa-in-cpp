//leetcode 71 : simplify-path

class Solution {
public:
    void buildAns(stack<string>&st,string &ans){
        if(st.empty()) return;

        string minPath = st.top(); st.pop(); // take top dir
        buildAns(st,ans);                    // build remaining
        ans += "/" + minPath;                // add path part
    }

    string simplifyPath(string path) {
        stack<string>st;
        int i = 0;

        while(i < path.size()){
            int start = i + 1;               // skip '/'
            int end = i + 1;

            while(end < path.size() && path[end] != '/'){
                ++end;
            }

            string minPath = path.substr(start,end-start);
            i = end;

            if(minPath == "" || minPath == ".") continue;

            if(minPath != ".."){
                st.push(minPath);            // valid dir
            } else if(!st.empty()){
                st.pop();                    // go back
            }
        }

        string ans = st.empty() ? "/" : "";
        buildAns(st,ans);
        return ans;
    }
};
