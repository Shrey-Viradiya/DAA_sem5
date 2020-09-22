// Implementation of median of median algorithm in C

#include <stdio.h>
#include <stdlib.h>

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

void swap(int *a, int *b) 
{ 
    // simple function to swap numbers
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 


int get_median(int array[], int n){
    // insertion sort the array and return the median
    insertion_sort(array, n);
    return array[n/2];
}

int partition (int arr[], int low, int right, int pivot) 
{ 
    // finding pivot element in the array and swaping it with the last element
    int i; 
    for (i=low; i<right; i++) 
        if (arr[i] == pivot) 
           break; 
    swap(&arr[i], &arr[right]); 


    // standard partitioning code used in quick sort
    i = low;
  
    for (int j = low; j <= right- 1; j++) 
    { 
        if (arr[j] <= pivot) 
        {             
            swap(&arr[i], &arr[j]); 
            i++;
        } 
    } 
    swap(&arr[i], &arr[right]); 
    return i; 
} 

int deterministic_select(int array[], int left, int right, int k){
    // condition for the number of elements and smallest int asked
    if (k > 0 && k <= right-left+1)
    {
        int n = right - left + 1;
        int i;
        int *median = (int*) calloc( (n+4)/5, sizeof(int));

        // compute medians of individual groups
        for (i=0; i<n/5; i++)
            median[i] = get_median(array+left+i*5, 5); 

        if (i*5 < n)
        { 
            // compute medians of last group if required
            median[i] = get_median(array+left+i*5, n%5);  
            i++; 
        }

        int median_of_median;

        if (i == 1)
        {
            /* only one median 
                no need of recursion
            */
            median_of_median = median[0];
        }
        else{
            median_of_median = deterministic_select(median, 0, i-1, i/2);
        }

        // partition and recurrence according to the condition
        int position = partition(array, left, right, median_of_median);
        if (position - left == k-1) 
            return *(array+position);

        if (position - left > k-1)  
            return deterministic_select(array, left, position-1, k); 
  
        // Else recur for right subarray 
        return deterministic_select(array, position+1, right , k - position + left -1);  
        
    }

    else
    {
        printf("K is greater than the number of elemets in the array");
    }
    
    
}

int main(){
    //driver code
    printf("kth Smallest element using Median of Median Algorithm");
    printf("\n===========================================\n\n");

    int array[1000] = {0};
    printf("Enter the number of elements in the array: \n");
    int n;
    scanf("%d",&n);

    printf("\nStart entering numbers in the array: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&array[i]);
    }

    int k = 5;


    // calling median of median function
    printf("\n%d st/rd/th smallest element in the array is %d\n",k,deterministic_select(array, 0, n-1, k));

    return 0;
}