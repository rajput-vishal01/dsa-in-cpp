#include<iostream>
using namespace std;

int isEven(int a){
	if(a&1){
		return 0;
	}
	else{
		return 1;
	}
}

int main(){
	int num;
	cin>>num;
	isEven(num);
	
	if((isEven(num))){
		cout<<num<<" is even Number"<<endl;
	}
	else{
		cout<<num<<" is odd Number"<<endl;
	}
	
}