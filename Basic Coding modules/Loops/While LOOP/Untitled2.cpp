//Sum of 1 to N (Even Numbers)
#include<iostream>
using namespace std;

int main() {
    int n, Sum = 0;
    cout << "Enter the value of N: ";
    cin >> n;
    int i = 2; // Starting from 2 as we want to sum even numbers
    while (i <= n) {
        Sum = Sum + i;
        i = i + 2; // Increment by 2 to get the next even number
    }
    cout << "Total sum of even numbers from 1 to " << n << " is: " << Sum << endl;
    return 0;
}
