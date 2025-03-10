#include <iostream>
#include <queue>
using namespace std; 

// interleavin (mixing) the first half of the queue with the second half
void interleavinf(queue<int> &q) {
    if(q.empty())
        return;
        
    int halfSize = q.size() / 2;
    queue<int> q2;
    
   
    while(halfSize != 0) {
        int elem = q.front();
        q.pop();
        q2.push(elem);
        halfSize--;
    }
    
   
    while(!q2.empty()) {
       
        q.push(q2.front());
        q2.pop();
        
        
        q.push(q.front());
        q.pop();
    }
}

int main() {
    queue<int> q;
    
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(80);
    
    interleavinf(q);  
    
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    
    return 0; 
}
