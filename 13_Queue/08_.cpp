#include <iostream>
#include <deque>
#include <queue>
#include <vector>
using namespace std;

//sliding window
/*
step 1; process first window
step 2: process remaining window-> ans/removal/addition
*/

queue<int> firstNegativeInWindow(const vector<int>& arr, int k) {
    deque<int> dq;
    queue<int> result;
    int n = arr.size();

    //processing the first window
    for (int i = 0; i < k; i++) {
        if (arr[i] < 0)
            dq.push_back(i);
    }

    // process remaining window-> ans/removal/addition
    for (int i = k; i < n; i++) {
        if (!dq.empty())
            {result.push(arr[dq.front()]);}
        else
           { result.push(0);}
        while (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();
        if (arr[i] < 0)
            dq.push_back(i);
    }
    if (!dq.empty())
        result.push(arr[dq.front()]);
    else
       { result.push(0);}
    return result;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    queue<int> ans = firstNegativeInWindow(arr, k);
    while (!ans.empty()){
        cout << ans.front() << " ";
        ans.pop();
    }
    cout << endl;
    return 0;
}
