#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
} node;

node* head = NULL;

void print_list(node* current){
    printf("The list:");
    while (current != NULL){
        printf(" %d", current->data);
        current = current->next;
    }
}

void insert_node(node** head, int after, int value){
    node* new = (node*) malloc(sizeof(node));
    new->data = value;
    node* current = *head;
    if(after == 0){
        new->next = current;
        *head = new;
        return;
    }
    for(int i = 0; i < after - 1; i++)
        if(current->next != NULL)
            current = current->next;
    new->next = current->next;
    current->next = new;
}

void delete_node(node** head, int value){
    node* current = *head, *after;
    if (current != NULL && current->data == value){
        *head = current->next;
        free(current);
        return;
    }
    while (current != NULL && current->data != value){
        after = current;
        current = current->next;
    }
    if (current == NULL)
        return;
    after->next = current->next;
    free(current);
}

int main(){
    insert_node(&head, 0, 2);
    insert_node(&head, 2, 9);
    insert_node(&head, 9, 5);
    insert_node(&head, 5, 8);
    print_list(head);
    printf("\nAfter deleting 8:   ");
    delete_node(&head, 8);
    print_list(head);
    printf("\nAfter inserting 7:   ");
    insert_node(&head, 10, 7);
    print_list(head);
    return 0;
}