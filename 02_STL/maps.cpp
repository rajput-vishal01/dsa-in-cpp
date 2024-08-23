#include<iostream>
#include<map>  // Include the map header to use STL map
using namespace std;

int main() {
	// Declare a map with integer keys and string values
	map<int,string> s;

	// Insert key-value pairs into the map
	s[1] = "love";
	s[9] = "3rd ";
	s[2] = "babbar";
	s[15] = "kumar";
	s.insert({5, "Bheem"});

	// Iterate through the map and print each key-value pair
	for(auto i : s) {
		cout << i.first << " " << i.second << endl;
	}

	// Check if a key exists in the map and print the result
	cout << "Finding 13 --->" << s.count(13) << endl;

	cout << endl;
	cout << "Before Erase" << endl;
	cout << endl;
	for(auto i : s) {
		cout << i.first << " " << i.second << endl;
	}

	// Erase an element from the map
	s.erase(15);

	cout << endl;
	cout << "After Erase" << endl;
	for(auto i : s) {
		cout << i.first << " " << i.second << endl;
	}

	cout << endl;
	cout << endl;

	// Find an element in the map and print all elements after it
	auto it = s.find(5);
	for(auto i = it; i != s.end(); i++) {
		cout << (*i).first << endl;
	}

	return 0;
}
