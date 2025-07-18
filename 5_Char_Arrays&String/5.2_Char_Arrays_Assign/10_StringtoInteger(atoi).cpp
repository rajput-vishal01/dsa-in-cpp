//Leetcode 8. String to Integer (atoi)
class Solution {
public:
    int myAtoi(string s) {
        long long num=0;
        int sign=1;
        int i=0;
        while(s[i]==' '){
            i++;
        }
       
       if(i<s.size() && s[i]=='-' || s[i]=='+' ){
        sign = (s[i]=='-')?-1:1;
        i++;
       }

        while(i<s.size() && isdigit(s[i])){

            num = num * 10 + (s[i]-'0');

            if(num * sign > INT_MAX) return INT_MAX;
            if(num * sign < INT_MIN) return INT_MIN;

            i++;
        }
    return num*sign;
    }

};