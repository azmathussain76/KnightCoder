#include <iostream>
// CPP program to illustrate 
// concept of Virtual Functions
using namespace std;
 
class shape
{
public:
    virtual void print ()
    { cout<< "I am a shape class" <<endl; }
 
    void show ()
    { cout<< "Hello world! I am a Shape!" <<endl; }

    // cannot draw a shape if we don't know what kind
    virtual void draw () = 0;
};
 
class triangle:public shape
{
public:
    void print ()
    { cout<< "I am a triangle class" <<endl; }
 
    void show ()
    { cout<< "Hello World! I am a triangle!" <<endl; }

    void draw () {
        cout << "blah.. I just drew a triangle" << endl;
    }
};
 
int main()
{
    shape *sptr;
    triangle tri;
    sptr = &tri;
    //shape s;
     
    //virtual function, binded at runtime
    sptr->print(); 
    tri.print();
    tri.draw();
    sptr->draw();
     
    // Non-virtual function, binded at compile time
    sptr->show(); 
    tri.show();
    
}