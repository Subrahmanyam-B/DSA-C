#include <stdio.h>
#include <stdlib.h>


int arr[100];
int temp=0;
int i = 0;
int k = 1;
struct node1 {
     int data;
     struct node1 *left,*right;
};


struct node1 * create_tree(){
     int x;
     struct node1 * newnode;
     newnode  = (struct node1 *)malloc(sizeof(struct node1));
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

void KthLargest(struct node1 *root,int K)
{
    if(root==0) return ;
    KthLargest(root->left,K);
    if(i== K+1)
    {
        printf("The %dth largest element in the BST is %d",K,root->data);
    }
    i++;
    KthLargest(root->right,K);
}

int main(){
     printf("Program to find kth largest element in BST\n");
     int K;
     printf("Enter the value of K :");
     scanf("%d", &K);
     struct node1 * root;
     root = create_tree();
     KthLargest(root,K);
     return 0;
}
