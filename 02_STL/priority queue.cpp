#include<iostream>
#include<queue>  // must include queue before using STL
using namespace std;

int main() {
    // max heap
    priority_queue<int> maxi;
  
    // Inserting elements into the max heap
    maxi.push(7);
    maxi.push(3);
    maxi.push(5);
    maxi.push(2);
    
    // Printing elements of the max heap in decreasing order
    int n = maxi.size();
    for(int i = 0; i < n; i++) {
        cout << maxi.top() << " ";
        maxi.pop();
    }
    cout << "Size of max heap: " << maxi.size() << endl;
  
    // min heap
    priority_queue<int, vector<int>, greater<int>> mini;
  
    // Inserting elements into the min heap
    mini.push(7);
    mini.push(3);
    mini.push(5);
    mini.push(2);
    
    // Printing elements of the min heap in increasing order
    int k = mini.size();
    for(int i = 0; i < k; i++) {
        cout << mini.top() << " ";
        mini.pop();
    }
    cout << "Size of min heap: " << mini.size() << endl;
}
