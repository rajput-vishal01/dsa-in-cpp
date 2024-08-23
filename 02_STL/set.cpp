#include<iostream>
#include<set>  // must include set before using STL
using namespace std;

int main() {

	set<int>s;
  //complexity of insert operation is O(n) as binary insertion is happning
	s.insert(5);
	s.insert(5);
	s.insert(5);
	s.insert(5);
	s.insert(6);
	s.insert(7);
	s.insert(9);
	s.insert(9);
	s.insert(1);
	s.insert(11);
	s.insert(2);
	
	for(auto i:s){
		cout<<i<<" ";
	}
	
	//with this only we can delete the element first storing the iterator and then inrementing it as we can not directly access the index
	set<int>::iterator it=s.begin();
	it++;
	s.erase(it); 
	
	
	cout<<endl;
	
	
	for(auto i:s){
		cout<<i<<" ";
	}
	
	cout<<endl;
	
	cout<<"5 is present"<<s.count(5)<<endl;
	cout<<"2 is present"<<s.count(2)<<endl; //as we deleted it
	
	set<int>::iterator itr=s.find(5);
	cout<<"5 is present at index "<<*itr<<endl;

}
