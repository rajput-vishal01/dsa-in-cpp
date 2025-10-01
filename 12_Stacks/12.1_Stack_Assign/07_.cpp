// leetcode 394 : decode-string

class Solution {
public:
    string decodeString(string s) {
        stack<string>st;

        for(auto ch:s){
            if(ch==']'){
                //Get the char's
                string stringToRep;
                while(!st.empty() && st.top()!="["){
                    string topChar = st.top();
                    stringToRep+=topChar;
                    st.pop();
                }
                st.pop(); //pop the [ bracket seprately

                //Get the nums's
                string numberOfTimes;
                while(!st.empty() && isdigit(st.top()[0])){
                    string topNums = st.top();
                    numberOfTimes+=topNums;
                    st.pop();
                }

                //reverse the number
                reverse(numberOfTimes.begin(),numberOfTimes.end());
                int n = stoi(numberOfTimes);

                //Decode
                string currDecode;
                while(n--){
                    currDecode+=stringToRep;
                }
                st.push(currDecode);

            }else {
                string temp(1,ch);
                st.push(temp);
            }
        }
        string ans;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};