#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node* next;  
} Node;

typedef struct LinkedList{
    struct Node* head;
} LinkedList;

void linked_list_append(LinkedList* list,int value){
    Node* node = malloc(sizeof(Node));
    if(!node) return;
    node->value = value;
    node->next = NULL;

    if(!list->head){
        list->head = node;
    }else{
        Node* current = list->head;
        while(current->next!=NULL){
            current = current->next;
        }
        current->next = node;
    }
}

void linked_list_prepend(LinkedList* list,int value){
    Node* node = malloc(sizeof(Node));
    if(!node) return;
    node->value = value;
    node->next = NULL;
    if(!list->head){
        list->head = node;
    }else{
        node->next = list->head;
        list->head = node;
    }
}

void free_linked_list(LinkedList* list){
    if(!list || !list->head) return;
    Node* current = list->head;
    while(current!=NULL){
        Node* temp = current;
        current = current->next;
        free(temp);
    }

    list->head = NULL;
}

void print_linked_list(LinkedList* list){
    if(!list || !list->head) return;
    Node* current = list->head;
    while(current!=NULL){
        printf("%d\n",current->value);
        current = current->next;
    }
}