#include <iostream>
#include <stack>
using namespace std; 

void insertAtMiddle(stack<int> &s, int elem, int middle) {
    if (middle == 0) { 
        s.push(elem);
        return;
    }

    int topElement = s.top();
    s.pop();

    insertAtMiddle(s, elem, middle - 1);

    s.push(topElement);
}

void insertAtMiddle(stack<int> &s, int elem) {
    int middle = s.size() / 2; 
    insertAtMiddle(s, elem, middle);
}

int main() {
    stack<int> s; 
    s.push(10); 
    s.push(20); 
    s.push(30); 
    s.push(40);
    s.push(50);

    int elem = 12;

    insertAtMiddle(s, elem);

    // Traverse    
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0; 
}
