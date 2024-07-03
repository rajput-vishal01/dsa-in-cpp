#include<iostream>
using namespace std;
int main()
{
	int n,i=1;
	char ch='A';
	cin>>n;
	while(i<=n){
		int j=1,value=i;
		while(j<=n){
			cout<<ch;
			ch++;
			value++;
			j++;
			
		}
		cout<<endl;
		i++;
	}
}