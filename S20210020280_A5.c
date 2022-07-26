#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
     struct node *prev;
     int val;
     struct node *next;
} node1;

typedef struct Node {
    float coeff;
    int expo;
    struct Node *next;
}node2;




node1 *Create_doublylist()
{
    node1 *head;
    node1 *tail;
    node1 *Ptr;
    int a, b;
    printf("\nEnter the no. of nodes:");
    scanf("%d", &b);
    for (a = 0; a < b; a++)
    {
        if (a == 0)
        {
            head = malloc(sizeof(node1));
            tail = head;
            tail->prev=NULL;
        }
        else
        {
            tail->next = malloc(sizeof(node1));
            Ptr=tail->next;
            Ptr->prev=tail;
            tail = tail->next;
            
        }

        printf("Enter the data of the node  %d: ", a + 1);
        scanf("%d", &tail->val);
    }
    tail->next = NULL;
    return head;
}


node1* Reverse_Doubly(node1 *head)
 {
    node1*pntr;
     printf("Reversed doubly nexted list is:");
    while(pntr -> next != NULL) {
        pntr = pntr -> next;
    }
    while(pntr!=NULL)
    {
        printf("%d ->",pntr->val);
        pntr=pntr->prev;
    }
    printf("\n");
    return (head);
}




node2 * insert(node2 * head, float coeff, int expo) {  //inserting into a new list

    node2 * temp;
    node2 * Ptr_1 = malloc(sizeof(node2 ));
    Ptr_1 -> coeff = coeff;
    Ptr_1 -> expo = expo;
    Ptr_1 -> next = NULL;

    if(head == NULL || expo > head->expo) {
        Ptr_1 -> next = head;
        head = Ptr_1;
    }
    else {
        temp = head;
        while(temp->next != NULL && temp->next->expo >= expo) {
            temp = temp->next;
        }
        Ptr_1 -> next = temp -> next;
        temp -> next = Ptr_1;
    }
    return head;
}

node2 * createPoly(node2 * head)
 {
    int len, i;
    float coeff;
    int expo;

    printf("Enter the number of terms in the polynomial: ");
    scanf("%d", &len);

    for(i = 0; i < len; i++) {
        printf("Enter the coeff for term %d: ", i + 1);
        scanf("%f", &coeff);

        printf("Enter the exponent for term %d: ", i + 1);
        scanf("%d", &expo);

        head = insert(head, coeff, expo);
    }
    return head;
}

void print(node2 * head) {

    if(head == NULL) {
        printf("No polynomial");
    }
    else {
        node2 * temp = head;
        while(temp != NULL) {
            printf("(%.1fx^%d)", temp -> coeff, temp -> expo);
            temp = temp -> next;
            if(temp != NULL) {
                printf(" + ");
            }
            else {
                printf("\n");
            }
        }
    }
}

void Addn(node2 * head1, node2 * head2)
{
     node2 * ptr_1 = head1;
     node2 * ptr_2 = head2;
     node2 * head3 = NULL;
     while(ptr_1 != NULL && ptr_2 != NULL) {
          if(ptr_1 -> expo == ptr_2 -> expo) {
               head3 = insert(head3, ptr_1 -> coeff + ptr_2 -> coeff, ptr_1 -> expo);
               ptr_1 = ptr_1 -> next;
               ptr_2 = ptr_2 -> next;
          }
          else if(ptr_1 -> expo > ptr_2 -> expo) {
               head3 = insert(head3, ptr_1 -> coeff, ptr_1 -> expo);
               ptr_1 = ptr_1 -> next;
          }
          else if(ptr_1 -> expo < ptr_2 -> expo) {
               head3 = insert(head3, ptr_2 -> coeff, ptr_2 -> expo);
               ptr_2 = ptr_2 -> next;
          }
     } 
     while(ptr_1 != NULL) {
          head3 = insert(head3, ptr_1 -> coeff, ptr_1 -> expo);
          ptr_1 = ptr_1 -> next;
     }
     while(ptr_2 != NULL) {
          head3 = insert(head3, ptr_2 -> coeff, ptr_2 -> expo);
          ptr_2 = ptr_2 -> next;
     }
     printf("Sum of the 2 polynomials is : ");
     print(head3);
}

void Subs(node2 *head1, node2 *head2) {

     node2 *ptr1 = head1;
     node2 *ptr2 = head2;
     node2 *head3 = NULL;

     while(ptr1 != NULL && ptr2 != NULL) {
          if(ptr1 -> expo == ptr2 -> expo) {
               head3 = insert(head3, ptr1 -> coeff - ptr2 -> coeff, ptr1 -> expo);
               ptr1 = ptr1 -> next;
               ptr2 = ptr2 -> next;
          }
          else if(ptr1 -> expo > ptr2 -> expo) {
               head3 = insert(head3, ptr1 -> coeff, ptr1 -> expo);
               ptr1 = ptr1 -> next;
          }
          else if(ptr1 -> expo < ptr2 -> expo) {
               head3 = insert(head3, ptr2 -> coeff, ptr2 -> expo);
               ptr2 = ptr2->next;
          }
        }

        while(ptr1 != NULL) {
                head3 = insert(head3, ptr1 -> coeff, ptr1 -> expo);
                ptr1 = ptr1 -> next;
        }

        while(ptr2 != NULL) {
                head3 = insert(head3, ptr2 -> coeff, ptr2 -> expo);
                ptr2 = ptr2 -> next;
        }

        printf("\nSubtraction of two polynomials entered is:\n");

        print(head3);
}

int main()
{
     node2 * L1 = NULL;
     node2 * L2 = NULL;
     printf("Enter the first polynomial\n");
     L1 = createPoly(L1);
     printf("Enter the second polynomial\n");
     L2 = createPoly(L2);
     Addn(L1, L2);


     Subs(L1, L2);


     node1 *L3; 
     printf("Question 3-\n");
     printf("Enter 1st list:");
     L3=Create_doublylist(L3); 
     L3=Reverse_Doubly(L3);  // Time Complexity is O(n)


    return 0;
}








  