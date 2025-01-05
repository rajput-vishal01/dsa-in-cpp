//Pointer with arrays

#include <iostream> 
using namespace std; 

int main() {
   
   int arr[4]={0,1,2,3};
   int *ptr = arr;

  //  arr=arr+1; //arr is not a modifiable value(read article present in folder)
  //  ptr=ptr+1; // ptr is a modifiable value
  //  cout<<ptr<<endl;
   cout<<arr<<endl;
   cout <<ptr << endl;

 //travsering array with pointer
 for(int i=0; i<4; i++) {
   cout << *(ptr+i) << " ";
 }
  
  //Pointer with char arrays
 cout<<endl;
 char ch[100]="vishalrajput";
 cout<<"base address :"<<&ch<<endl;
 char *ptr1 = ch;
 cout <<ch<<endl;
 cout <<ptr1 << endl; //if it was normal array it would have printed the address(Implementation is different)






    return 0; 
}
