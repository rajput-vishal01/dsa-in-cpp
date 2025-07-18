// Leetcode : 179. Largest Number

class Solution {
public:
        static bool mycomp(string a,string b){
            string t1=a+b;
            string t2=b+a;
            return t1>t2;
        }
    string largestNumber(vector<int>& nums) {
        
        //if sorted the nums and then putted into str then the issue is largest elem (two digit) creates the issue. 
        //if first pushed in string arr and then putted into ans -- string lexical sorting which is perfect for this case but
         
        // static bool mycomp(string a,string b){
        //     return a>b
        // } creates issue:while using custom comparator only with two digits 
        
        vector<string>sNums;
        for(auto i:nums){
            sNums.push_back(to_string(i));
        }
        sort(sNums.begin(),sNums.end(),mycomp);

       if(sNums[0]=="0") return "0";

        string ans="";
        for(auto i:sNums){
            ans+=i;
        }

        return ans;
    }
};