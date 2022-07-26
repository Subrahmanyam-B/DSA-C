#include <stdio.h>
#include <stdlib.h>

struct node {
     int data;
     struct node *next;
}node;
struct node *head;


void printList(struct node* head1){
     struct node * Ptr;
     
     Ptr = head1;

     while (Ptr != NULL) {

          printf("%d --> ", Ptr->data);
          Ptr = Ptr->next;
     }
}

void printcircList(struct node* head1){
     struct node * Ptr;
     
     Ptr = head1;

     while ((Ptr->next)!= head1) {

          printf("%d --> ", Ptr->data);
          Ptr = Ptr->next;
     }
     printf("%d", Ptr->data);
}

// Creating a Linked List

struct node * create_List(int n){
     struct node * head;
     struct node * p;
     int i ;
     for (i = 0 ; i<n ; i++){
          if (i==0){
               head = malloc(sizeof(struct node));
               p = head;
          }

          else {
               p->next = malloc(sizeof(struct node));
               p = p->next;
          }

          printf("Enter the value at the node %d :", i+1);
          scanf("%d", &p->data);

     }
     p->next = NULL;
     return head;
}

struct node * create_circList(int n){
     struct node * head;
     struct node * p;
     int i ;
     for (i = 0 ; i<n ; i++){
          if (i==0){
               head = malloc(sizeof(struct node));
               p = head;
          }

          else {
               p->next = malloc(sizeof(struct node));
               p = p->next;
          }

          printf("Enter the value at the node %d :", i+1);
          scanf("%d", &p->data);

     }
     p->next = head;
     return head;
}






struct node * concatenate(struct node* head1 , struct node * head2) {
     struct node * Ptr;

     Ptr = head1;

     while (Ptr->next != NULL) {
          Ptr = Ptr->next;
     }

     Ptr->next=head2;

     return head1;

}

struct node * insert_sorted(struct node * head ,struct node * element)
{
    struct node * Ptr;
    Ptr = head;
    
    while (Ptr->next!=NULL){
        if (element->data >= ((Ptr->next)->data)){
                Ptr=Ptr->next;
        }
        else {
            break;
        }
    }
    element->next = Ptr->next;
    Ptr->next= element;

    return head;
}


struct node * merge_circList(struct node * head1 , struct node * head2)
{
    struct node * Ptr1;
    struct node * Ptr2;

    Ptr1 = head1;

    while (Ptr1->next != head1) {
        Ptr1 = Ptr1->next;
    }
    Ptr1->next=head2;

    while (Ptr2->next != head2) {
        Ptr2 = Ptr2->next;
    }
    Ptr2->next= head1;

    return head1;
}
void printloopedList(struct node* head1, int len){
    int count = 0;
    struct node * Ptr;
     
    Ptr = head1;

    while (Ptr != NULL) {

        printf("%d --> ", Ptr->data);
        Ptr = Ptr->next;
        count++;
        if (count == len+1){
            break;
        }
    }
}

struct node * Looplist(struct node* head, int k){
    struct node * Ptr1;
    struct node * Ptr2;

    Ptr1= head;
    Ptr2= head;

    while ((Ptr1->next) != NULL) {

        Ptr1 = Ptr1->next;
    }

    for (int i=0 ;i<k-1; i++){
        Ptr2= Ptr2->next;
    }

    Ptr1->next=Ptr2;

    return head;
}




int main() {
     struct node *L1, *L2, *CL1, *CL2 , *L3;

     int len;
     printf("Enter the length of list:");
     scanf("%d", &len);

     printf("Enter linked list 1\n");
     L1 = create_List(len);
     
     printf("Enter linked list 2\n");
     L2 = create_List(len);

     // L1= concatenate(L1, L2);
     // printList(L1);
     // printf("\nQuestion 2\n");
     // int x;
     // printf("Enter the integer to be added:");
     // scanf("%d", &x);
     // struct node *element = (struct node *)malloc(sizeof(struct node));
     // element->data = x;
     // L1 = insert_sorted(L1, element);
     // printList(L1);

     
     // printf("Question 3\n");
     // printf("Enter circular linked list 2\n");

     // CL1 = create_circList(len);
     // printf("Enter circular linked list 2\n");

     // CL2 = create_circList(len);
  
     // CL1 = merge_circList(CL1, CL2);
     // printcircList(CL1);
     printf("\nQuestion 4\n");

     
     printf("Enter linked list 1\n");

     L3 = create_List(len);


     int y;
     printf("Enter the position to loop:");
     scanf("%d",&y);


    L3 = Looplist(L3,y);
    printloopedList(L3,len);

}