#include <iostream>
using namespace std;

int main() {
    double fahrenheit, celsius;
    char choice;

    do {
        cout << "Enter temperature in Fahrenheit: ";
        cin >> fahrenheit;

        // Convert Fahrenheit to Celsius
        celsius = (fahrenheit - 32) * 5 / 9;

        // Display the result
        cout << "Temperature in Celsius: " << celsius << endl;

        // Ask user if they want to convert another temperature
        cout << "Do you want to convert another temperature? (Y/N): ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');

    cout << "Exiting program. Thank you!" << endl;

    return 0;
}
