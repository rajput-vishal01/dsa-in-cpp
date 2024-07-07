//Binary Search

#include<iostream>
using namespace std;

int binarySearch(int arr[],int size,int key){
	int start = 0;
	int end=size-1;
	
	int mid = start+(end-start)/2;
	 
	while(start<=end){
		if(arr[mid]==key){
			return mid;
		}
		//Go to start Part
		if(key>arr[mid]){
			start=mid+1;
		}
		else{
			end=mid-1;
		}
		
	 mid = start+(end-start)/2;
	}
	return -1;
}
int main(){
	
	int even[6]={2,23,45,66,99,204};
	int odd[5] ={12,45,66,78,92};
	
	
	int Evenindex = binarySearch(even,6,12);	
	cout<<"index of key is "<<Evenindex<<endl;
	
	int Oddindex = binarySearch(odd,5,12);	
	cout<<"index of key is "<<Oddindex<<endl;
	
	return 0;
}