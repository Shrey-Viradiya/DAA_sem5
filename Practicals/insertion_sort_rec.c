#include<stdio.h>

void swap(int *a, int *b) 
{ 
    // simple function to swap numbers
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 

void printArray(int arr[], int size) 
{ 
    // simple function to print an array
    for (int i=0; i < size; i++) printf("%d ", arr[i]); 
    printf("\n"); 
} 

void insertion_sort(int arr[], int n, int end) {
    if(end == n) return;
    if(arr[end] < arr[end - 1]){
        swap(&arr[end], &arr[end - 1]);
        insertion_sort(arr, n, end-1);
    }
    else
    {
        insertion_sort(arr, n, end +1);
    }
}



int main(void)
{
  	// take input from user for numbers
    int arr[1000]; 
    int n;

    printf("Enter the number of elements: (MAX 1000) \n");
    scanf("%d",&n);
    
    // checking if the number is beyond the limit or less than ZERO
    while(n>1000 || n<= 0){
        printf("Please enter the number b/w 0 & 1000: \n");
        scanf("%d",&n);
    }

    // Start taking input and store it in arr
    printf("Start entering number:\n");
    for (int i =0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    printf("Array: \n");
    printArray(arr, n);

    // calling function
    // for starting insertion sort, third argument is 1
    insertion_sort(arr, n, 1);

    
    printf("Sorted Array: \n");
    printArray(arr, n);
    return 0;
}