#include <iostream>
#include <string>

using namespace std;

class Student{
    public:
    string name;
    double* cgpaPtr;  //pointer to double

    Student(string name, double cgpa){   //copy constructor
        cout<<"Inside Student copy constructor"<<endl;
        this->name = name;
        //deep copy
        cgpaPtr = new double; //allocating new memory dynamically in heap
        *cgpaPtr = cgpa; //copying the value
        
    }

    // Student(Student &s){   //copy constructor
    //     this->name = s.name;
    //     this->cgpaPtr = s.cgpaPtr; //shallow copy - both pointers point to same memory location
    // }

     Student(Student &s){   //copy constructor
        this->name = s.name;
        cgpaPtr = new double; //allocating new memory dynamically in heap
        *cgpaPtr = *(s.cgpaPtr); //deep copy - copying the value to new memory location
    }

    void displayDetails(){
        cout << "Name: " << name << endl;
        cout << "CGPA: " << *cgpaPtr << endl;
    }
};

int main(){
    Student s1("Dixit", 9.1);
    Student s2 = s1; //copy constructor called let's name of s2 is Virat
    s1.displayDetails();
    *s2.cgpaPtr = 8.5; //changing cgpa of s2
   // s1.displayDetails(); //cgpa of s1 also changes because of shallow copy because both pointers point to same memory location
    s1.displayDetails(); //cgpa of s1 remains same because of deep copy using dynamic memory allocation
    s2.name = "Virat"; //changing name of s2
    s2.displayDetails();
   return 0;
}