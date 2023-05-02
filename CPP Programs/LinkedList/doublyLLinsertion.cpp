#include<iostream>
using namespace std;

class Node
{
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

void insertAtHead(Node* &head, int d)
{

    Node* newNode = new Node(d);
    newNode -> next = head;
    head -> prev = newNode;
    head = newNode;
    
}

void insertAtTail(Node* &tail, int d)
{
    Node* newNode = new Node(d);
    tail -> next = newNode;
    newNode -> prev = tail;
    tail = newNode;
}

void print(Node* head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout << temp -> data << " -> " ;
        temp = temp -> next;
    }
    cout << endl;
}

void insertAtPosition(Node* &head, Node* &tail, int position, int d)
{
    if(position == 1)
    {
        insertAtHead(head, d);
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
        insertAtTail(tail, d);
        return;
    }

    //2 ways to insert at position

    //1st
    // Node* newNode = new Node(d);
    // newNode -> next = temp -> next;
    // newNode -> prev = temp;
    // temp -> next -> prev = newNode;
    // temp -> next = newNode;

    //2nd
    Node* newNode = new Node(d);
    newNode -> next = temp -> next;
    newNode -> prev = temp;
    temp -> next = newNode;
    newNode -> next -> prev = newNode;
}

int main()
{
    Node* node1 = new Node(30);
    Node* head = node1;
    Node* tail = node1;

    print(head);

    //INSERTION

    //AtHead
    insertAtHead(head, 10);
    print(head);
    cout << "head is : " << head -> data << endl;
    cout << "tail is : " << tail -> data << endl;

    //AtTail
    insertAtTail(tail, 40);
    print(head);
    cout << "head is : " << head -> data << endl;
    cout << "tail is : " << tail -> data << endl;
    
    //AtPosition
    insertAtPosition(head, tail, 2, 20);
    print(head);
    cout << "head is : " << head -> data << endl;
    cout << "tail is : " << tail -> data << endl;

    return 0;
}