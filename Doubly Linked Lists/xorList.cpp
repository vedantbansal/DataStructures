// The Code Room

#include<iostream>
using namespace std;

//Declare a Node structure
class Node{
    public:
        int key;
        Node *np;
};

Node *head = NULL; //pointer to head node of the linked list

Node * XOR(Node *a, Node *b){
    return (Node *)((unsigned)a ^ (unsigned)b);
}

//Create the Linked list
void createList(int data){
    Node *newNode = new Node();
    newNode->key = data;
    newNode->np = NULL;

    Node *currentNode = head;
    Node *prev = NULL;
    Node *next;

    //Create head node if list is empty.
    if (head == NULL){
        head = XOR(newNode, head);
        return;
    }

    //Append node in the list
    while(currentNode){
        next = XOR(currentNode->np, prev);
        prev = currentNode;
        currentNode = next;
    }

    prev->np = XOR(prev->np, newNode);
    newNode->np = prev;
}

//Print the linked list
void printList(){
    Node *currentNode = head;
    Node *prev = NULL;
    Node *next;

    //traverse the linked list
    cout<<"List: ";
    while(currentNode){
        cout<<currentNode->key<<" ";
        next = XOR(prev, currentNode->np);
        prev = currentNode;
        currentNode = next;
    }
    cout<<endl;
}

//Function to print the list in backward direction.
void backwardList(){
    Node *currentNode = head;
    Node *prev = NULL;
    Node *next;

    //Find the address of tail node
    while(currentNode){
        next = XOR(prev, currentNode->np);
        prev = currentNode;
        currentNode = next;
    }

    //traverse the linked list backwards
    currentNode = prev;
    cout<<"Backwards List: ";
    while(currentNode){
        cout<<currentNode->key<<" ";
        prev = XOR(next, currentNode->np);
        next = currentNode;
        currentNode = prev;
    }
    cout<<endl;
}

int main(){
    int n, x;
    cout<<"Enter the number of elements you want to insert initially: ";
    cin>>n;
    cout<<"Enter the elements: ";
    for (int i = 0; i < n; i++){
        cin>>x;
        createList(x);
    }
    printList();
    backwardList();
    return 0;
}