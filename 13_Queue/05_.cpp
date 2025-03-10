#include <iostream> 
#include <queue>
#include <stack>
using namespace std; 

// Reverse a queue
//T.C = O(n) S.C = O(n){as stack is being used}
// void reverseQueue(queue<int> &q) {
//   stack<int> st;

//   while (!q.empty()) {
//     int elem = q.front();
//     q.pop();
//     st.push(elem);
//   }

//   // Now pop from stack and push back into queue
//   while (!st.empty()) {
//     int elem = st.top();  
//     st.pop();
//     q.push(elem);
//   }
// }


void reverseQueueRecurr(queue<int> &q) {
  if (q.empty()) {
    return;
  }

  int elem = q.front();
  q.pop();
  reverseQueueRecurr(q);
  q.push(elem);
}

int main() {
  queue<int> q;
  q.push(10); 
  q.push(20); 
  q.push(30); 
  q.push(40); 
  q.push(50); 

  // reverseQueue(q);

  reverseQueueRecurr(q);

  while (!q.empty()) {
    cout << q.front() << " ";
    q.pop();    
  }

  return 0; 
}
