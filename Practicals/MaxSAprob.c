// Maximum subaraay problem Kadanes Algo

#include<stdio.h>
#include <limits.h>

int minVal(int a, int b){
    // returns the minimum from a and b
    return a<b?a:b;
}

int maxVal(int a, int b){
    // returns the maximum from a and b
    return a<b?b:a;
}

int main(){
    int n, arr[1000], max_till_now = INT_MIN, max_cumm_iter = 0;
    int start =0, end = 0, temp=start;
    // Input for the number of elements
    // max limit 1000 numbers
    printf("Please Enter the Array size (MAX 1000) : \n");
    scanf("%d", &n);

    // take numbers from users
    printf("Start Entering Number:");
    for( int i = 0; i < n;i ++){
        // scan the number
        scanf("%d", &arr[i]);

        // add the input into cumm sum iter
        max_cumm_iter += arr[i];

        if (max_cumm_iter < 0){
            // If the sum is contributing negatively
            // make it zero
            max_cumm_iter = 0;
            temp = i;
        }
        else if(max_till_now < max_cumm_iter){
            // when sub array sum is maximum than any other sub array sum
            // change the max_till_now
            max_till_now = max_cumm_iter;
            start = temp;
            end = i;
        }
    }

    // print the answer
    printf("Start %d End %d", temp + 1, end);
    printf("\nMaximum Subarray sum is %d", max_till_now);
    return 0;
    
}