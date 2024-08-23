#include<iostream>
#include<array>//must include array befor using stl array
using namespace std;

int main(){
	
	int basic[3]={1,2,3};
	
	
	array<int,5>a={1,2,3,4}; //defining stl array
	a.push(5);
	
	int size=a.size();
	
	for(int i=0;i<size;i++){
		cout<<a[i]<<" " ;
	}
	//every thing is done at 0(1) complexity
	cout<<"element in array at index 2 :"<<a.at(2)<<endl;//returns element 
	cout<<"array is empty or not :"<<a.empty()<<endl; //returns bool
	cout<<"array's first element :"<<a.front()<<endl; //returns first element
	cout<<"array's last element :"<<a.back()<<endl; //returns last element

}