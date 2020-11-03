#include<stdio.h>
#include<stdlib.h>

struct item{
    int item_number;
    double value;
    double weight;
    double ratio;
};

typedef struct item item;

void knapsack(item * items, int n, int w){

    double weight = 0;
    double value = 0;
    for (int i = 0; i < n; i++)
    {
        // selecting item at index i in items
        // double c_left_weight = weight;
        double u_left_weight = weight;
        // double c_left = value;
        double u_left = value;

        // not selecting item at index i in items
        // double c_right_weight = weight;
        double u_right_weight = weight;
        // double c_right = value;
        double u_right = value;

        for (int j = i; j < n; j++)
        {
            // selecting the item
            // if (c_left_weight + items[j].weight <= w)
            // {
            //     c_left_weight += items[j].weight;
            //     c_left += items[j].value;
            // }
            // else
            // {
            //     c_left += ((w-c_left_weight)/items[j].weight) * items[j].value;
            //     c_left_weight = w;
            // } 

            if(u_left_weight + items[j].weight <= w){
                u_left_weight += items[j].weight;
                u_left += items[j].value;
            }

            // not selecting the item
            if (j != i)
            {
                // if (c_right_weight + items[j].weight <= w)
                // {
                //     c_right_weight += items[j].weight;
                //     c_right += items[j].value;
                // }
                // else
                // {
                //     c_right += ((w-c_right_weight)/items[j].weight) * items[j].value;
                //     c_right_weight = w;
                // } 

                if(u_right_weight + items[j].weight <= w){
                    u_right_weight += items[j].weight;
                    u_right += items[j].value;
                }
            }
        }
        if (u_left > u_right)
        {
            printf("Item %d is selected\n", items[i].item_number);
            weight += items[i].weight;
            value += items[i].value;
        }
        else
        {
            printf("Item %d is NOT selected\n", items[i].item_number);
        }  
    }

    printf("\nWeight is %lf and Value is %lf", weight, value);
}

int main(){

    int n;
    printf("Enter the number of items: \n");
    scanf("%d", &n);

    int w;
    printf("Enter Knapsack Capicity\n");
    scanf("%d", &w);

    item *items = malloc(n * sizeof(item));

    printf("Enter Value Weight\n");
    // taking input from user
    for (int i = 0; i < n; i++)
    {
        double v,w;
        scanf("%lf %lf",&v,&w);
        item temp = {i+1,v,w, v/w};
        items[i] = temp;
    }

    // sorting items
    for (int i = 1; i < n; i++) {
        // hold first position in temp
        // use the postion before it as starting iterator
        item tmp = items[i];
        int j = i-1;
        

        // iterating from last to first 
        // check whether the starting number is smaller or not
        // shift till the position is found
        while (tmp.ratio > items[j].ratio && j >= 0) {
            items[j + 1] = items[j];
            --j;
        }

        // place the number at its sorted position
        items[j + 1] = tmp;
    }

    printf("Sorted Items\n");
    printf("ItemNumber | Value | Weight | Value/Weight\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d | %lf | %lf | %lf\n",items[i].item_number,items[i].value,items[i].weight,items[i].ratio);
    }

    knapsack(items, n, w);

    return 0;
}
