#include<iostream>
using namespace std;

class sk
{
    public:
    int a,b;

    void input()
    {
        cout<<"Enter values : ";
        cin>>a>>b;
    }

    void output()
    {
        cout<<"A : "<<a<<" B : "<<b;
    }

    sk operator-(sk s)
    {
        sk s1;
        s1.a=a+s.a;
        s1.b=b+s.b;

        return s1;
    }
};
int main(){

    sk sx,sy,sz;
    sx.input();
    sy.input();
    sz=sx-sy;

    sz.output();
    




    return 0;
}