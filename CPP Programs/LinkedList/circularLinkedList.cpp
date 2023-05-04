#include<iostream>
#include<map>
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

void print(Node *tail)
{
    Node* temp = tail;
    if(tail == NULL)
    {
        cout << "List is Empty" << endl;
        return;
    }

    do
    {
        cout << tail -> data << " -> ";
        tail = tail -> next;
    }
    while(tail != temp);
    cout << endl;
    cout << "tail : " << tail -> data << endl;
}

void insert(Node* &tail, int element, int d)
{
    if(tail == NULL)
    {
        Node *newNode = new Node(d);
        tail = newNode;
        newNode -> next = newNode;
    }
    else
    {
        //normal insertion
        // Node* node1 = new Node(d);
        // tail -> next = node1;
        // node1 -> next = tail;

        //by elements
        //assuming that the element is present in the list

        Node* curr = tail;

        while(curr->data != element) {
            curr = curr -> next;
        }
        
        //element found -> curr is representing element wala node
        Node* newNode = new Node(d);
        newNode -> next = curr -> next;
        curr -> next = newNode;
    }
}

void deleteNode(Node* &tail, int value)
{
    if(tail == NULL)
    {
        cout << "list is empty cannot delete please insert first" << endl;
        return;
    }
    else{
        //Assuming that node with value is present in linked list
        Node* prev = tail;
        Node* curr = prev -> next;

        while(curr -> data != value)
        {
            prev = curr;
            curr = curr -> next;
        }
        prev -> next = curr -> next;
        
        //1 Node List
        if(curr == prev)
        {
            tail = NULL;
        }

        //>=2 Node list
        else if(tail == curr)
        {
            tail = prev;
        }
        
        curr -> next = NULL;
        delete curr;
    }
}

//Check for circular linked list

bool isCircularList(Node* head) {
    //empty list
    if(head == NULL) {
        return true;
    }

    Node* temp = head -> next;
    while(temp != head ) {
        temp = temp -> next;
    }

    if(temp == head ) {
        return true;
    }

    return false;

}

/*
bool detectLoop(Node* head) {

    if(head == NULL)
        return false;

    map<Node*, bool> visited;

    Node* temp = head;

    while(temp !=NULL) {

        //cycle is present
        if(visited[temp] == true) {
            return true;
        }

        visited[temp] = true;
        temp = temp -> next;

    }
    return false;

}
*/


int main()
{
    //Node* node = new Node(5);
    Node* tail = NULL;

    //insertion
    insert(tail, 5, 10);
    print(tail);

    insert(tail, 10, 20);
    print(tail);

    insert(tail, 20, 30);
    print(tail);

    insert(tail, 30, 40);
    print(tail);

    insert(tail, 40, 50);
    print(tail);

    //Deletion at any position
    deleteNode(tail, 10);
    print(tail);

    if(isCircularList(tail)) {
        cout << "Linked List is Circular in nature" << endl;
    }
    else{
        cout << "Linked List is not Circular " << endl;
    }
/*
    if(detectLoop(tail)) {
        cout << " TRUE" << endl;
    }
    else{
        cout << "FALSE" << endl;
    }

*/
    
    return 0;
}