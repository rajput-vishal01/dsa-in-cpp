#include <iostream>
using namespace std;

int main() {
    char ch;
    cout << "Enter a character: ";
    cin >> ch;
    if (isdigit(ch)) {
        cout << "The character entered is numeric." << endl;
    }
    else if (isupper(ch)) {
        cout << "The character entered is uppercase." << endl;
    }
    else if (islower(ch)) {
        cout << "The character entered is lowercase." << endl;
    }
    else {
        cout << "The character entered is neither numeric nor uppercase nor lowercase." << endl;
    }

    return 0;
}
