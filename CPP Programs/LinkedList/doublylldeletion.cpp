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

// DELETION IN DOUBLY LINKEDLIST

void deleteAtHead(Node* &head)
{
    Node* temp = head;
    head = head -> next;
    head -> prev = NULL;
    temp -> next = NULL;
    delete temp;
}

void deleteAtTail(Node* &tail)
{
    Node* temp = tail;
    tail = tail -> prev;
    tail -> next = NULL;
    temp -> prev = NULL;
    delete temp;
}

void deleteAtPosition(Node* &head, Node* &tail, int index)
{
    if(index == 0)
    {
        deleteAtHead(head);
        return;
    }
    Node* curr = head;
    Node* prev = NULL;
    int count = 0;
    while(count < index)
    {
        prev = curr;
        curr = curr -> next;
        count++;
    }
    if(curr -> next == NULL)
    {
        deleteAtTail(tail);
        return;
    }
    prev -> next = curr -> next;
    curr -> next -> prev = prev;

    curr -> prev = curr -> next = NULL;
    delete curr;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    //INSERTION

    //AtHead
    insertAtHead(head, tail, 30);
    print(head, tail);

    insertAtHead(head, tail, 10);
    print(head, tail);

    //AtTail
    insertAtTail(tail, head, 40);
    print(head, tail);
    
    //AtPosition
    insertAtPosition(head, tail, 2, 20);
    print(head, tail);

    // DELETION

    //head
    deleteAtHead(head);
    print(head, tail);

    //tail
    deleteAtTail(tail);
    print(head, tail);

    //position
    deleteAtPosition(head, tail, 2);
    print(head, tail);

    return 0;
}
