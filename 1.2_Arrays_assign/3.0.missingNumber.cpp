// Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

#include <iostream> 
#include <algorithm> //for sort() function
using namespace std; 

int missingNum(int arr[], int n) {
  
  sort(arr, arr+n);
  
  for (int i = 0; i < n; i++) {
    if (arr[i]!= i)
     cout<<i<<" is missing"<<endl;
  }

}


int main() {
   
    int arr[9]={9,6,4,2,3,5,7,0,1};
    int n= 9;

    missingNum(arr, n);
    return 0; 
}
