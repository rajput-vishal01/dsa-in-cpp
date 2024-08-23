#include<iostream>
#include<list>  // must include list before using STL
using namespace std;

int main() {
    // Declare a list
    list<int> q;

    // adding elements to the list
    q.push_back(7);
    q.push_front(3);
    q.push_back(5);
    q.push_front(2);

    // iterating over the list and printing its elements
    for(int i:q) {
        cout<<i<<" ";
    }
    cout<<endl;

    // removing elements from the list using erase function
    cout<<"before erase "<<q.size();

    // erasing elements from the deque
    q.erase(q.begin()); // only erases the element to which it is pointing
    cout<<endl;

    cout<<"after erase "<<q.size();
    cout<<"Empty or Not : "<<q.empty()<<endl;
}
