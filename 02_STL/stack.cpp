#include<iostream>
#include<stack>  // must include stack before using STL
using namespace std;

int main() {
    // Declare a stack of strings
    stack<string> s;

    // Pushing elements onto the stack
    s.push("vishal");
    s.push("kumar");
    s.push("rajput");

    // Printing the top element of the stack
    cout<<"Top element: "<<s.top()<<endl;

    // Popping an element from the stack
    s.pop();

    // Printing the new top element of the stack
    cout<<"Top element: "<<s.top()<<endl;

    // Getting the size of the stack
    cout<<"Size of stack: "<<s.size()<<endl;

    // Checking if the stack is empty or not
    cout<<"Empty or Not: "<<s.empty()<<endl;
}
