//the cin object has delimeter for \n ("Enter") ,tab and space which means 
//it stops inserting the data after Enter , Tab and space.

//Beacuse of which we are unable to provide character array as 
//Vishal Rajput as the cin will stop inserting the data after space.

#include <iostream>
using namespace std;

// int main() {
//     char name[100];
//     cin >> name; // Input stops at the first space
//     cout << "Name: " << name << endl;
//     return 0;
// }


// Solution:
// To allow cin to read the entire line (including spaces), you can use cin.getline() or std::getline():

//the cin object has delimeter for \n ("Enter") ,tab and space which means 
//it stops inserting the data after Enter , Tab and space.

//Beacuse of which we are unable to provide character array as 
//Vishal Rajput as the cin will stop inserting the data after space.

// #include <iostream>
// using namespace std;
// int main() {
//     char name[100];
//     cin >> name; // Input stops at the first space
//     cout << "Name: " << name << endl;
//     return 0;
// }


// Solution:
// To allow cin to read the entire line (including spaces), you can use cin.getline() or std::getline():

#include <string>


int main() {

    string name;
    cout << "Enter your name"<< endl;
    getline(cin, name); // Reads the entire line, including spaces
    cout << "Name: " << name << endl;
    return 0;
}
