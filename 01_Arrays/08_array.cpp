//Sum of elements in an array
#include<iostream>
using namespace std;

int sum( int arr[],int size){
	int sum=0;
	for(int i=0 ; i<size ; i++){
		sum=sum + arr[i];
	}
	return sum;
}
int main(){
	
	int size;
	cout<<"Enter the size of array :";
	cin>>size;
	int num[100];
	cout<<"Enter the elements in array :";
	for(int i=0;i<size;i++)
	{
        cin>>num[i];
	}
	
	cout<<"Sum of all the elements in the array is : "<<sum(num,size);
	
	return 0;
}