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

void insertion_sort(int arr[], int n) {
  for (int i = 1; i < n; i++) {
    // hold first position in temp
    // use the postion before it as starting iterator
    int tmp = arr[i], j = i-1;
    

    // iterating from last to first 
    // check whether the starting number is smaller or not
    // shift till the position is found
    while (tmp < arr[j] && j >= 0) {
        arr[j + 1] = arr[j];
        --j;
    }

    // place the number at its sorted position
    arr[j + 1] = tmp;
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
    insertion_sort(arr, n);
    printf("Sorted Array: \n");
    printArray(arr, n);
    return 0;
}