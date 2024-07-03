#include<iostream>
using namespace std;

int main() {
    // Declare variables
    int n, Sum = 0;

    // Prompt user to enter the value of N
    cout << "Enter the value of N: ";
    cin >> n;

    // Initialize loop counter
    int i = 1;

    // Loop to calculate the sum of numbers from 1 to N
    while (i <= n) {
        // Add current number to the sum
        Sum += i;

        // Increment loop counter
        i++;
    }

    // Display the total sum
    cout << "Total sum is: " << Sum << endl;

    // Return 0 to indicate successful execution
    return 0;
}
