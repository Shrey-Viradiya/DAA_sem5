#include<stdio.h>

void swap(int *a, int *b) 
{ 
    // simple function to swap numbers
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 

void selection_sort(int arr[], int n, int start){
    
        if (start == n) return;
        // Start with the first index as min index
		int min_idx = start;

        // iterate through array and find minimum number
        // and change min index
		for(int j=start; j<n; j++) 
            if(arr[j] < arr[min_idx]) min_idx = j;
	   		
        // swap the minimum number with first number
        swap(&arr[min_idx], &arr[start]); 

        // after every call
        // first position number of the sub-array will be 
        // at sorted position.
        selection_sort(arr, n, start+1);	
}

void printArray(int arr[], int size) 
{ 
    // simple function to print an array
    for (int i=0; i < size; i++) printf("%d ", arr[i]); 
    printf("\n"); 
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
    selection_sort(arr, n, 0);
    printf("Sorted Array: \n");
    printArray(arr, n);
    return 0;
}