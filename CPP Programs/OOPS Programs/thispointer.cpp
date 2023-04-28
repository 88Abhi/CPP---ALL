#include <bits/stdc++.h> 
using namespace std; 
class mobile{   public: 
    string model; 
    int year_of_manufacture;
    
    //  void set_details(string model,int year_of_manufacture)
    //  { 
    //     model = model;
    //   year_of_manufacture = year_of_manufacture;
    //    } 

      void print()
      { 
        cout<<model <<endl; 
        cout<<year_of_manufacture <<endl; 
        } 
        };
         int main() 
         {
             mobile redmi; 
             redmi.model="Abhishek";
             redmi.year_of_manufacture=1001;
              redmi.print(); 
              return 0;}