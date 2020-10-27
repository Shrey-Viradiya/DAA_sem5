// For reference: http://www.hungarianalgorithm.com/examplehungarianalgorithm.php

#include<stdio.h>
#include<stdlib.h>

int min(int a, int b){
    return a < b ? a : b;
}

void subtract_row_minima(int ** efficiency, int size){
    for (int row = 0; row < size; row++)
    {
        int minimum = efficiency[row][0];
        for (int col = 0; col < size; col++)
        {
            minimum = min(minimum, efficiency[row][col]);
        }

        for (int col = 0; col < size; col++)
        {
            efficiency[row][col] -= minimum;
        }       
    }
}

void subtract_column_minima(int ** efficiency, int size){
    for (int col = 0; col < size; col++)
    {
        int minimum = efficiency[0][col];
        for (int row = 0; row < size; row++)
        {
            minimum = min(minimum, efficiency[row][col]);
        }

        for (int row = 0; row < size; row++)
        {
            efficiency[row][col] -= minimum;
        }       
    }
}

void print_matrix(int ** efficiency, int size){
    for (int row = 0; row < size; row++)
    {
        for (int col = 0; col < size; col++)
        {
            printf("%d ", efficiency[row][col]);
        }
        printf("\n");
    }
}

int get_number_of_lines(int ** efficiency, int size){
        
}

void hungarian(int ** efficiency, int size){
    subtract_row_minima(efficiency, size);
    subtract_column_minima(efficiency, size);
    print_matrix(efficiency, size);   
}

int main(){
    int size;
    printf("Enter the size of the matrix: ");
    scanf("%d", &size);


    int ** efficiency = malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++)
    {
        efficiency[i] = malloc(size * sizeof(int));
    }

    int ** efficiency_copy = malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++)
    {
        efficiency_copy[i] = malloc(size * sizeof(int));
    }
    
    // take input
    for (int row = 0; row < size; row++)
    {
        for (int col = 0; col < size; col++)
        {
            scanf("%d", &efficiency[row][col]);
            efficiency_copy[row][col] = efficiency[row][col];
        }
    }

    hungarian(efficiency, size);    
    return 0;
}