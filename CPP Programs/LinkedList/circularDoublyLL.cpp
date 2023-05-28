#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node * prev;
    Node(int data)
    {
        this -> data = data;
        this -> next = NULL;
        this -> prev = NULL;
    }   
    ~Node()
    {
        int value = this -> data; 
        if(this -> next != NULL)
        {
            this -> next = NULL;
            delete next;
        }
        cout << "Memory free for the node with data : "<< value << endl;
    }
};

int main()
{
    return 0;
}