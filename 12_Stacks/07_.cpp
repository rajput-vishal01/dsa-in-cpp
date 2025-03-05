#include <iostream> 
#include <stack>
using namespace std; 

/*
insert elem at sorted stack
*/

void insertAtSorted(stack<int> &s, int elem) {

  if(s.empty()) {
    s.push(elem);
  }


  if (!s.empty() && s.top() < elem) {
    s.push(elem);
    return;
  }
  int topElement = s.top();
  s.pop();
  insertAtSorted(s, elem);
  s.push(topElement);
}

int main() {
   

    stack<int> s; 
    s.push(10); 
    s.push(20); 
    s.push(30); 
    s.push(40); 
    s.push(50);

    int elem =13;

    insertAtSorted(s,elem);

    //traverse    
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

   

   
  
    return 0; 
}
