#include<iostream>
using namespace std;
int main(){
	int a,b;
	cout<<"Enter the value of A and B :";
	cin>>a>>b;
	
	cout<<" Bitwise AND of A and B are :"<<(a&b)<<endl;
	cout<<" Bitwise OR of A and B are  :"<<(a|b)<<endl;
	cout<<" Bitwise XOR of A and B are :"<<(a^b)<<endl;
	cout<<" Bitwise Complement of A is :"<<(~a)<<endl;
	cout<<" Bitwise Complement of B is :"<<(~b)<<endl;
	cout<<" Bitwise Left Shift of A is :"<<(a<<1)<<endl;
	cout<<" Bitwise Left Shift of B is :"<<(b<<1)<<endl;
	cout<<" Bitwise Right Shift of A is:"<<(a>>1)<<endl;
	cout<<" Bitwise Right Shift of B is:"<<(b>>1)<<endl;
	return 0;
}