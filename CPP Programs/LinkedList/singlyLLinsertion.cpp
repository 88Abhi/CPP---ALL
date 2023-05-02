#include<iostream>
using namespace std;

class Node
{
    public:

    int data;
    Node* next;
    Node(int data)
    {
        this -> data = data;
        this -> next = NULL;
    }
};

//inserting at head

void insertAtHead(Node* &head, Node* &tail, int d)
{
    if(head == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else{
    Node* newNode = new Node(d);
    newNode -> next = head;
    head = newNode;
    }
}

//inserting at tail

void insertAtTail(Node* &head, Node* &tail, int d)
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
    tail = newNode;
    }
}

void insertAtPosition(Node* &head, Node* &tail, int pos, int d)
{
    if(pos == 1)
    {
        insertAtHead(head, tail, d);
        return;
    }

    
    Node* temp = head;
    int cnt = 1;
    while(cnt < pos - 1)
    {
        temp = temp -> next;
        cnt++;
    }

    if(temp -> next == NULL)
    {
        insertAtTail(head, tail, d);
        return;
    }
    Node* newNode = new Node(d);
    newNode -> next = temp -> next;
    temp -> next = newNode;

}

//travesing in LinkedList

void print(Node* &head, Node* tail)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }
    cout << endl;
    cout << "Head At : " << head -> data << endl;
    cout << "tail At : " << tail -> data << endl;
    cout << endl;
}


int main()
{
    //cout << node1 -> data << endl;
    //cout << node1 -> next << endl;
/*
    //head
    Node* head = node1;
    
    //tail
    Node* tail = node1;
    print(head);
    
    //insertion
    insertAtTail(tail , 15);
    print(head);
    insertAtTail(tail, 20);
    print(head);
    insertAtHead(head, 5);
    print(head);
    insertAtPosition(head, 5 , 25);
    print(head);
*/

    Node* head = NULL;
    Node* tail = NULL;
    int n;
    cin >> n;

    //AtHead

    for(int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        insertAtHead(head, tail, val);
    }

    print(head, tail);

    //AtTail

    int n1;
    cin >> n1;

    for(int i = 0; i < n1; i++)
    {
        int val1;
        cin >> val1;
        insertAtTail(head, tail, val1);
    }

    print(head, tail);

    //AtPosition

    int n3;
    cin >> n3;

    for(int i = 0; i < n3; i++)
    {
        int val2, pos;
        cin >> val2;
        cin >> pos;
        insertAtPosition(head, tail, pos, val2);
    }
    print(head, tail);

    

    return 0;
}