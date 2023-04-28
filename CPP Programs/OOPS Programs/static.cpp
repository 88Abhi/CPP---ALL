#include <iostream>
using namespace std;

class shape
{
    public:

     shape (){
        cout << "constructor is called " << endl;    }
    
    virtual int area() ;

   
    
};

class rectangle : public shape 
{
    public:
    int area (){
        return 5 * 10;
    }
};

class triangle : public shape 
{
    public:
    int area (){
        return 59* 10;
    }
};

class circle : public shape 
{
    public:
    int area (){
        return 58 * 10;
    }
};



int main()
{

    circle c;
    triangle a;
    rectangle r;
    shape s;


    cout << c.area() << endl;
    cout << a.area() << endl;
    cout << r.area() << endl;

    
}
