#include<iostream>
#include<vector>//must include array befor using stl array
using namespace std;

int main() {

	vector<int>v;
	
	
	//every thing is done at 0(1) complexity
	
	cout<<"capacity at start "<<v.capacity()<<endl; // Initial capacity of the vector

	v.push_back(1);
	cout<<"capacity after adding 1st element "<<v.capacity()<<endl; // Capacity after adding the first element

	v.push_back(2);
	cout<<"capacity after adding 2nd element "<<v.capacity()<<endl; // Capacity after adding the second element

	v.push_back(3);
	cout<<"capacity after adding 3rd element "<<v.capacity()<<endl; // Capacity after adding the third element
	cout<<"size of vector "<<v.size()<<endl ; // Size of the vector (number of elements)

	cout<<endl;
	cout<<endl;

	cout<<"element in vector at index 2 :"<<v.at(2)<<endl;// Returns element at index 2
	cout<<"array is empty or not :"<<v.empty()<<endl; // Returns true if the array is empty, false otherwise
	cout<<"array's first element :"<<v.front()<<endl; // Returns the first element of the array
	cout<<"array's last element :"<<v.back()<<endl; // Returns the last element of the array

	cout<<endl;
	cout<<endl;

	cout << "BEGIN ELEMENT: " << *v.begin() << endl; // Value of the first element using iterators
	cout << "BEGIN ITERATOR ADDRESS: " << &(*v.begin()) << endl; // Address of the iterator pointing to the first element

	cout << "END ELEMENT: " << *(v.end() - 1) << endl; // Value of the last element using iterators
	cout << "END ITERATOR ADDRESS: " << &(*(v.end() - 1)) << endl; // Address of the iterator pointing to the last element

	cout<<endl;
	cout<<endl;

	// Popping the last element
	cout<<"before pop"<<endl;
	for(int i:v) {
		cout<<i<<" ";
	}

	v.pop_back(); // Popping the last element
	cout<<endl;

	cout<<"after pop"<<endl;
	for(int i:v) {
		cout<<i<<" ";
	}

	cout<<endl;
	cout<<endl;

	// Clearing the vector
	cout<<"before clear size "<<v.size()<<endl; // Size of the vector before clearing
	v.clear();
	cout<<endl;
	cout<<"after clear size "<<v.size()<<endl; // Size of the vector after clearing
	cout<<"after clearing size items are"<<endl;
	for(int i:v) {
		cout<<i<<" "; // All the elements are deleted
	}
	
	cout<<endl;
	cout<<endl;
	
	vector<int>c(5,1); //vector with known capacity 5 and all the elements are initialzed at 1 as by default its 0
	cout<<"Elements of c vector ";
	for(int i:c) {
		cout<<i<<" "; // All the elements are deleted
	}
	
	cout<<endl;
	cout<<endl;
	
	//copying a vector
	vector<int>last(c);
	cout<<"elements in last vector";
	for(int i:last) {
		cout<<i<<" "; // All the elements are copied
	}
	

}
