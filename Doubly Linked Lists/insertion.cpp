// The Code Room

#include<iostream>
using namespace std;

//Declare a Node structure
class Node{
    public:
        int key;
        Node *next;
};

Node *head = NULL; //pointer to head node of the linked list

//Create the Linked list
void createList(int data){
    Node *newNode = new Node();
    newNode->key = data;
    newNode->next = NULL;

    Node *currentNode = head;

    //Create head node if list is empty.
    if (head == NULL){
        head = newNode;
        return;
    }

    //Append node in the list
    while(currentNode->next != NULL){
        currentNode = currentNode->next;
    }
    currentNode->next = newNode;
}

//Insert element in the list
void insert(int data, int pos){
    Node *newNode = new Node();
    newNode->key = data;
    newNode->next = NULL;

    Node *currentNode = head;
    int count = 1;

    //Insert node at first position
    if (pos == 1){
        newNode->next = head;
        head = newNode;
        return;
    }

    //Insert node in remaining list
    while (count<pos-1 && currentNode != NULL){
        currentNode = currentNode->next;
        count++;
    }
    newNode->next = currentNode->next;
    currentNode->next = newNode;
}

//Print the linked list
void printList(){
    Node *currentNode = head;

    //traverse the linked list
    cout<<"List: ";
    while (currentNode != NULL){
        cout<<currentNode->key<<" ";
        currentNode = currentNode->next;
    }
    cout<<endl;
}

int main(){
    int n, x, ele, pos, choice;
    cout<<"Enter the number of elements you want to store in the list: ";
    cin>>n;
    cout<<"Enter the elements: ";
    for(int i = 0; i<n; i++){
        cin>>x;
        createList(x);
    }

    //Loop to insert element in the list
    while(1){
        cout<<"Enter 1 if you want to insert an element else enter 0 to quit: ";
        cin>>choice;
        if(choice == 1){
            cout<<"Enter the element and its position: ";
            cin>>ele>>pos;
            insert(ele, pos);
            printList();
        }
        else{
            break;
        }
    }
    printList();
    return 0;
}
