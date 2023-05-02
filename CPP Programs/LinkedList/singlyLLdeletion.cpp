#include<iostream>
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

void deleteAtHead(Node* &head)
{
    Node* temp = head;
    head = head -> next;
    temp -> next = NULL;
    delete temp;

}

void deleteAtTail(Node* &tail, Node* &cur, Node* &prev)
{
    
    prev -> next = cur -> next;
    cur -> next = NULL;
    delete cur; 
}

void deleteAtNode(int pos, Node* &head, Node * &tail)
{
    if(pos == 1)
    {
        deleteAtHead (head);
        return;
    }
    Node* cur = head;
    Node* prev = NULL;
    int cnt = 1;
    while(cnt < pos)
    {
        prev = cur;
        cur = cur -> next;
        cnt++;
    }

    if(cur -> next == NULL)
    {
        // deleteAtTail(tail, cur, prev);
        // return;
        tail = prev;
    }
    prev -> next = cur -> next;
    cur -> next = NULL;
    delete cur; 
}

int main()
{
    Node * node1 = new Node(10);   

    //head
    Node* head = node1;
    
    //tail
    Node* tail = node1;
    //print(head);
    
    //insertion
    insertAtTail(tail , 15);
    //print(head);
    insertAtTail(tail, 20);
    //print(head);
    insertAtHead(head, 5);
    //print(head);
    insertAtPosition(head, tail, 5 , 25);
    print(head);

    cout << "Head : " << head -> data << endl;
    cout << "Tail : " << tail -> data << endl;

    deleteAtHead(head);
    print(head);

    cout << "Head : " << head -> data << endl;
    cout << "Tail : " << tail -> data << endl;

    deleteAtNode(4, head, tail);
    print(head);

    // deleteAtNode(3, head, tail);
    // print(head);
    cout << "Head : " << head -> data << endl;
    cout << "Tail : " << tail -> data << endl;

    deleteAtNode(3, head, tail);
    print(head);

    cout << "Head : " << head -> data << endl;
    cout << "Tail : " << tail -> data << endl;
    return 0;
}