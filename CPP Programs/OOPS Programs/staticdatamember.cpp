#include <iostream>
using namespace std;

class base
{
    public :

    static int a ;

    void print()
    {
        cout << a << endl;
        a++;
    }
};

int base :: a = 10;

int main()
{
    base b1,b2,b3;
    b1.print();
    b2.print();
    b3.print();

}