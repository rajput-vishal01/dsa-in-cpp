//Leetcode 1910. Remove All Occurrences of a Substring

class Solution {
public:
    void removeOccurrencesRE(string &s, string &part) {
        int found = s.find(part);
        if(found != string::npos){
            string leftStr = s.substr(0,found);
            string rightStr = s.substr(found+part.size(),s.size());
            s=leftStr+rightStr;

            removeOccurrencesRE(s,part);
        }else{
            //base case
            //as no part found
            return;
        }
    }

    string removeOccurrences(string s, string part) {
        removeOccurrencesRE(s,part);
        return s;
    }
};