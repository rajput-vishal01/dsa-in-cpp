//Linear Search
#include<iostream>
using namespace std;

bool search( int arr[],int size,int key){
	for(int i=0 ; i<size ; i++){
		if(arr[i]==key){
			return 1;
		}
		return 0;	
	}
}
int main(){
	
	int size;
	int key;
	cout<<"Enter the size of array :";
	cin>>size;
	int num[100];
	cout<<"Enter the elements in array :";
	for(int i=0;i<size;i++)
	{
        cin>>num[i];
	}
	
	cout<<"Enter the element you want to search :";
	cin>>key;
	if(search(num,size,key)){
		cout<<"Element is present";
	}
	else{
		cout<<"Element is Absent";
	}
	return 0;
}