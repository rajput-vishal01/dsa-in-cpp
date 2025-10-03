//  Implement Stack using Queues
#include <bits/stdc++.h>
using namespace std;

class MyStack {
public:
    queue<int>q1,q2;

    void push(int x) {
        // step 1: push new element into q2
        q2.push(x);

        // step 2: move all elements of q1 into q2
        // this ensures new element will be at front of q1
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }

        // step 3: swap q1 and q2
        // now q1 has the correct order (stack top at q1.front())
        swap(q1,q2);
    }

    int pop() {
        // pop from q1 since q1.front() is the top of stack
        if(q1.empty()) return -1;
        int elem=q1.front();
        q1.pop();
        return elem;
    }

    int top() {
        // return the front of q1 (which is the stack's top element)
        if(q1.empty()) return -1;
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};


// leetcode 225 : Implement Stack using Queues
//using single queue
class MyStack {
public:
    queue<int>q;
    MyStack() {
        
    }
    
    void push(int x) {
        // push new element at the back
        q.push(x);

        // rotate the queue to bring the new element to the front
        // this ensures LIFO behavior (stack top always at front)
        for(int i=0;i<q.size()-1;i++){
            int topElem = q.front();
            q.pop();
            q.push(topElem);
        }
    }
    
    int pop() {
        // front always holds the stack's top element
        int topElem = q.front();
        q.pop();
        return topElem;
    }
    
    int top() {
        // return the current top element (front of queue)
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};
