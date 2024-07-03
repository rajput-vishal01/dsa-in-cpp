//Prime number

#include<iostream>
using namespace std;

//1 --> Prime number
//0 --> Not a Prime number

bool isPrime(int n){
	
	for(int i=2;i<n;i++){
		if(n%i==0){
			return 0;
		}
		return 1;
	}
	
}
int main(){
	int a;
	cout<<"Enter your number :";
	cin>>a;
	
	if((isPrime(a))){
		cout<<a<<" is a prime number";
	}
	else{
		cout<<a<<" is not a prime number";
	}
	return 0;
}