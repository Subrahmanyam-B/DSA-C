
#include <stdio.h>
 
int st1[100], st2[100];
int top1 = -1, top2 = -1;
int count = 0;
 

void push1(int data)
{
    st1[++top1] = data;
}
 
int pop1()
{
    return(st1[top1--]);
}
 
void push2(int data)
{
    st2[++top2] = data;
}
 
 
int pop2()
{
    return(st2[top2--]);
}
 
void enqueue()
{
    int data, i;
 
    printf("Enter data into queue");
    scanf("%d", &data);
    push1(data);
    count++;
}
 
void dequeue()
{
    int i;
 
    for (i = 0;i <= count;i++)
    {
        push2(pop1());
    }
    pop2();
    count--;
    for (i = 0;i <= count;i++)
    {
        push1(pop2());
    }
}
 
 
void display()
{
    int i;
 
    for (i = 0;i <= top1;i++)
    {
        printf(" %d ", st1[i]);
    }
}

#define N 100
int top=-1;
int stack[N];
void push(int k,int *a){
     int front=0;
     while(k--){
          top++;
          stack[top]=a[front];
          front++;
     }
}
void pop(int k,int *a){
     int front=-1;
     while(k--){
          front++;
          a[front]=stack[top];
          top--;
     }
}


int main()
{

     printf("\n=================Question 1=========================\n");
    int ch;
    int x=1;
 
    printf("\n1 - Enqueue element into queue");
    printf("\n2 - Dequeue element from queue");
    printf("\n3 - Display from queue");
    printf("\n4 - Exit");
        while (x==1)
    {
        printf("\nEnter choice");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
          printf("Program terminated");
            x=0;
            break;
        default:
            printf("Wrong choice");
        }
    }
     printf("\n=================Question 2=========================\n");
     



     printf("\n=================Question 3=========================\n");

     int n;
     printf("Enter the size of the queue:");
     scanf("%d",&n);
     int front=-1,rear=-1;
     int queue[n];
     printf("Enter the elements in queue:");
     for(int i=0;i<n;i++){
          scanf("%d",&queue[i]);
          rear++;
          if(i==0)
               front++;
     }
          int k;
          printf("Enter the value of k:");
          scanf("%d",&k);
          push(k,queue);
          pop(k,queue);

     for(int i=0;i<n;i++){
          printf("%d ",queue[front]);
          front++;
     }


}