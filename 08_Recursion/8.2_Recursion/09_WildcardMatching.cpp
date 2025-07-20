//Leetcode 44. Wildcard Matching -- HARD

// Memory Limit Exceeded -> as recursion soln

class Solution {
public:
    
    bool isMatchHelper(string s,int si ,string p,int pi){
     //base
     if(si==s.size() && pi==p.size()) return true;

    if(si==s.size() && pi<p.size()){
        while(pi<p.size()){
            if(p[pi]!='*') return false;
            pi++;
        }
        return true;
    }
    
     if(pi==p.size() && si<s.size()) return false;

     //single char
     if(s[si]==p[pi] || '?'==p[pi]){
        return isMatchHelper(s,si+1,p,pi+1);
     }
     if(p[pi]=='*'){
        //* is empty or null
       bool caseA = isMatchHelper(s,si,p,pi+1);
       //* consume 1 char
       bool caseB = isMatchHelper(s,si+1,p,pi);
       return caseA||caseB;
     }
     //char doesnt match
     return false;
    }

    bool isMatch(string s, string p) {
        int si=0;
        int pi=0;

        return isMatchHelper(s,si,p,pi);
    }
};