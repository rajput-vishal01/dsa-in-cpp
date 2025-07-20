//Print Sub Arrays

#include <iostream> 
#include <vector>
using namespace std; 

void printSubArr(vector<int>arr,int size,int start){
 if(start>=size){
  return;
 }
 for(int end=start;end<size;end++){
  //print subarr
  for(int k=start;k<=end;k++){
    cout<<arr[k]<<" ";
  }
    cout<<endl;
 }
 printSubArr(arr, size, start + 1);
}

int main() {
  vector<int> arr={1,2,3,4,5};
  int size= arr.size();
  int i=0;
  printSubArr(arr,size,i);
   
  return 0; 
}
