#include <stdio.h>
#include <stdlib.h>


void swap(int * p1 , int * p2){
     int temp = *p1;
     *p1 = *p2;
     *p2 = temp;
}

void Insertion_sort(int arr[] , int n)
{
     int key, i , j;

     for ( i=1 ; i<n ; i++){
          key = arr[i];
          j = i-1;

          while( j >= 0 && arr[j]>key){
               arr[j+1] = arr[j];
               j = j-1;
          }
          arr[j+1]= key;
     }
}


void Selection_sort(int arr[] , int n)
{
     int min_val, i , j;

     for ( i=0 ; i<n-1 ; i++){

          min_val = i;
          for(j = i+1 ; j<n;j++){
               if (arr[j] < arr[min_val]){
                    min_val = j;
               }
          }
          swap(&arr[min_val], &arr[i]);
     }
}





void printArray(int arr[] , int n){
     printf("Array : ");
     for(int i = 0 ; i < n ; i++){
          printf("%d\t",arr[i]);
     }
}

int main(){
     int array[7]= {6,7,1,4,10,5,3};

     Selection_sort(array, 7);
     printArray(array, 7);

     return 0;
}