#include <iostream>
#include <string>

using namespace std;

/*------------------ In this we will see inheritance concept in OOPs ------------------*/

// class Person{
// public:
//     string name;
//     int age;

//     Person(string name, int age){ // for parameterized constructor we have to call it explicitly in derived class means we have to pass the parameters from derived class constructor
//         this->name = name;
//         this->age = age;
//     }

//     Person(){
//       cout<<"Inside Parent constructor"<<endl; //Base class constructor called first then derived class constructor
//     }

//     ~Person(){
//       cout<<"Inside Parent destructor"<<endl; //Base class destructor called last
//     }
// };

// class Student : public Person{  //inheritance
// public:
//     int rollNumber;
    
//     void displayDetails(){
//         cout << "Name: " << name << endl; //accessing inherited property
//         cout << "Age: " << age << endl;   //accessing inherited property
//         cout << "Roll Number: " << rollNumber << endl;
//     }

//     Student(string name, int age, int rollNumber) : Person(name, age){ //calling base class constructor with parameters
//         this->rollNumber = rollNumber;
//       cout<<"Inside Child constructor"<<endl; //Derived class constructor called after base class constructor
//     }

//     ~Student(){
//       cout<<"Inside Child destructor"<<endl; //Derived class destructor called first
//     }

// };   

/*------------------ The above example is of single level inheritance ------------------*/


// class Person{
// public:
//     string name;
//     int age;
// };

// class Student : public Person{  //inheritance
// public:
//     int rollNumber;
    
// };   

// class gradStudent : public Student{  //multi-level inheritance
// public:
//     string researchArea;
// };


/*------------------ The above example is of multi-level inheritance ------------------*/

// class Student{
// public:
//     string name;
//     int rollNumber;
// };

// class Teacher  {  
// public:
//     string subject;
//     double salary;

// };   

// class PHD : public Student, public Teacher{  //multiple inheritance

// };

/*------------------ The above example is of multiple inheritance ------------------*/

// class Person{  //multiple inheritance
//  public:
//     string name;
//     int age;
// };

// class Student : public Person{  //hierarchical inheritance
// public:
//     int rollNumber;
// };

// class Teacher : public Person{  //hierarchical inheritance means multiple derived classes from a single base class
//  public:
//     string subject;
// };


/*------------------ The above is an example of Hierarchical inheritance ------------------*/


class Person {
protected:
    string name;
    int age;
public:
    Person(const string& n = "", int a = 0) : name(n), age(a) {}
    virtual ~Person() = default;

    void displayPerson() const {
        cout << "Name: " << name << "\nAge: " << age << '\n';
    }
};

// Student and Staff virtually inherit Person to avoid duplicate Person subobject
class Student : virtual public Person {
protected:
    int rollNumber;
    string course;
public:
    Student(const string& n = "", int a = 0, int r = 0, const string& c = "")
        : Person(n, a), rollNumber(r), course(c) {}

    void displayStudent() const {
        cout << "Roll Number: " << rollNumber << "\nCourse: " << course << '\n';
    }
};

class Staff : virtual public Person {
protected:
    double salary;
    string subject;
public:
    Staff(const string& n = "", int a = 0, double s = 0.0, const string& subj = "")
        : Person(n, a), salary(s), subject(subj) {}

    void displayStaff() const {
        cout << "Salary: " << salary << "\nSubject: " << subject << '\n';
    }
};

// TeachingAssistant demonstrates hybrid inheritance:
// - hierarchical: Person -> Student and Person -> Staff
// - multiple: TeachingAssistant inherits from Student and Staff
class TeachingAssistant : public Student, public Staff {
public:
    // Must initialize the virtual base Person here (most-derived class)
    TeachingAssistant(const string& n, int a, int r, const string& c, double s, const string& subj)
        : Person(n, a), Student(n, a, r, c), Staff(n, a, s, subj) {}

    void displayAll() const {
        displayPerson();   // from Person
        displayStudent();  // from Student
        displayStaff();    // from Staff
    }
};


/*------------------ The above is an example of Hybrid inheritance ------------------*/


int main() {
    TeachingAssistant ta("Alice", 28, 101, "Computer Science", 25000.0, "Algorithms");
    ta.displayAll();
    return 0;
}