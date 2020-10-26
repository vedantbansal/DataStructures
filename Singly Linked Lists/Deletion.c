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

//delete element from the list
void deleteElement(int pos){
    struct Node *currentNode = head;
    struct Node *temp;
    int count = 1;

    //Check if list is empty.
    if (head == NULL){
        printf("Sorry! List is empty.");
    }

    //Delete node at first position
    else if (pos == 1){
        temp = head;
        head = temp->next;
        free(temp);
    }

    //Delete node from the remaining list
    else{
        while (count<pos-1 && currentNode != NULL){
            currentNode = currentNode->next;
            count++;
        }
        temp = currentNode->next;
        currentNode->next = temp->next;
        free(temp);
    }
}

//Print the linked list
void printList(){
    struct Node *currentNode = head;

    //traverse the linked list
    printf("List: ");
    while (currentNode != NULL){
        printf("%d ", currentNode->key);
        currentNode = currentNode->next;
    }
    printf("\n");
}

void main(){
    int n, x, pos, choice;
    printf("Enter the number of elements you want to store in the list: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for(int i = 0; i<n; i++){
        scanf("%d", &x);
        createList(x);
    }

    //Loop to delete an element from the list
    while(1){
        printf("Enter 1 if you want to delete an element else enter 0 to quit: ");
        scanf("%d", &choice);
        if(choice == 1){
            printf("Enter the position of element: ");
            scanf("%d", &pos);
            deleteElement(pos);
            printList();
        }
        else break;
    }
    printList();
}