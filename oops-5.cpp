#include <iostream>
#include <string>

using namespace std;


/*------------------ In this we will study Polymorphism in OOPs ------------------*/

// class Student{
// public:
//     string name;

//     Student(){
//         cout<<"non-parameterized constructor"<<endl;
//     }

//     Student(string name){
//         this->name = name;
//         cout<<"parameterized constructor"<<endl;
//     }
// };




// int main(){
//     Student s1; //non-parameterized constructor called
//     Student s2("Dixit"); //parameterized constructor called
//     return 0;   
// }

/*------------------ The above example is of Constructor Overloading which is a compile time polymorphism ------------------*/


// class Print{
//     public:
//     void show(int i){
//         cout<<"Integer: "<<i<<endl; 
//     }
//     void show(char ch){
//         cout<<"Character: "<<ch<<endl; 
//     }
// };

// int main(){
//     Print p;
//     p.show(5);    //calls show(int i) on compile time itself decides which function to call based on the argument type
//     p.show('A');  //calls show(char ch) on compile time itself decides which function to call based on the argument type
//     return 0;   
// }

/*------------------ The above example is of Function Overloading which is a compile time polymorphism ------------------*/

// class Point {
// public:
//     int x, y;

//     // Constructor to initialize the object
//     Point(int x = 0, int y = 0) : x(x), y(y) {}

//     // Operator overloading for '+'
//     // This lets you write: p1 + p2
//     // Internally it creates a new Point whose values
//     // are the sum of the two operands.
//     Point operator+(const Point& other) {
//         // 'other' is the object on the right-hand side of +
//         return Point(x + other.x, y + other.y);
//     }
// };

// int main() {
//     // Create two objects
//     Point p1(2, 3);
//     Point p2(4, 1);

//     // Calls the overloaded operator+
//     // Equivalent to: p1.operator+(p2)
//     Point p3 = p1 + p2;

//     // Display results
//     cout << p3.x << " " << p3.y << endl;

//     return 0;
// }

/*------------------ The above example is of Operator Overloading which is a compile time polymorphism ------------------*/


// class Parent{
//     public:
//     void show(){
//         cout<<"Parent class show function called"<<endl;
//     }
// };

// class Child : public Parent{
//     public:
//     void show(){  //function overriding - runtime polymorphism
//         cout<<"Child class show function called"<<endl;
//     }
// };

// int main(){
//       Child c;
//       c.show(); //calls child class show function 
//       Parent p;
//       p.show(); //calls parent class show function
// }


/*------------------ The above example is of Function Overriding which is a runtime polymorphism ------------------*/



class Parent{
    public:
    void show(){
        cout<<"Parent class show function called"<<endl;
    }

    virtual void display(){  //virtual function - to achieve runtime polymorphism
        cout<<"Parent class display function called"<<endl;
    }
};

class Child : public Parent{
    public:
    void show(){  //function overriding - runtime polymorphism
        cout<<"Child class show function called"<<endl;
    }
    void display(){  //overriding virtual function
        cout<<"Child class display function called"<<endl;
    }
};

int main(){
      Child c;
      c.display(); //calls child class virtual function 
      Parent p;
      p.display(); //calls parent class virtual function
}