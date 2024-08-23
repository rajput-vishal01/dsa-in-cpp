#include<iostream>
#include<queue>  // must include queue before using STL
using namespace std;

int main() {
    // Declare a queue of strings
    queue<string> s;

    // Pushing elements into the queue
    s.push("vishal");
    s.push("kumar");
    s.push("rajput");

    // Printing the front element of the queue
    cout<<"Front element: "<<s.front()<<endl;

    // Popping an element from the queue
    s.pop();

    // Printing the new front element of the queue
    cout<<"Front element: "<<s.front()<<endl;

    // Getting the size of the queue
    cout<<"Size of queue: "<<s.size()<<endl;

    // Checking if the queue is empty or not
    cout<<"Empty or Not: "<<s.empty()<<endl;
}
