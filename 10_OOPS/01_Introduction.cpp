#include <iostream> 
using namespace std; 

class Student {
  public:
  //student attributes
  int id;
  string name;
  int roll_no;

//constructor/ctor

//default constructor

Student(){
  cout<<"Default Constructor"<<endl;
}

//parameterized constructor
  Student(int id, string name, int roll_no){
    //initializing the student attributes
    cout<<"Student Parameterized Constructor"<<endl;
    this->id = id;
    this->name = name;
    this->roll_no = roll_no;
  }

  //Copy constructor
  Student(const Student &srcobj){ //&srcobj => student 
    //initializing the student attributes
    cout<<"Student Copy Constructor"<<endl;
    this->id = srcobj.id;
    this->name = srcobj.name;
    this->roll_no = srcobj.roll_no;
  }



//Behaviour / Methods/ Functions
void study(){
  cout << this->name<<" Student is studying" << endl;
}

void sleep(){
  cout << this->name << " Student is sleeping" << endl;
}

//destructor/dtor

~Student(){
  cout<<" Student Destructor"<<endl;
  //deleting the student object
  //freeing up memory
  //...other cleanup code if required
 // delete this;
}

//compiler by default also creates constructor and destructor



};




int main() {
 //works for default constructor
  //  Student student;
  //  student.id = 1;
  //  student.name = "Ram";
  //  student.roll_no = 101;
  //  student.study();
  

//works for parameterized constructor
  Student student(2, "Shyam", 102); //stored in Stack Memory
  Student student2(2, "Karma",103);
  student.study();
  student.sleep();

 student2.sleep();

 cout<<student.name<<" "<<student.roll_no<<endl;
 

//Copy constructor/ctor
Student student3 = student;
cout<<student3.name<<" "<<student3.id<<endl;

//Dynamic allocation,On Heap Memory
  Student *p = new Student(3, "Gopal", 104);
  p->study();
  p->sleep();

  delete p; //free up memory always basic dynamic memory concept
 // p = nullptr; //optional, to avoid dangling pointer


    return 0; 
}
