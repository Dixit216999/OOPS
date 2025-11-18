#include <iostream>
#include <string>

using namespace std;

class Teacher{

private:
    //properties/attributes
    double salary;    //data hiding - encapsulation
public:
//properties/attributes
    string name;
    string subject;
    string department;

    //non-parameterized constructor
    // Teacher(){   //constructor
    //     department = "Electronics and Communication";
    // }   
    //parameterized constructor
     Teacher(string name, string subject, string department, double salary){   //constructor
        this->name = name;       //this pointer - to refer current object or to tell which one is the property of class
        this->subject = subject; //this pointer points to the memory address of current object
        this->department = department;
        this->salary = salary;
    }   
    
    Teacher(Teacher &t){   //copy constructor passing object by reference means address is passed meaning no new copy is created 
       cout<<"Inside copy constructor"<<endl;
       this-> name = t.name;     //and any changes made to the object inside the constructor will reflect in the original object
       this-> subject = t.subject;
       this-> department = t.department;
       this-> salary = t.salary;
    }
    

    //methods/ members functions
    void changeDepartment(string newDepartment){
        department = newDepartment;
    }
    //setter - to set the value of private attribute
    void changeSalary(double newSalary){ 
        salary = newSalary;
    }
    //getter - to get the value of private attribute
    double getSalary(){
        return salary;
    }
    void displayDetails(){
        cout << "Name: " << name << endl;
        cout << "Subject: " << subject << endl;
        cout << "Department: " << department << endl;
        cout << "Salary: " << salary << endl;
    }
};

class Account{
 private:                   //data hiding - encapsulation
    string accountNumber;
    double balance;
 public:
    string accountHolderName;
    string bankName;
};

int main() {
    // Teacher t1; //constructor called automatically
    // t1.name = "Dixit";
    // t1.subject = "Maths";
    // t1.changeSalary(500000);

    Teacher t1("Dixit", "Maths", "ECE", 500000); //parameterized constructor called automatically
  //  t1.displayDetails();

    Teacher t2(t1) ; //copy constructor called automatically, copying t1 object to t2 object
    t2.displayDetails();
    return 0;
}