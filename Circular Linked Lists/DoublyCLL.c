// The Code Room

#include<stdio.h>
#include<stdlib.h>

//Declare a Node structure
struct Node{
    struct Node *prev; 
    int key;
    struct Node *next; 
};

struct Node *head = NULL; //pointer to head node of the linked list

//Create the Linked list
void createList(int data){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); //C++: new Node()
    newNode->key = data;
    newNode->next = head;

    struct Node *currentNode = head;

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
    struct Node *currentNode = head;

    //traverse the linked list
    printf("List: ");
    do{
        printf("%d ", currentNode->key);
        currentNode = currentNode->next;
    }while (currentNode != head);
    printf("\n");
}

//Function to print the list in backward direction.
void backwardList(){
    struct Node *tail = head->prev;
    struct Node *currentNode = tail;

    //traverse the linked list backwards
    printf("Backwards List: ");
    do{
        printf("%d ", currentNode->key);
        currentNode = currentNode->prev;
    }while (currentNode != tail);
    printf("\n");
}

void main(){
    int n,x;
    printf("Enter the number of elements you want to store in the list: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for(int i = 0; i<n; i++){
        scanf("%d", &x);
        createList(x);
    }
    printList();
    backwardList();
}