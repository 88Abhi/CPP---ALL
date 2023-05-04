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

void reverse(Node* &head, Node* &tail)
{
    Node* temp = NULL;
    Node* current = head;
 
    /* swap next and prev for all nodes of
    doubly linked list */
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
 
    /* Before changing the head, check for the cases like
       empty list and list with only one node */
    if (temp != NULL)
        head = temp->prev;
}

int main()
{
    // Node* node1 = new Node(30);
    // Node* head = node1;
    // Node* tail = node1;

    //edge case 
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

    reverse(head, tail);
    print(head, tail);

    return 0;
}