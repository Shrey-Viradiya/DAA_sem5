#include<stdio.h> 
#include <stdlib.h>

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
  
int partition (int arr[], int low, int high) 
{ 
    // For the randomized quick sort algorithm
    // key point is to randomly select the pivot
    int random = low + rand() % (high - low  + 1);
    int pivot = arr[random];    
    int i = (low - 1); 


    // here the trick is to swap the random index to high 
    // index and let simple quick sort algo do the work.
    swap(&arr[random], &arr[high]);
  
    for (int j = low; j <= high- 1; j++) 
    { 
        if (arr[j] <= pivot) 
        { 
            i++;
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
  
void quickSort(int arr[], int low, int high) 
{ 
    // quick sort algorithm 
    // recursive implementation
    if (low < high) // end case condition
    { 
        int pi = partition(arr, low, high); 
  
        // recursive call for sub arrays 
        // after getting partition index
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
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

    // printing unsorted array
    printf("Array: \n");
    printArray(arr, n);


    // calling quick sort function to sort the elements
    quickSort(arr, 0, n-1); 
    printf("Sorted array: \n"); 
    printArray(arr, n); 
    return 0; 
} 