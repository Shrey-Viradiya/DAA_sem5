// Maximum subaraay problem Divide and Conquer 

#include<stdio.h>
#include <limits.h>

struct box{
    int low;
    int high;
    int sum;
};

int minVal(int a, int b){
    return a<b?a:b;
}

int maxVal(int a, int b){
    return a<b?b:a;
}

struct box maxJoinSum(int arr[], int low, int middle, int high){
    int sum = 0;
    int left_sum = INT_MIN, right_sum = INT_MIN;
    int max_left, max_right;
    // search the max left sub array sum
    for ( int iter = middle; iter >= low; iter--){
        sum += arr[iter];
        if (sum > left_sum){
            left_sum = sum;
            max_left = iter;
        }
    }

    sum = 0;

    // search the max right sub array sum
    for ( int iter = middle + 1; iter <= high; iter++){
        sum += arr[iter];
        if (sum > right_sum){
            right_sum = sum;
            max_right = iter;
        }
    }

    struct box final = {max_left, max_right, left_sum + right_sum};

    return final;
}

struct box maxSAsum(int arr[], int low, int high){
    // Best case
    // only element is available
    if (low == high){
        struct box m = {low, high, arr[low]};
        return m;
    }

    // find middle element
    int middle = (low + high) / 2;

    // return the max amongst the three numbers
    // 1. Maximum Subarray sum of left sub array
    // 2. Maximum Subarray sum of right sub array
    // 3. Maximum Subarray sum of Joined sub array
    
    struct box left_m = maxSAsum(arr, low, middle);
    struct box right_m = maxSAsum(arr, middle +1 , high);
    struct box join_m = maxJoinSum(arr, low, middle, high);
    
    if ((left_m.sum > right_m.sum)  && (left_m.sum > join_m.sum)){
        return left_m;
    }
    else if((right_m.sum > left_m.sum)  && (right_m.sum > join_m.sum)){
        return right_m;
    }
    else{
        return join_m;
    }
}

int main(){
    int n, arr[1000];

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
    struct box max = maxSAsum(arr, 0, n-1);

    // print the answer
    printf("\nMaximum Subarray sum is %d:", max.sum);
    printf("\nMaximum Subarray sum index is %d to %d:", max.low, max.high);
    return 0;
}