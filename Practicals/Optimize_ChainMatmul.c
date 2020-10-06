// C program for Optimizing Chained Matrix Multiplication

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void OptimizeSequence(int i, int j, int **s, int *matrix){
    if (i == j) 
    { 
        printf("A%d",(*matrix)++);
        // int t = *matrix + 1;
        // matrix = &t;
        return;
    }
    
    printf("(");
    OptimizeSequence(i, s[i][j], s, matrix);
    OptimizeSequence(s[i][j] + 1, j, s, matrix);
    printf(")");
       
}

void OptimizeMultiplication(int *arr, int n){
    
    int **m = malloc(n * sizeof(int *));
    for(int i=0;i<n;i++){
        m[i] = malloc(n*sizeof(int));
    }
    
    int **s = malloc(n * sizeof(int *));
    for(int i=0;i<n;i++){
        s[i] = malloc(n * sizeof(int));
    }  

    for (int i = 0; i < n; i++)
    {
        m[i][i] = 0;
    }

    for (int l = 2; l < n; l++)
    {
        for (int i = 1; i < n - l + 1; i++)
        {
            int j = i + l - 1;
            m[i][j] = LONG_MAX;
            for (int k = i; k <= j-1; k++)
            {
                int q = m[i][k] + m[k+1][j] + arr[i-1] * arr[k] * arr[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }                
            }            
        }        
    }

    int *matrix;
    int a = 1;
    matrix = &a;

    printf("\nMinimum Cost: %li", m[1][n-1]); 
    printf("\nOptimized Sequence: \n");
    OptimizeSequence(1, n-1, s, matrix);
}

int main(){

    printf("Enter the number of Dimensions: \n");
    int n;
    scanf("%d", &n);

    printf("Enter the Dimensions: \n");

    int* arr;
    arr = calloc(n, sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\nOptimizing....");
    OptimizeMultiplication(arr, n);   

    return 0;
}