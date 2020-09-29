// Strassens's Matrix Multiplication Algorithm

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void add(int **a, int **b, int size,int **ans){
    int i,j;       
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            ans[i][j] = a[i][j] + b[i][j];   
        }
    }
}

void sub(int **a,int **b,int size,int **ans){
    int i,j;
    for(i=0;i<size;i++){
                for(j=0;j<size;j++){
                        ans[i][j]= a[i][j] - b[i][j];
                }
        }
}

void strassens_matmul(int **a, int **b, int size, int **ans){
    if (size == 1)
    {
        ans[0][0] = a[0][0] * b[0][0];
    }
    else
    {
        int reduced_size = size/2;

        // allocate sub matrix memories

        int **a11 = malloc(reduced_size * sizeof(int *));
        for(int i=0;i<reduced_size;i++){
            a11[i]= malloc(reduced_size*sizeof(int));
        }

        int **a12 = malloc(reduced_size * sizeof(int *));
        for(int i=0;i<reduced_size;i++){
            a12[i]= malloc(reduced_size*sizeof(int));
        }

        int **a21 = malloc(reduced_size * sizeof(int *));
        for(int i=0;i<reduced_size;i++){
            a21[i]= malloc(reduced_size*sizeof(int));
        }

        int **a22 = malloc(reduced_size * sizeof(int *));
        for(int i=0;i<reduced_size;i++){
            a22[i]= malloc(reduced_size*sizeof(int));
        }

        int **b11 = malloc(reduced_size * sizeof(int *));
        for(int i=0;i<reduced_size;i++){
            b11[i]= malloc(reduced_size*sizeof(int));
        }

        int **b12 = malloc(reduced_size * sizeof(int *));
        for(int i=0;i<reduced_size;i++){
            b12[i]= malloc(reduced_size*sizeof(int));
        }

        int **b21 = malloc(reduced_size * sizeof(int *));
        for(int i=0;i<reduced_size;i++){
            b21[i]= malloc(reduced_size*sizeof(int));
        }

        int **b22 = malloc(reduced_size * sizeof(int *));
        for(int i=0;i<reduced_size;i++){
            b22[i]= malloc(reduced_size*sizeof(int));
        }

        for(int i=0; i<reduced_size; i++){
            for(int j=0; j<reduced_size; j++){
                a11[i][j]=a[i][j];
                a12[i][j]=a[i][j+reduced_size];
                a21[i][j]=a[i+reduced_size][j];
                a22[i][j]=a[i+reduced_size][j+reduced_size];                   
                b11[i][j]=b[i][j];
                b12[i][j]=b[i][j+reduced_size];
                b21[i][j]=b[i+reduced_size][j];
                b22[i][j]=b[i+reduced_size][j+reduced_size];
            }
        }


        // memory allocation to 7 products
        int **p1 = malloc(reduced_size * sizeof(int *));
        for(int i=0;i<reduced_size;i++){
            p1[i]= malloc(reduced_size*sizeof(int));
        }
        int **p2 = malloc(reduced_size * sizeof(int *));
        for(int i=0;i<reduced_size;i++){
            p2[i]= malloc(reduced_size*sizeof(int));
        }
        int **p3 = malloc(reduced_size * sizeof(int *));
        for(int i=0;i<reduced_size;i++){
            p3[i]= malloc(reduced_size*sizeof(int));
        }
        int **p4 = malloc(reduced_size * sizeof(int *));
        for(int i=0;i<reduced_size;i++){
            p4[i]= malloc(reduced_size*sizeof(int));
        }
        int **p5 = malloc(reduced_size * sizeof(int *));
        for(int i=0;i<reduced_size;i++){
            p5[i]= malloc(reduced_size*sizeof(int));
        }
        int **p6 = malloc(reduced_size * sizeof(int *));
        for(int i=0;i<reduced_size;i++){
            p6[i]= malloc(reduced_size*sizeof(int));
        }
        int **p7 = malloc(reduced_size * sizeof(int *));
        for(int i=0;i<reduced_size;i++){
            p7[i]= malloc(reduced_size * sizeof(int));
        }



        // compute products from p1 to p7
        int **temp1 = malloc(reduced_size * sizeof(int *));
        for(int i=0;i<reduced_size;i++){
            temp1[i]= malloc(reduced_size*sizeof(int));
        }

        sub(b12, b22, reduced_size, temp1);
        strassens_matmul(a11, temp1, reduced_size, p1); // p1 = a11(b12 - b22)
        

        int **temp2 = malloc(reduced_size * sizeof(int *));
        for(int i=0;i<reduced_size;i++){
            temp2[i]= malloc(reduced_size*sizeof(int));
        }

        add(a11, a12, reduced_size, temp2);
        strassens_matmul(temp2, b22, reduced_size, p2); // p2 = (a11 + a12)b22
        

        int **temp3 = malloc(reduced_size * sizeof(int *));
        for(int i=0;i<reduced_size;i++){
            temp3[i]= malloc(reduced_size*sizeof(int));
        }

        add(a21, a22, reduced_size, temp3);
        strassens_matmul(temp3, b11, reduced_size, p3); // p3 = (a21 + a22)b11
        

        int **temp4 = malloc(reduced_size * sizeof(int *));
        for(int i=0;i<reduced_size;i++){
            temp4[i]= malloc(reduced_size*sizeof(int));
        }

        sub(b21, b11, reduced_size, temp4);
        strassens_matmul(a22, temp4, reduced_size, p4); // p4 = a22(b21 - b11)
        

        int **temp5 = malloc(reduced_size * sizeof(int *));
        for(int i=0;i<reduced_size;i++){
            temp5[i]= malloc(reduced_size*sizeof(int));
        }
        int **temp6 = malloc(reduced_size * sizeof(int *));
        for(int i=0;i<reduced_size;i++){
            temp6[i]= malloc(reduced_size*sizeof(int));
        }
        
        add(a11, a22, reduced_size, temp5);
        add(b11, b22, reduced_size, temp6);
        strassens_matmul(temp5, temp6, reduced_size, p5); // p5 = (a11 + a22)(b11 + b22)
        

        int **temp7 = malloc(reduced_size * sizeof(int *));
        for(int i=0;i<reduced_size;i++){
            temp7[i]= malloc(reduced_size*sizeof(int));
        }
        int **temp8 = malloc(reduced_size * sizeof(int *));
        for(int i=0;i<reduced_size;i++){
            temp8[i]= malloc(reduced_size*sizeof(int));
        }
        
        sub(a12, a22, reduced_size, temp7);
        add(b21, b22, reduced_size, temp8);
        strassens_matmul(temp7, temp8, reduced_size, p6); // p6 = (a12 - a22)(b21 + b22)
        

        int **temp9 = malloc(reduced_size * sizeof(int *));
        for(int i=0;i<reduced_size;i++){
            temp9[i]= malloc(reduced_size*sizeof(int));
        }
        int **temp10 = malloc(reduced_size * sizeof(int *));
        for(int i=0;i<reduced_size;i++){
            temp10[i]= malloc(reduced_size*sizeof(int));
        }
        
        sub(a11, a21, reduced_size, temp9);
        add(b11, b12, reduced_size, temp10);
        strassens_matmul(temp9, temp10, reduced_size, p7); // p7 = (a11 - a21)(b11 + b12)

        free(temp1);
        free(temp2);
        free(temp3);
        free(temp4);
        free(temp5);
        free(temp6);
        free(temp7);
        free(temp8);
        free(temp9);
        free(temp10);

        int **t1 = malloc(reduced_size * sizeof(int *));
        for(int i=0;i<reduced_size;i++){
            t1[i]= malloc(reduced_size*sizeof(int));
        }
        int **t2 = malloc(reduced_size * sizeof(int *));
        for(int i=0;i<reduced_size;i++){
            t2[i]= malloc(reduced_size*sizeof(int));
        }
        int **t3 = malloc(reduced_size * sizeof(int *));
        for(int i=0;i<reduced_size;i++){
            t3[i]= malloc(reduced_size*sizeof(int));
        }
        int **t4 = malloc(reduced_size * sizeof(int *));
        for(int i=0;i<reduced_size;i++){
            t4[i]= malloc(reduced_size*sizeof(int));
        }
        

        int **ans11 = malloc(reduced_size * sizeof(int *));
        for(int i=0;i<reduced_size;i++){
            ans11[i]= malloc(reduced_size*sizeof(int));
        }
        int **ans12 = malloc(reduced_size * sizeof(int *));
        for(int i=0;i<reduced_size;i++){
            ans12[i]= malloc(reduced_size*sizeof(int));
        }
        int **ans21 = malloc(reduced_size * sizeof(int *));
        for(int i=0;i<reduced_size;i++){
            ans21[i]= malloc(reduced_size*sizeof(int));
        }
        int **ans22 = malloc(reduced_size * sizeof(int *));
        for(int i=0;i<reduced_size;i++){
            ans22[i]= malloc(reduced_size*sizeof(int));
        }

        add(p5,p6,reduced_size, t1);
        sub(p4,p2,reduced_size, t2);
        add(t1,t2,reduced_size, ans11); // ans11 = p5 + p6 + p4 - p2

        add(p1, p2, reduced_size, ans12); // ans12 = p1 + p2
        add(p3, p4, reduced_size, ans21); // ans21 = p3 + p4

        sub(p1, p3, reduced_size, t3);
        sub(p5, p7, reduced_size, t4);
        add(t3, t4, reduced_size, ans22); // ans22 = p1 + p5 - p7 - p3

        int a=0;
        int b=0;
        int c=0;   
        int d=0;
        int e=0;
        int nsize2= 2*reduced_size;
        for(int i=0;i<nsize2;i++){
            for(int j=0;j<nsize2;j++){
                if(j>=0 && j<reduced_size && i>=0 && i<reduced_size){
                    ans[i][j] = ans11[i][j];
                }
                if(j>=reduced_size && j<nsize2 && i>=0 && i<reduced_size){
                    a=j-reduced_size;
                    ans[i][j] = ans12[i][a];
                }
                if(j>=0 && j<reduced_size && i>= reduced_size && i < nsize2){
                    c=i-reduced_size;
                    ans[i][j] = ans21[c][j];
                }
                if(j>=reduced_size && j< nsize2 && i>= reduced_size && i< nsize2 ){
                    d=i-reduced_size;
                    e=j-reduced_size;
                    ans[i][j] =ans22[d][e];
                }
            }   
        }

        free(t1);
        free(t2);
        free(t3);
        free(t4);
        free(p1);
        free(p2);
        free(p3);
        free(p4);
        free(p5);
        free(p6);
        free(p7);
        free(a11);
        free(a12);
        free(a21);
        free(a22);
        free(b11);
        free(b12);
        free(b21);
        free(b22);
        
    }
    
    
    return;
}

int main(){
    int size, temp, power;

    // Take matrix size as input
    printf("Enter the matrix size: ");
    scanf("%d", &size);
    temp = size;

    // Expand the matrix size aacording to the power
    if(size & size-1 != 0){
        power = log(size)/log(2);
        size = pow(2,power+1);
    }

    // allocate memory to the expanded power size matrix
    int **a = malloc(size * sizeof(int *));
    for(int i=0;i<size;i++){
        a[i] = malloc(size*sizeof(int));
    }   
    int **b = malloc(size * sizeof(int *));
    for(int i=0;i<size;i++){
        b[i] = malloc(size*sizeof(int));
    }
    int **ans = malloc(size * sizeof(int *));
    for(int i=0;i<size;i++){
        ans[i] = malloc(size*sizeof(int));
    }


    // take user inputs for matrixs
    printf("Enter the elements of First Matrix of size %d x %d: \n", temp, temp);
    for (int iterator1 = 0; iterator1 < size; iterator1++)
    {
        for (int iterator2 = 0; iterator2 < size; iterator2++)
        {
            if (iterator1 >= temp || iterator2 >= temp )
            {
                a[iterator1][iterator2] = 0;
            }
            else
            {
                scanf("%d", &a[iterator1][iterator2]);
            }           
        }
    }

    printf("Enter the elements of Second Matrix of size %d x %d: \n", temp, temp);
    for (int iterator1 = 0; iterator1 < size; iterator1++)
    {
        for (int iterator2 = 0; iterator2 < size; iterator2++)
        {
            if (iterator1 >= temp || iterator2 >= temp )
            {
                b[iterator1][iterator2] = 0;
            }
            else
            {
                scanf("%d", &b[iterator1][iterator2]);
            }           
        }
    }
    
    // strassens_matmul
    strassens_matmul(a,b,size,ans);

    printf("Answer of the Matrix Multiplication: \n");
    for (int iterator1 = 0; iterator1 < temp; iterator1++)
    {
        for (int iterator2 = 0; iterator2 < temp; iterator2++)
        {
            printf("%d ",ans[iterator1][iterator2]);
        }
        printf("\n");
    }
    

    return 0;
}