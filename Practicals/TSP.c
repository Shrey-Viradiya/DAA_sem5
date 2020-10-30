// Travelling Salesman Problem

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int cost = 0;

int TSP(int city, int no_of_cities, int *visited_cities, int **cost_matrix)
{
    // initialize to maximum
    int nearest_city = INT_MAX;
    int minimum = INT_MAX, temp;


    // from all the other cities
    for(int count = 0; count < no_of_cities; count++)
    {
        // if connected
        if((cost_matrix[city][count] != 0) && (visited_cities[count] == 0))
        {
            // get minimum and update variables minimum and temp
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
        // update cost only if minimum is updated
        cost = cost + temp;
    }

    // return nearest city
    return nearest_city;
}

void minimum_cost(int city, int no_of_cities, int *visited_cities, int **cost_matrix, int starting_city)
{
    int nearest_city;
    visited_cities[city] = 1;
    printf("%d --> ", city + 1);

    // starting from the given city
    // get nearest city
    // and add cost if to initial city if not found
    nearest_city = TSP(city, no_of_cities, visited_cities, cost_matrix);
    if(nearest_city == INT_MAX)
    {
        nearest_city = starting_city;
        printf("%d", nearest_city + 1);
        cost = cost + cost_matrix[city][nearest_city];
        return;
    }

    // recursive call to function from new nearest city
    minimum_cost(nearest_city, no_of_cities, visited_cities, cost_matrix, starting_city);
}

int main(){

    printf("Travelling Salesman Problem:\n");

    printf("Enter the number of cities: \n");

    // take input for number of cities
    int no_of_cities;
    scanf("%d", &no_of_cities);

    // take cost matrix
    int **cost_matrix = calloc(no_of_cities, sizeof(int *));
    for(int i=0;i<no_of_cities;i++){
        cost_matrix[i]= calloc(no_of_cities, sizeof(int));
    }

    printf("Enter Cost Matrix: \n");

    for (int i = 0; i < no_of_cities; i++){
        for (int j = 0; j < no_of_cities; j++){
            scanf("%d", &cost_matrix[i][j]);
        }        
    }

    int *visited_cities = calloc(no_of_cities, sizeof(int));

    int starting_city = 0;
    printf("Enter the Starting City: \n");
    scanf("%d", &starting_city);
    starting_city--;
    
    // Output
    printf("\nTravelling Path is: \n");
    minimum_cost(starting_city, no_of_cities, visited_cities, cost_matrix, starting_city);
    printf("\nTravelling Cost is: %d\n", cost);

    return 0;
}