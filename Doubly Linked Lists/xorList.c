// The Code Room

#include<stdio.h>
#include<stdlib.h>

//Declare a Node structure
struct Node{
    int key;
    struct Node *np;
};

struct Node *head = NULL; //pointer to head node of the linked list

struct Node * XOR(struct Node *a, struct Node *b){
    return (struct Node *)((unsigned)a ^ (unsigned)b);
}

//Create the Linked list
void createList(int data){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->key = data;
    newNode->np = NULL;

    struct Node *currentNode = head;
    struct Node *prev = NULL;
    struct Node *next;

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
    struct Node *currentNode = head;
    struct Node *prev = NULL;
    struct Node *next;

    //traverse the linked list
    printf("List: ");
    while(currentNode){
        printf("%d ", currentNode->key);
        next = XOR(prev, currentNode->np);
        prev = currentNode;
        currentNode = next;
    }
    printf("\n");
}

//Function to print the list in backward direction.
void backwardList(){
    struct Node *currentNode = head;
    struct Node *prev = NULL;
    struct Node *next;

    //Find the address of tail node
    while(currentNode){
        next = XOR(prev, currentNode->np);
        prev = currentNode;
        currentNode = next;
    }

    //traverse the linked list backwards
    currentNode = prev;
    printf("Backwards List: ");
    while(currentNode){
        printf("%d ", currentNode->key);
        prev = XOR(next, currentNode->np);
        next = currentNode;
        currentNode = prev;
    }
    printf("\n");
}

int main(){
    int n, x;
    printf("Enter the number of elements you want to insert initially: ");
    scanf("%d", &n);
    printf("Enter the %d elements: ",n);
    for (int i = 0; i < n; i++){
        scanf("%d", &x);
        createList(x);
    }
    printList();
    backwardList();
}