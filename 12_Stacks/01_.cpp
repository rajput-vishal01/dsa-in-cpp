/*
Implementation of 2 stacks using 1 array

Approch 1: divide array in 2 parts and have two top one on bottom and one on middle -- Memory wasteage

Approch 2: In a single array keep one top(for push increment it & for pop viceversa) at bottom and on top(for push decrement it & for pop viceversa) at end or the array.
*/

#include<iostream>
using namespace std;

class stack{
  public:
  int *arr;
  int top1;
  int top2;
  int size;

  stack(int size){
    this->size = size;  
    arr = new int[size];
    top1 = -1;
    top2 = size;
  }

  void push1(int element){
    if(top1 == top2-1){
      cout<<"Stack Overflow"<<endl;
      return;
    }
    top1++;
    arr[top1] = element;
  }

  void push2(int element){
    if(top1 == top2-1){
      cout<<"Stack Overflow"<<endl;
      return;
    }
    top2--;
    arr[top2] = element;  
  }

  void pop1(){
    if(top1 == -1){
      cout<<"Stack Underflow"<<endl;
      return;
    }
    arr[top1] = -1; // not mandatory to do
    top1--;  
  }

  void pop2(){
    if(top2 == size){
      cout<<"Stack Underflow"<<endl;
      return;
    }
    arr[top2] = -1; // not mandatory to do
    top2++;  
  }


void  print(){
    for(int i = 0; i < size; i++){
      cout<<arr[i]<<" ";
    }
    cout<<endl;
  }

};

int main(){

  stack st(10);

  st.push1(10);
  st.push1(20);
  st.push1(30); 

  st.push2(100);  
  st.push2(200);
  st.push2(300);
  
  st.print();

  st.pop1();
  st.pop2();

  st.print();

  return 0;
}