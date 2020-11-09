// The Code Room

#include<iostream>
using namespace std;

//Declare a Node structure
class Node{
    public:
        Node *prev; 
        int key;
        Node *next; 
};

Node *head = NULL; //pointer to head node of the linked list

//Create the Linked list
void createList(int data){
    Node *newNode = new Node();
    newNode->key = data;
    newNode->next = head;

    Node *currentNode = head;

    //Create head node if list is empty.
    if (head == NULL){
        head = newNode;
        newNode->prev = head;
        newNode->next = head;
        return;
    }

    //Append node in the list
    while(currentNode->next != head){
        currentNode = currentNode->next;
    }
    currentNode->next = newNode;
    newNode->prev = currentNode;
    head->prev = newNode;
}

//Print the linked list
void printList(){
    Node *currentNode = head;

    //traverse the linked list
    cout<<"List: ";
    do{
        cout<<currentNode->key<<" ";
        currentNode = currentNode->next;
    }while (currentNode != head);
    cout<<endl;
}

//Function to print the list in backward direction.
void backwardList(){
    struct Node *tail = head->prev;
    struct Node *currentNode = tail;

    //traverse the linked list backwards
    cout<<"Backwards List: ";
    do{
        cout<<currentNode->key<<" ";
        currentNode = currentNode->prev;
    }while (currentNode != tail);
    cout<<endl;

}

int main(){
    int n,x;
    cout<<"Enter the number of elements you want to store in the list: ";
    cin>>n;
    cout<<"Enter the elements: ";
    for(int i = 0; i<n; i++){
        cin>>x;
        createList(x);
    }
    printList();
    backwardList();
    return 0;
}