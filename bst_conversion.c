#include <stdio.h>
#include <stdlib.h>

//binary search tree
int i=0;
int arr[100];
struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node * create_tree(){
     int x;
     struct node * newnode;
     newnode  = (struct node *)malloc(sizeof(struct node));
     printf("Enter data:( -1 for no node ):");
     scanf("%d", &x);

     if (x == -1){
          return 0;
     }
     newnode -> data=x;

     printf("Enter left child of %d\n", x);
     newnode->left = create_tree();
     printf("Enter right child of %d\n" ,x);
     newnode -> right = create_tree();

     return newnode;

}

void InOrder(struct node *root)
{
     if(root != NULL)
     {
          InOrder(root->left);
          printf(" %d ",root->data);
          arr[i]=root->data;
          i++;
          InOrder(root->right);
     }
}

//insertion sort
void insertion_sort(int *arr, int n)
{
     int i,j,temp;
     for(i=1;i<n;i++)
     {
          temp=arr[i];
          j=i-1;
          while(j>=0 && arr[j]>temp)
          {
               arr[j+1]=arr[j];
               j=j-1;
          }
          arr[j+1]=temp;
     }
}

//print array
void print_array(int arr[], int n)
{
     int j;
     for (j = 0; j < n; j++)
         printf("%d ", arr[j]);
     printf("\n");
}

//print tree
void print_tree(struct node *root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    print_tree(root->left);
    print_tree(root->right);
}

int main(){
     int n;
     printf("Enter the number of elements:");
     scanf("%d", &n);
     struct node *root = NULL;
     root = create_tree();
     printf("The InOrder traversal is :");
     InOrder(root);
     printf("\n");
     insertion_sort(arr, n);
     print_array(arr, n);
     return 0;
}