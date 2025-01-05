#include<iostream>
#include<vector>
using namespace std;

//ques: why arrays are passed by reference in fn 
//-refer the png img for more clear understanding
// void solve(int* arr // OR int arr[], int size) {
//     cout << sizeof(arr) << endl;
// }
//why output = 8
//Because when arrays are passed in a fn.Arrays are passed as a pointer.




// void solve(vector<int> &v) {
//     cout << sizeof(v) << endl;
// } //vector is passed as value if & not added

int main() {

    int a = 50;
    int* p = &a;
    int** q = &p;
    int** r = q;

    cout << **r << endl;




    // vector<int> v;
    // v.push_back(10);
    // v.push_back(20);
    // v.push_back(30);
    // solve(v);

    // int arr[] = {10,20,30,40,50};
    // int size = 5;
    
    // solve(arr,size);




    return 0;
}