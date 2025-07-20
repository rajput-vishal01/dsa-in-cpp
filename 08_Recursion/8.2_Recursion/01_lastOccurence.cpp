//last occourence of a elem

/*
methods:

1.m1: traverse left to right and return the last occurence after continuously updating the elem
2.m2: traverse right to left and return the first occurence of the elem
3.m3: stl fn: strrchar()

*/

#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std; 

int m3LastOcc(vector<string>&arr,string elem) {
    auto it = find(arr.rbegin(), arr.rend(), elem);
    if (it!=arr.rend()) {
        // Convert reverse iterator to normal index
        return arr.rend()-it-1;
    }
    
    return -1;
}

int m2LastOcc(vector<string> arr,int size,string elem,int i){
  if(i<0){
  return -1;
 }
 
  if(arr[i]==elem) {
   return i;
 }
 return m2LastOcc(arr, size, elem, i-1);
}

int m1LastOcc(vector<string> &arr,int size,string elem,int i){
 if(i>=size){
  return -1;
 }
 int ans=m1LastOcc(arr,size,elem,i+1);

 if(ans!=-1) return ans;

 if(arr[i]==elem) return i;
 
 return -1;
}

int main() {
  vector<string> arr={"a","b","b","b","a","e","f","d","b","a"};
  // int size=arr.size();
  // int index=0;  // for m1
  // int index=arr.size(); //for m2
  string elem="b";
  // int result = m1LastOcc(arr,size,elem,index);
  // int result = m2LastOcc(arr,size,elem,index);
  int result=m3LastOcc(arr,elem);
  cout<<result;
  
    return 0; 
}
