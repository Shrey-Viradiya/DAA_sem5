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

int minIndex(int arr[], int i, int j) 
{ 
    if (i == j) return i;
  
    // Find minimum of remaining elements 
    int k = minIndex(arr, i + 1, j); 
  
    // Return minimum of current and remaining. 
    return (arr[i] < arr[k])? i : k; 
} 

void bubble_sort(int arr[], int outer, int inner, int n){
    // end case
    if (outer > n) return;

    // recurrently calling function to start inner from n again
    // with outer increased
    if (inner < 0) bubble_sort(arr, outer + 1, n, n);
    else{
        // Swapping is condition is true
        // reverse the sign for descending sort
        if ( arr[outer] > arr[inner]) swap(&arr[outer], &arr[inner]);
        // decrease the inner with outer untouched
        bubble_sort(arr, outer, inner-1, n);
    }
}

void insertion_sort(int arr[], int n, int end) {
    // end case
    if(end == n) return;

    // if adjacent are in inappropriate order,
    // swap them and recurrently call function for smaller subarray
    if(arr[end] < arr[end - 1]){
        swap(&arr[end], &arr[end - 1]);
        insertion_sort(arr, n, end-1);
    }
    else
    {
        // If adjacent are in appropriate order
        // recurrently call the bigger array        
        insertion_sort(arr, n, end +1);
    }
}
   
void selection_sort(int arr[], int n, int index) 
{ 
    // end case
    if (index == n) return; 
  
    // get index of minimum element
    int k = minIndex(arr, index, n-1); 
  
    // Swapping when index nd minimum index are not same 
    if (k != index) swap(&arr[k], &arr[index]); 
  
    // Recursively calling selection sort function 
    selection_sort(arr, n, index + 1); 
} 

int main(void)
{
  	 // take input from user for numbers
    int arr[1000], arr1[1000], arr2[1000];
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
        arr1[i] = arr[i];
        arr2[i] = arr[i];
    }


    printf("Array: \n");
    printArray(arr, n);

    // calling functions

    // calling insertion Sort
    insertion_sort(arr, n, 1);
    printf("Insertion Sorted Array: \n");
    printArray(arr, n);


    // calling bubble sort
    bubble_sort(arr1, 0, n, n);
    printf("Bubble Sorted Array: \n");
    printArray(arr1, n);


    // calling selection sort
    selection_sort(arr2, n, 0);
    printf("Selection Sorted Array: \n");
    printArray(arr2, n);
    return 0;
}