#include <iostream>

using namespace std;

bool isTriplet(int a,int b,int c)
{
    int prod1=max(a,max(b,c))*max(a,max(b,c));
    
    int prod2;
    
/*    if(a<b && c<b)
    prod2=a*a + c*c;
    else if(b<c && a<c)
    prod2=a*a + b*b;
    else
    prod2=b*b + c*c;
  */  
    prod2=((a*a)+(b*b)+(c*c))/prod1;
    if(prod2==2){
    return false;
    return true;}
}

int main()
{
    int a,b,c;
    
    cin >> a >> b >> c;
    
    if(isTriplet(a,b,c))
    cout << "is a pythagorous triplet";
    
    else
    cout << "not a pythagorous triplet";

    return 0;
}