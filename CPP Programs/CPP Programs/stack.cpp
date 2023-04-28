#include <iostream>
#include <stack>
using namespace std;

void insertAtend(stack<int>&s,int data)
{
    if(s.empty())
    {
        s.push(data);
        return;
    }

    int num=s.top();
    s.pop();
    insertAtend(s,data);
    s.push(num);
}
int main()
{
    stack<int> s;
    int length;
    cin>>length;
    for(int i=0;i<length;i++)
    {
        int n;
        cin>>n;
        s.push(n);
    }

    
   insertAtend(s,length);
    // while(!s.empty())
    // {
    //     cout<<s.top()<<" ";
    //     s.pop();
    // }
 
   for (int i=s.size();i>0;i--){
       cout<< s.top() <<" ";
        s.pop();
    }
    // cout<<" The top element is "<<s.top()<<endl;    
    // if (s.empty()) {
    //     cout << "The stack is empty";
    // }
    // else {
    //     cout << "The stack is not empty";
    // }
 
    return 0;
}
