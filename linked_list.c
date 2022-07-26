#include <stdio.h>
#include <stdlib.h>

//create linked list
struct node {
    int data;
    struct node *next;
};

//create head
struct node *head;

//create function to create linked list
void create_list(int n) {
    struct node *p, *q;
    int i;
    for (i = 0; i < n; i++) {
        p = (struct node *)malloc(sizeof(struct node));
        printf("Enter the value at the node %d :", i + 1);
        scanf("%d", &p->data);
        p->next = NULL;
        if (i == 0) {
            head = p;
        } else {
            q->next = p;
        }
        q = p;
    }
}

//create function to print linked list
void print_list(struct node *head) {
    struct node *p;
    p = head;
    while (p != NULL) {
        printf("%d --> ", p->data);
        p = p->next;
    }
}

//create function to create circular linked list
void create_circular_list(int n) {
    struct node *p, *q;
    int i;
    for (i = 0; i < n; i++) {
        p = (struct node *)malloc(sizeof(struct node));
        printf("Enter the value at the node %d :", i + 1);
        scanf("%d", &p->data);
        p->next = NULL;
        if (i == 0) {
            head = p;
        } else {
            q->next = p;
        }
        q = p;
    }
    q->next = head;
}

//create function to print circular linked list
void print_circ_list(struct node *head) {
    struct node *p;
    p = head;
    while (p->next != head) {
        printf("%d --> ", p->data);
        p = p->next;
    }
    printf("%d", p->data);
}

int main(){
     int n;
     printf("Enter the number of nodes in the linked list :");
     scanf("%d", &n);
     create_list(n);
     print_list(head);
     printf("\n");
     create_circular_list(n);
     print_circ_list(head);
     return 0;
}