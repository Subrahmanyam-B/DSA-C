#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int arr[100];
int temp=0;
int i = 0;
int k = 1;
struct node {
     int data;
     struct node *left,*right;
};


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


void Question_1(){
     printf("=======================Question 1==========================\n");
     int array[100];
     struct node * root;
     root = create_tree();
     printf("The InOrder traversal is :");
     InOrder(root);

     for(int j=0;j<i;j++){
          if ( temp < arr[j]) 
          {temp = arr[j];}
     }
     printf("\nLargest value is  : %d\n", temp);


}

void swap_tree(struct node* ptr)
{
        struct node* tmp;
        if (ptr==NULL)
                return;
        swap_tree(ptr->left);
        swap_tree(ptr->right);
    tmp = ptr->left;
    ptr->left = ptr->right;
    ptr->right = tmp;
}

int check_identical( struct node *p1, struct node *p2)
{
        if(p1==NULL && p2==NULL)
                return 1;
        if(p1!=NULL && p2!=NULL && p1->data == p2->data)
                if(check_identical(p1->left, p2->left) && check_identical(p1->right, p2->right))
                        return 1;
        return 0;
}

bool check_subtree(struct node *tree, struct node *subtree)
{
     if (subtree == NULL) return true;

     if (tree == NULL) return false;

     if (check_identical(tree,subtree)) return true;

     return (check_subtree(tree->left,subtree) || check_subtree(tree->right,subtree));
}

struct node * convert_tree(struct node * root){
     if(root!=NULL){
          root -> data= k;
          k++;
          root->left = convert_tree(root->left);
          root -> right = convert_tree(root->right);
     }
     return root;
}

void Question_2(){
     printf("=====================Question 2========================\n");
     struct node * root1, * root2;
     printf("______ENTER DATA FOR 1st TREE______\n");
     root1 = create_tree();
     printf("______ENTER DATA FOR 2nd TREE______\n");
     root2 = create_tree();
     root1 = convert_tree(root1);
     k=1;
     root2 = convert_tree(root2);
     if (check_identical(root1, root2)){
          printf("Same Structure\n");
     }

}


void Question_3(){
     printf("=====================Question 3========================\n");
     struct node * root, * root1;
     printf("______ENTER DATA FOR 1st TREE______\n");
     root = create_tree();
     printf("Inorder of the tree before swap:");
     InOrder(root);
     swap_tree(root);
     printf("\nInorder of the tree after swap:");
     InOrder(root);
}


void Question_4(){
     printf("\n=====================Question 4========================\n");
     struct node * root1, * root2;
     printf("______ENTER DATA FOR 1st TREE______\n");
     root1 = create_tree();
     printf("______ENTER DATA FOR 2nd TREE______\n");
     root2= create_tree();

     if (check_subtree(root1, root2)){
          printf("TRUE");
     }
     else {
          printf("FALSE");
     }
}





void main(){
     Question_1();
     Question_2();
     Question_3();
     Question_4();
}