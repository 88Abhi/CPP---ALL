#include<iostream>
#include<map>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data)
    {
        this -> data = data;
        this -> next = NULL;
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

void insertAtPosition(Node* &head, Node* &tail, int pos, int d)
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
        insertAtTail(tail, d);
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
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }
    cout << endl;
}

Node* getReverse(Node* &head)
{
    if(head == NULL)
    return NULL;
    Node* curr = head;
    while(curr != NULL && curr -> next != NULL)
    {
        Node* prev = curr;
        Node* next = curr -> next;
        
        while(next != NULL && next -> next != NULL)
        {
            if(next -> data == curr -> data)
            {
                Node* temp = next;
                prev -> next = next -> next;
                next = next -> next;
                delete temp;
            }
            else{
                prev = next;
                next = next -> next;
            }
        }
        curr = curr -> next;
    }
    return head;
}

Node* getReverse1(Node* &head)
{
    map< int, bool > m;
    Node* curr = head;
    Node* prev = NULL;

    while(curr != NULL)
    {
        if(m[curr -> data] == true && curr -> next != NULL)
        {
                Node* temp = curr;
                prev -> next = curr -> next;
                curr = curr -> next; 
                delete temp;
        }
        else
        {
            prev = curr;
            m[curr -> data] = true;
            curr = curr -> next;
        }
    }
    return head;
}

int main()
{
    Node * node1 = new Node(10);   

    //head
    Node* head = node1;
    
    //tail
    Node* tail = node1;

    insertAtTail(tail , 15);
    insertAtTail(tail, 15);
    insertAtHead(head, 525);
    insertAtPosition(head, tail, 5 , 25);
    insertAtHead(head, 534);
    insertAtHead(head, 5);
    insertAtHead(head, 5);
    insertAtHead(head, 525);
    insertAtHead(head, 5);
    insertAtHead(head, 598);
    print(head);
    
    //O(n2) complexity O(1) using Loops
    //Node* temp = getReverse(head);
    //print(head);

    //O(n) Time and O(n) Space as well using map
    Node* temp1 = getReverse1(head);
    print(temp1);
    return 0;
}

/*
new line added successfully
*/