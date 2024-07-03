#include<iostream>
#include<cmath>
using namespace std;

 int decimalToBinaryNoMethod1(int n){
  //division method
  int binaryno=0;
  int i=0;
  while(n>0){
    int bit = n % 2;
    binaryno=bit*pow(10,i++)+binaryno;
    n = n/2;
  }
  return binaryno;
}

 int decimalToBinaryNoMethod2(int n){
  //bitwise method
  int binaryno=0;
  int i=0;
  while(n>0){
    int bit = (n & 1);
    binaryno=bit*pow(10,i++)+binaryno;
    n = n>>1;
  }
  return binaryno;
}

int binaryToDecimalNoMethod(int n){
	int decimal=0;
	int i=0;
	while(n){
		int bit = n % 10;
		decimal=decimal+bit*pow(2,i++);
		n=n/10;	
	}
	return decimal;
}

int main(){

 /* int n;
  cout<<"Enter the no you want to convert : ";
  cin>>n;
  int binary=decimalToBinaryNoMethod1(n);
  int binary2=decimalToBinaryNoMethod2(n);
  cout<<binary<<endl;
  cout<<binary2<<endl;
  return 0; */
  
  
  int binaryno;
  cout<<"enter binary no.";
  cin>>binaryno;
   int number=binaryToDecimalNoMethod(binaryno);
  cout<<number;
  return 0;
  

}