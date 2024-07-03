#include<iostream>
using namespace std;
int main(){
	int n;
	cout<<"Choose an option to perform : "<<endl;
	cout<<"1. Addition \t \t 2.Subtraction \t \t 3.Multiplication"<<endl;
	cin>>n;
	int a,b;
	
	switch(n){
		case 1:
			cout<<"Enter the Value of A and B"<<endl;
			cin>>a>>b;
			cout<<a+b<<endl;
			break;
			case 2:
			cout<<"Enter the Value of A and B"<<endl;
			cin>>a>>b;
			cout<<a-b<<endl;
			break;
			case 3:
			cout<<"Enter the Value of A and B"<<endl;
			cin>>a>>b;
			cout<<a*b<<endl;
			break;
			
			default:
				cout<<"Only press between 1 to 3 ";
	}
	return 0;
}