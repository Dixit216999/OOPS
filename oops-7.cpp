#include <iostream>
#include <string>

using namespace std;

/*------------------ In this we will study Static Keyword in OOPs ------------------*/

// void fun(){
//     int x = 0;
//     cout<<"x : "<<x<<endl;
//     x++;
// }

// int main(){
//     fun(); //x is initialized to 0 every time function is called because in call stack every time 
//     fun(); //fun() is called a new memory is allocated for x and initialized to 0 means the value of x is not retained 
//     fun(); // or we can say the lifetime of x is only during the function call
//     return 0;   
// }

// void fun(){
//    static int x = 0;  //static variable - retains its value between function calls , initialized only once
//     cout<<"x : "<<x<<endl;
//     x++;
// }

// int main(){
//     fun(); //x is initialized to 0 only once and retains its value between function calls
//     fun();  //x is now 1
//     fun(); // x is now 2  as now x retains its value between function calls outside the call stack 
//     return 0;   
// }

/*------------------ The above example is of Static Variable which retains its value between function calls ------------------*/


// class A{
//     public:
//     int x;

//     void incX(){
//       x= x+1;
//     }
// };

// int main(){
//     A obj1, obj2;
//     obj1.x = 5;  //for obj1 x is created in memory and initialized to 5 means each object has its own copy of x
//     obj2.x = 10; //for obj2 x is created in memory and initialized to 10 means each object has its own copy of x
//     obj1.incX();
//     obj2.incX();
//     cout<<"Value of x : "<<obj2.x<<endl;
//     cout<<"Value of x : "<<obj1.x<<endl;
// }

class Abc{
    public:
   static int x;

    void incX(){
      x= x+1;
    }
};
int Abc::x = 0;
int main(){
    Abc obj1, obj2;
    obj1.x = 5;  //for obj1 x is created in memory and initialized to 5 means static variable is shared among all objects of the class
    obj2.x = 10; //for obj2 x is created in memory and initialized to 10 means static variable is shared among all objects of the class
    obj1.incX();
    obj2.incX();
    cout<<"Value of x : "<<obj2.x<<endl;
    cout<<"Value of x : "<<obj1.x<<endl;
    return 0;
}

/*-------------- The above is an example of static variable in a class ----------*/

// class A{
//     public:
//     A(){
//       cout<<"Constructor"<<endl;
//     }
//     ~A(){
//       cout<<"Destructor"<<endl;
//     }
// };

// int main(){
//    if(true){
//      static A obj; //constructor called when object is created
//    }        //destructor called when program ends not when object goes out of scope

//    cout<<"Outside if block"<<endl;
//    return 0;
// }

/*------------------ The above example is of Static Object whose destructor is called when program ends ------------------*/