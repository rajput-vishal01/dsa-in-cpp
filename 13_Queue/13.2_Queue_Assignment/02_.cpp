// Implement Queue using Stacks two Ways:
//1. Push costly (O(n)), Pop O(1)
//2. Pop costly (O(n)), Push O(1)

//232. Implement Queue using Stacks
class MyQueue {
public:
    stack<int>s1,s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
        
    }
    
    int pop() {
        int popElem=-1;
        if(!s2.empty()){
            popElem=s2.top();
            s2.pop();
        }else{
            while(!s1.empty()){
                int s1TopElem=s1.top();
                s2.push(s1TopElem);
                s1.pop();
            }
            popElem=s2.top();
            s2.pop();
        }
        return popElem;
    }
    
    int peek() {
        int peekElem=-1;
        if(!s2.empty()){
            peekElem=s2.top();
        }else{
            while(!s1.empty()){
                int s1TopElem=s1.top();
                s2.push(s1TopElem);
                s1.pop();
            }
            peekElem=s2.top();
        }
        return peekElem;
        
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};
