#include "LinkedListString.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Link list node */
struct node
{
    char data[40];
    struct node* next;
};

/* Function to push a node */
void push(struct node** head_ref, char* new_data)
{

    /* allocate node */
    struct node* new_node = malloc(sizeof(struct node));

    /* put in the data  */
    strcpy(new_node->data, new_data);

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref) = new_node;

}

/* Function to print linked list */
void printList(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%s  ", temp->data);
        temp = temp->next;
    }
}

/* Function to count the number of elements in the linked list */
int listCount(struct node *head){

    struct node *temp = head;
    int count = 0;

    while(temp != NULL){
        count++;
        temp = temp->next;

    }

    return count;
}
/* Function to reverse the linked list */

/**/

void reverseList(struct node** head_ref){
    struct node * previous = NULL;
    struct node * current = *head_ref;
    struct node * next;
    while(current != NULL){
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    };

    (*head_ref) = previous;
}
/*Function to delete all elements in a Linked List */
/**/

void listAllDelete(struct node **currP){

    free(*(currP));
    *(currP) = NULL;
}

/***Function to delete a particular element or elements in a linked list**/
void deleteElement(struct node **currP, char *value){

    struct node *temp = *currP;
    struct node *previous;
    struct node *head;

    while(temp != NULL && (strcmp(temp->data, value) == 0)){
        head = *currP;
        (*currP) = (*currP)->next;
        free(head);
        temp = *currP;
    }
    while(temp != NULL){
        while(temp != NULL && (strcmp(temp->data, value) != 0)){
            previous = temp;
            temp = temp->next;
        }
        if(temp == NULL){
            return;
        } else {
            previous->next = temp->next;
            free(temp);
            temp = previous->next;
        }
    }
}


