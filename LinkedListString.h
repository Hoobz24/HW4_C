//
// Created by Andrew on 3/12/2024.
//

#ifndef HW4_LINKEDLISTSTRING_H
#define HW4_LINKEDLISTSTRING_H

#endif //HW4_LINKEDLISTSTRING_H
struct node;
void push(struct node** head_ref, char* new_data);
void printList(struct node *head);
int listCount(struct node *head);
void reverseList(struct node** head_ref);
void listAllDelete(struct node **currP);
void deleteElement(struct node **currP, char *value);