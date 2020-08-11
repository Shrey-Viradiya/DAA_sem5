// Maximum subaraay problem Divide and Conquer 

#include<stdio.h>
#include <limits.h>

int minVal(int a, int b){
    return a<b?a:b;
}

int maxVal(int a, int b){
    return a<b?b:a;
}

int maxJoinSum(int arr[], int low, int middle, int high){
    int sum = 0;
    int left_sum = INT_MIN, right_sum = INT_MIN;

    // search the max left sub array sum
    for ( int iter = middle; iter >= low; iter--){
        sum += arr[iter];
        if (sum > left_sum){
            left_sum = sum;
        }
    }

    sum = 0;

    // search the max right sub array sum
    for ( int iter = middle + 1; iter <= high; iter++){
        sum += arr[iter];
        if (sum > right_sum){
            right_sum = sum;
        }
    }

    return maxVal(
        maxVal(
            left_sum,
            right_sum
        ),
        left_sum + right_sum
    );
}

int maxSAsum(int arr[], int low, int high){
    // Best case
    // only element is available
    if (low == high){
        return arr[low];
    }

    // find middle element
    int middle = (low + high) / 2;

    // return the max amongst the three numbers
    // 1. Maximum Subarray sum of left sub array
    // 2. Maximum Subarray sum of right sub array
    // 3. Maximum Subarray sum of Joined sub array
    
    return maxVal(
        maxVal(
            maxSAsum(arr, low, middle), 
            maxSAsum(arr, middle +1, high)),
        maxJoinSum(arr, low, middle, high)
        );
    
}

int main(){
    int n, arr[1000], max;

    // Input for the number of elements
    // max limit 1000 numbers
    printf("Please Enter the Array size: \n");
    scanf("%d", &n);

    // take numbers from users
    printf("Start Entering Number:");
    for( int i = 0; i < n;i ++){
        // scan the number
        scanf("%d", &arr[i]);
    }

    // call the Max SubArray Sum function
    // problem will be solved by divide and conquer
    max = maxSAsum(arr, 0, n-1);

    // print the answer
    printf("\nMaximum Subarray sum is %d:", max);
    return 0;
}