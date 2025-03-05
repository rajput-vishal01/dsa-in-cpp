#include <iostream>
#include <stack>
using namespace std;


void insertAtBottom(stack<int>& s, int elem) {
    if (s.empty()) {
        s.push(elem);
        return;
    }
    int topElement = s.top();
    s.pop();
    insertAtBottom(s, elem);
    s.push(topElement);
}


void reverseStack(stack<int>& s) {
    if (s.empty()) {
        return;
    } 
    int topElement = s.top();
    s.pop();
    reverseStack(s); //empty ho jayega stack
    insertAtBottom(s, topElement); //and then ulta insert ho jayega
}

int main() {
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    reverseStack(s);

   
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}
