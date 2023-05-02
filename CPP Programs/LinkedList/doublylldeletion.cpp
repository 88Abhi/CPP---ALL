#include<iostream>
using namespace std;
/*

here the new line added to github repo

*/
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
};

void insertAtHead(Node* &head, Node* &tail, int d)
{
    if(head == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {
    Node* newNode = new Node(d);
    newNode -> next = head;
    head -> prev = newNode;
    head = newNode;
    } 
}

void insertAtTail(Node* &tail, Node* &head, int d)
{
    if(tail == NULL)
    {
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {
    Node* newNode = new Node(d);
    tail -> next = newNode;
    newNode -> prev = tail;
    tail = newNode;
    }
}

void print(Node* head, Node* tail)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout << temp -> data << " -> " ;
        temp = temp -> next;
    }
    cout << endl;
    cout << "head is : " << head -> data << endl;
    cout << "tail is : " << tail -> data << endl;
    cout << endl;
}

void insertAtPosition(Node* &head, Node* &tail, int position, int d)
{
    if(position == 1)
    {
        insertAtHead(head, tail, d);
        return ;
    }
    Node* temp = head;
    int cnt = 1;
    while(cnt < position - 1)
    {
        temp = temp -> next;
        cnt++;
    }
    if(temp -> next == NULL)
    {
        insertAtTail(tail, head, d);
        return;
    }

    Node* newNode = new Node(d);
    newNode -> next = temp -> next;
    newNode -> prev = temp;
    temp -> next = newNode;
    newNode -> next -> prev = newNode;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    //INSERTION

    //AtHead
    insertAtHead(head, tail, 10);
    print(head, tail);

    //AtTail
    insertAtTail(tail, head, 40);
    print(head, tail);
    
    //AtPosition
    insertAtPosition(head, tail, 2, 20);
    print(head, tail);

    return 0;
}