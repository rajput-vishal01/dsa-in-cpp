//Reverse A String using RE

#include <iostream> 
using namespace std; 

//in place
string reverseStr2(string &str,int size,int i,int j){
 if(i>j){
  return str;
 }

 swap(str[i],str[j]);
 return reverseStr2(str,size,i+1,j-1);

}

string reverseStr(string str,int size,int index,string &ans){

  if(index<0){
    return ans;
  }

  ans.push_back(str[index]);  
  return reverseStr(str,size,index-1,ans);

}

int main() {
   string s="https://askvishal.in";
   int size=s.size();
  //  int index=s.size()-1;
  //  string ans;
  //  string result=reverseStr(s,size,index,ans);
  int i=0;
  int j=size-1;
  string result=reverseStr2(s,size,i,j);
  cout<<result;
  return 0; 
}
