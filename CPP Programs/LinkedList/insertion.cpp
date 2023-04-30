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

void insertAtHead(Node* &head, int d)
{
    Node* newNode = new Node(d);
    newNode -> next = head;
    head = newNode;
}

//inserting at tail

void insertAtTail(Node* &tail, int d)
{
    Node* newNode = new Node(d);
    tail -> next = newNode;
    tail = newNode;
}

void insertAtPosition(Node* &head, int pos, int d)
{
    if(pos == 1)
    {
        insertAtHead(head, d);
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
        insertAtTail(temp, d);
        return;
    }
    Node* newNode = new Node(d);
    newNode -> next = temp -> next;
    temp -> next = newNode;

}

//travesing in LinkedList

void print(Node* &head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}


int main()
{
    Node* node1 = new Node(5);
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

    Node* head = node1;
    Node* tail = node1;
    int n;
    cin >> n;

    //AtHead

    for(int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        insertAtHead(head, val);
    }

    print(head);

    //AtTail

    int n1;
    cin >> n1;

    for(int i = 0; i < n1; i++)
    {
        int val1;
        cin >> val1;
        insertAtTail(tail, val1);
    }

    print(head);

    //AtPosition

    int n3;
    cin >> n3;

    for(int i = 0; i < n3; i++)
    {
        int val2, pos;
        cin >> val2;
        cin >> pos;
        insertAtPosition(head, pos, val2);
    }
    print(head);


     
    return 0;
}