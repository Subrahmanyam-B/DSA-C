#include <stdio.h>

int readsmatrix(int sparseMatrix[10][3]){  //Reading the sparse Matrix
     int n;
     printf("Enter the no.of non-zero elements:");
     scanf("%d", &n);
     sparseMatrix[0][2]=n;
     

     for(int i=1; i<=n; i++){
          printf("\nEnter Triplet no %d :(row, column, value)", i);
          scanf("%d%d%d", &sparseMatrix[i][0],&sparseMatrix[i][1], &sparseMatrix[i][2]);
     }
     return 0;


}

int print_matrix(int matrixx[10][3]){  // Printing the sparse matrix
     int n;
     n= matrixx[0][2];
     printf("\nrow\tcolumn\tvalue");

     for(int i=0; i<=n; i++){
          printf("\n%d\t%d\t%d\t", matrixx[i][0],matrixx[i][1], matrixx[i][2]);
     }
     return 0;

}
int transpose_sparse(int sparseMatrix[10][3], int transposeSparse[10][3]){
     int i, j, k=1, n;
     transposeSparse[0][0]=sparseMatrix[0][1];
     transposeSparse[0][1]=sparseMatrix[0][0];
     transposeSparse[0][2]=sparseMatrix[0][2]; 

     n=sparseMatrix[0][2];
 

     for(i=0;i<sparseMatrix[0][1];i++){
          for(j=1;j<=n;j++){
               if(i==sparseMatrix[j][1]){
                    transposeSparse[k][0]=i;
                    transposeSparse[k][1]=sparseMatrix[j][0];
                    transposeSparse[k][2]=sparseMatrix[j][2];
                    k++;
               }
          }          
     }
     

}

int main(){
     int m,n;
     int sparseMatrix[10][3];
     int transposeSparse[10][3];

     printf("Enter the size of matrix (rows,columns):");
     scanf("%d%d",&m,&n);

     sparseMatrix[0][0]=m;
     sparseMatrix[0][1]=n;

     transposeSparse[0][0]=n;
     transposeSparse[0][1]=m;

     readsmatrix(sparseMatrix);
     print_matrix(sparseMatrix);
     transpose_sparse(sparseMatrix, transposeSparse);
     print_matrix(transposeSparse);

     return 0;
}