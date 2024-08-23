#include<iostream>
#include<deque>  // must include deque before using STL deque
using namespace std;

int main() {

    deque<int> q;  // declaring a deque
    
    //complexity of every element is O(1) except erase method as it traverse to the element 

    // adding elements to the deque
    q.push_back(7);
    q.push_front(3);
    q.push_back(5);
    q.push_front(2);

    // iterating over the deque and printing its elements
    for(int i:q) {
        cout<<i<<" ";
    }

    cout<<endl;
    cout<<endl;

    // removing an element from the back of the deque
    q.pop_back();
    for(int i:q) {
        cout<<i<<" ";
    }

    cout<<endl;
    cout<<endl;

    // removing an element from the front of the deque
    q.pop_front();
    for(int i:q) {
        cout<<i<<" ";
    }

    cout<<endl;
    cout<<endl;

    // accessing elements at specific positions in the deque
    cout<<"Print element at first index : "<<q.at(1)<<endl;
    cout<<"Print element at front index : "<<q.front()<<endl;
    cout<<"Print element at back index : "<<q.back()<<endl;

    // checking if the deque is empty or not
    cout<<"Empty or Not : "<<q.empty()<<endl;

    cout<<endl;

    // removing elements from the deque using erase function
    cout<<"before erase "<<q.size();
    cout<<endl;

    // erasing elements from the deque
    q.erase(q.begin(),q.begin()+1);
    cout<<endl;

    cout<<"after erase "<<q.size();

    // printing the elements of the deque after erasing
    for(int i:q) {
        cout<<i<<" ";
    }
    
    

}
