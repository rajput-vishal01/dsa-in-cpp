#include <iostream>
#include<vector> 
using namespace std; 

// all pair addition
// int twoSum_(vector<int> arr){
//     int n=arr.size();

//     for(int i=0;i<n;i++){
//         for(int j=i;j<n;j++){
//             cout<<"sum of "<<arr[i]<<" "<<arr[j]<<" is = "<<arr[i]+arr[j]<<endl;
//         }
//     }
// }


int twoSum_(vector<int> arr, int target) {
    int n = arr.size();
    bool found = false;

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) { 
            if(arr[i] + arr[j] == target) {
                cout << "Target element is present" << endl;
                found = true;
                break; 
            }
        }
        if(found) break;
    }
    if(!found) {
        cout << "Element is absent" << endl;
    }
    return 0; 
}

int main() {
    vector<int> arr = {10, 20, 30, 40, 50};
    int target = 80;

    twoSum_(arr, target);

    return 0;
}
