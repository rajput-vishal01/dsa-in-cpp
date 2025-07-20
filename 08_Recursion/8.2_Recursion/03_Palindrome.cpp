// check_Palindrome

#include <iostream> 
using namespace std; 

bool check_Palindrome(string str,int size,int i,int j){
  if(i>=j){
    return true;
  }
  
  if(str[i]!=str[j]){
    return false;
  }
  return check_Palindrome(str,size,i+1,j-1);
}


int main() {
  string str ="racecar";
  int size = str.size();
  int i=0;
  int j=size-1;
  bool result=check_Palindrome(str,size,i,j);
  cout<<result;

  
  return 0; 
}
