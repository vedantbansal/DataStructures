// The Code Room

#include<stdio.h>
#include<stdlib.h>

//Declare a Node structure
struct Node{
    int key;
    struct Node *next; //C++: Node *next;
};

struct Node *head = NULL; //pointer to head node of the linked list

//Create the Linked list
void createList(int data){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); //C++: new Node()
    newNode->key = data;
    newNode->next = NULL;

    struct Node *currentNode = head;

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

//Reverse the list
void reverse(){
    struct Node *currentNode = head;
    struct Node *nextNode = head->next;
    struct Node *temp;

    while(nextNode != NULL){
        temp = nextNode->next;
        nextNode->next = currentNode;
        currentNode = nextNode;
        nextNode = temp;        
    }
    head->next = NULL;
    head = currentNode;
}

//Print the linked list
void printList(){
    struct Node *currentNode = head;

    //traverse the linked list
    while (currentNode != NULL){
        printf("%d ", currentNode->key);
        currentNode = currentNode->next;
    }
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
    printf("Original List: ");
    printList();
    reverse();
    printf("Reversed List: ");
    printList();
}