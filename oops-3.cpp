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

    ~Student(){  //destructor
        cout<<"I deleted static allocated memory by default"<<endl;
        delete cgpaPtr; //freeing the dynamically allocated memory
        // if we don't free the memory here, it will lead to memory leak
    }


    void displayDetails(){
        cout << "Name: " << name << endl;
        cout << "CGPA: " << *cgpaPtr << endl;
    }
};

int main(){
    Student s1("Dixit", 9.1);
    s1.displayDetails();
   return 0;
}