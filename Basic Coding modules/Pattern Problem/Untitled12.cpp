#include<iostream>
using namespace std;
int main()
{
	int n,i=1;
	cin>>n;
	while(i<=n){
		int j=1,value=i;
		while(j<=n){
			char ch = 'A'+i-1;
			cout<<ch;
			value++;
			j++;
			
		}
		cout<<endl;
		i++;
	}
}