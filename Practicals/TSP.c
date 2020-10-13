// Travelling Salesman Problem

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int cost = 0;

int TSP(int city, int no_of_cities, int *visited_cities, int **cost_matrix)
{
    int nearest_city = INT_MAX;
    int minimum = INT_MAX, temp;

    for(int count = 0; count < no_of_cities; count++)
    {
        if((cost_matrix[city][count] != 0) && (visited_cities[count] == 0))
        {
            if(cost_matrix[city][count] < minimum)
            {
                minimum = cost_matrix[count][0] + cost_matrix[city][count];
                temp = cost_matrix[city][count];
                nearest_city = count;
            }            
        }
    }
    if(minimum != INT_MAX)
    {
        cost = cost + temp;
    }
    return nearest_city;
}

void minimum_cost(int city, int no_of_cities, int *visited_cities, int **cost_matrix)
{
    int nearest_city;
    visited_cities[city] = 1;
    printf("%d --> ", city + 1);
    nearest_city = TSP(city, no_of_cities, visited_cities, cost_matrix);
    if(nearest_city == INT_MAX)
    {
        nearest_city = 0;
        printf("%d", nearest_city + 1);
        cost = cost + cost_matrix[city][nearest_city];
        return;
    }
    minimum_cost(nearest_city, no_of_cities, visited_cities, cost_matrix);
}

int main(){

    printf("Travelling Salesman Problem:\n");

    printf("Enter the number of cities: \n");

    int no_of_cities;
    scanf("%d", &no_of_cities);

    int **cost_matrix = calloc(no_of_cities, sizeof(int *));
    for(int i=0;i<no_of_cities;i++){
        cost_matrix[i]= calloc(no_of_cities, sizeof(int));
    }

    printf("Enter Cost Matrix: \n");

    for (int i = 0; i < no_of_cities; i++)
    {
        for (int j = 0; j < no_of_cities; j++)
        {
            scanf("%d", &cost_matrix[i][j]);
        }
        
    }

    int *visited_cities = calloc(no_of_cities, sizeof(int));

    int starting_city = 0;

    printf("\nTravelling Path is: \n");
    minimum_cost(starting_city, no_of_cities, visited_cities, cost_matrix);

    printf("\nTravelling Cost is: %d\n", cost);

    return 0;
}