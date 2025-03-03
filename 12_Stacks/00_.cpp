#include <iostream> 
using namespace std; 

/*

Using LInked List :abort
--Operation of inserting at head in a doubly linked list will act as a stack.
--And there head will act as a top. and deletion will act as a pop operation.
*/


class Stack{
  public:
  int *arr;
  int top;
  int size;
  public:
  Stack(int size){
    this->size = size;
    arr = new int[size];
    top = -1;
  }

  void push(int element){
    if(top == size-1){
      cout<<"Stack Overflow"<<endl;
      return;
    }
    top++;
    arr[top] = element;
  }

  void pop(){
    if(top == -1){
      cout<<"Stack Underflow"<<endl;
      return;
    }
    arr[top] = -1; // not mandatory to do
    top--;
  }

  int getSize(){
    return top+1;
  }


  bool isEmpty(){
   if(top == -1){
     return true;
   }
   return false;  
  }


  int getTop(){
    if(top == -1){
      cout<<"Stack Underflow"<<endl;
      return -1;
    }
    return arr[top];
  }

};


int main() {
   
    Stack st(5);
    st.push(10);
    st.push(20);
    st.push(30);
    cout<<st.getTop()<<endl;
    st.pop();
    cout<<st.getTop()<<endl;
    cout<<st.getSize()<<endl;
    cout<<st.isEmpty()<<endl; 
  
    return 0; 
}
