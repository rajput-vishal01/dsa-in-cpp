// Leetcode 6. Zigzag Conversion
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;

        vector<string>zigzag(numRows);

        int i=0,row=0;
        bool direction =1;

        while(true){
            if(direction){
                // Going down
                while(row<numRows && i<s.size()){
                    zigzag[row++].push_back(s[i++]);
                }
                row=numRows-2;  // Start going up from second-to-last row
            }else{
                  // Going up
                while(row>=0 && i<s.size()){
                     zigzag[row--].push_back(s[i++]);
                }
                row=1;// Start going down from second row
            }
        if(i>=s.size()) break;
        direction =!direction;
        }
        string ans="";
        for(int i=0;i<zigzag.size();i++){
           ans+=zigzag[i];
        }

        return ans;
    }

};