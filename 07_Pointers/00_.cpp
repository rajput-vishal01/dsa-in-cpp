#include <iostream> 
using namespace std; 

int main() {
   
   int a =5;
  //  int c = &a; //error as can not store memory address in int  
  int *ptr = &a; //pointer to an int
  int &b = a; //(reference variable)
   cout << a << endl;
   cout << &a << endl;
   cout << &b << endl; //(address of the reference variable)
   
   // Demonstrate the difference between pointer and reference variables
   cout << "Difference between pointer and reference variables:" << endl;
   cout << "Value of a: " << a << endl;


   cout << ptr << endl;
   cout << *ptr << endl; //(value at address) dereferencing the pointer to get the value of the variable
  
   cout<<sizeof(ptr) << endl;
 //for every datatype size of ptr should be 8bit (for 64bit PC's).But that is not
 //guaranteed sometimes its because of arichitectural differences
 //for me -- its 4 bit only (mine is also 64bit pc WTF)

   *ptr = 10; // changing the value of the variable using the pointer
   cout << a << endl; // output: 10

  
 int *p ;
 cout <<*p<<endl; // output may vary but its a bad practice
 //should be segmentation fault but for me its working

    return 0; 
}
