#ifndef C_LINKED_LIST_H
#define C_LINKED_LIST_H

typedef struct Node{
    int value;
    struct Node* next;  
} Node;

typedef struct LinkedList{
    struct Node* head;
} LinkedList;

void linked_list_append(LinkedList* list,int value);
void linked_list_prepend(LinkedList* list,int value);
void free_linked_list(LinkedList* list);
void print_linked_list(LinkedList* list);

#endif