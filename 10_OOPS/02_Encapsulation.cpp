#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    // Private data members (hidden from the outside world)
    int employeeID;
    string employeeName;
    float salary;

public:
    // Constructor to initialize employee details
    Employee(int id, string name, float sal) {
        employeeID = id;
        employeeName = name;
        salary = sal;
    }

    // Public getter methods to access private data
    int getEmployeeID() {
        return employeeID;
    }

    string getEmployeeName() {
        return employeeName;
    }

    float getSalary() {
        return salary;
    }

    // Public setter methods to modify private data
    void setEmployeeName(string name) {
        employeeName = name;
    }

    void setSalary(float sal) {
        if (sal > 0) { // Validating the input
            salary = sal;
        } else {
            cout << "Invalid salary value!" << endl;
        }
    }

    // Method to display employee details
    void displayEmployeeInfo() {
        cout << "Employee ID: " << employeeID << endl;
        cout << "Name: " << employeeName << endl;
        cout << "Salary: $" << salary << endl;
    }
};

int main() {
    // Creating an object of the Employee class
    Employee emp(101, "John Doe", 50000.0);

    // Display initial details
    cout << "Initial Employee Details:" << endl;
    emp.displayEmployeeInfo();

    // Modify and access employee details using methods
    cout << "\nUpdating Employee Details..." << endl;
    emp.setEmployeeName("Jane Smith");
    emp.setSalary(60000.0);

    // Display updated details
    cout << "\nUpdated Employee Details:" << endl;
    emp.displayEmployeeInfo();

    return 0;
}
