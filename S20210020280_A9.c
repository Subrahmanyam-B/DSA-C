#include <stdio.h>




void Question_1()
{    int size,N;
     printf("Enter the size of hash table:");
     scanf("%d",&size);
     printf("Enter the 'N' value:");
     scanf("%d",&N);
     if(N>size || N<=10)
          printf("Invalid input");
     else
     {  int a[N],b[N];
          printf("Enter the elements\n");
          for(int i=0;i<N;i++)
          {  scanf("%d",&a[i]);
               int sum=0;
               int k=a[i];
               while(k) 
               {  sum=sum+(k%10);
                    k=k/10;
               }
               b[i]=sum;
          }

          char hash_table[size];
          for(int i=0;i<size;i++)
               hash_table[i]='*';

          int count=0;
          int i=0;
          while(N--)
          {    int L=b[i]%size;
               if(hash_table[L%size]=='*')
               {  hash_table[L%size]='b[i]';
                         i+=1;
               }
               else
               {  
                    for(int j=0;j<size;j++)
                    {  if(hash_table[(L+(j*j))%size]=='*')
                         {   hash_table[(L+(j*j))%size]='b[i]';
                         i+=1;
                              break;
                         }
                         else
                         {   count+=1;
                         
                         }

                    }
                    
               }

          }
          printf("The no. of collisions occured is %d\n\n",count);

     }
}

struct pair{
     int value;
     int key;
};

void display_hash(struct pair hash[], int size)
{
     int i;
     printf(" Value\tKey\n");
     for (i=0;i<size;i++){
          printf("%d\t%d\n",hash[i].value , hash[i].key );
     }
}

int search(struct pair arr[], int size, int searchel){
     if (arr[searchel%size].value == searchel){
          return 1;
     }
     else
          return 0;
}

int sumpairs(struct pair arr[], int size){
     int sum;
     printf("Enter the value of sum:");
     scanf("%d", &sum);
     int count=0;
     int temp1,temp2;
     for(int i=0; i<size ; i++){
          for (int j = 0; i < size; j++)
          {  
               if (arr[i].value + arr[j].value == sum)
               {
                    printf("(%d,%d)\t",arr[i].value, arr[j].value);
                    break;
               }
          }
     }
}

void Question_3(){
     int size, temp , i;

     printf("Enter the size of Hash Table:");
     scanf("%d", &size);
     struct pair hash[size];
     printf("Enter the elements:");
     for (i = 0;i<size;i++)
     {
          scanf("%d", &temp);
          hash[temp%size].value = temp;
          hash[temp%size].key = temp%size;
     }
     printf("\n");

     display_hash(hash, size);
     sumpairs(hash, size);
}

void main(){
     printf("==============Question 1======================");
     Question_1();
     printf("==============Question 3======================");
     Question_3();

}