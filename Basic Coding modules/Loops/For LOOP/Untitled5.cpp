//Prime Number
#include<iostream>

/*using namespace std;
int main(){
	int n;;
	cout<<"Enter the value :"<<endl;
	cin>>n;
	
	for(int i=2;i<n;i++){
		if(n%i==0){
			cout<<n<<" is not a prime number";
		}
		else{
			cout<<n<<" is a prime number";
		}
		return 0;
	}
}*/


//Faster way {In this Method we are not dividing n with every number ek baar 0 agya to break
using namespace std;
int main(){
	int n;;
	cout<<"Enter the value :"<<endl;
	cin>>n;
	int IsPrime=1;
	for(int i=2;i<n;i++){
		if(n%i==0){
			int isPrime=0;
			break;
		}
	 
	 if(IsPrime==0){
			cout<<n<<" is not a prime number";
		}
		else{
			cout<<n<<" is a prime number";
		}
		return 0;
	}
}

