//Given Number is Prime or not
#include<iostream>
using namespace std;
int main(){
	int n;
	cout<<"Enter the Number"<<endl;
	cin>>n;
	int i=2;
	while(i<n){
		if(n%i==0){
			cout<<"Not Prime for "<<i<<endl;
		}
		else{
			cout<<"Is Prime for "<<i<<endl;
		}
		i++;
	}
	return 0;
}