
#include <stdio.h>

void swap(int* p1, int* p2)
{
  int temp = *p1;
  *p1 = *p2;
  *p2 = temp;
}

void Array_zigzag(int A[], int n)
{

  int flag = 1;

  for (int i = 0; i <= n - 2; i++) {
    if (flag) 
    {
      if (A[i] > A[i + 1])
        swap(&A[i], &A[i + 1]);
    }
    else 
    {

      if (A[i] < A[i + 1])
        swap(&A[i], &A[i + 1]);
    }
    
    if (flag==1){flag=0;}
    else{flag=1;}

  }
}

int main()
{
    int n;
    int A[n];
    printf("Enter the size of array:");
    scanf("%d",&n);
    printf("Enter the array:");
    for(int i = 0;i < n; i++){
        scanf("%d", &A[i]);
    }

    Array_zigzag(A, n);
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    return 0;
}
