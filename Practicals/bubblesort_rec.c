#include <stdio.h> 

void swap(int *a, int *b) 
{ 
    // simple function to swap numbers
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 

void bubbleSort(int arr[], int n) 
{
    // end case
    if (n == 1) return; 
  
    // operating on first n numbers
    // after the operation nth number will be
    // at its sorted position
    for (int i=0; i<n-1; i++) {
        if (arr[i] > arr[i+1]) swap(&arr[i], &arr[i+1]); 
    }
    
    // Recursive call to bubble sort on first n-1 numbers
    bubbleSort(arr, n-1); 
} 

void printArray(int arr[], int size) 
{ 
    // simple function to print an array
    for (int i=0; i < size; i++) printf("%d ", arr[i]); 
    printf("\n"); 
} 
   
int main() 
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

    printArray(arr, n); 

    // Call bubble sort function
    bubbleSort(arr, n); 
    printf("Sorted array : \n"); 
    printArray(arr, n); 
    return 0; 
} 