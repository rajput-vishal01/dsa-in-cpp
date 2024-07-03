#include<iostream>
using namespace std;
/*int main()
{
	int n,i=1,count=1;
	cin>>n;
	
	while(i<=n){
		int j=1,value=i;
		while(j<=i){
			cout<<value;
			value--;
			j++;
			
		}
		cout<<endl;
		count--;
		i++;
	}
}*/

//Printing the same pattern without using value use  formula n-j+1 as did before

int main()
{
	int n,i=1,count=1;
	cin>>n;
	
	while(i<=n){
		int j=1;
		while(j<=i){
			cout<<i-j+1;
			j++;
			
		}
		cout<<endl;
		count--;
		i++;
	}
}