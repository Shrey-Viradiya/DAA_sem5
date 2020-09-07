#include <stdio.h>
#include <limits.h>
#include <stdbool.h> 
#include <string.h>

#define V 8

struct edge
{
    int start;
    int end;
    int weight;
};


int graph[V][V];
int left = -1;
int right = -1;
struct edge priority_queue[V*V + 1];
int marked[V][V] = {0};
// array to keep track of selected nodes in MST
int mst_nodes[V];

void swap(struct edge *a, struct edge *b ){
    struct edge temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(struct edge *arr, int n, int i) 
{ 
    int largest = i; // Initialize largest as root 
    int l = 2*i + 1; // left = 2*i + 1 
    int r = 2*i + 2; // right = 2*i + 2 
  
    // If left child has higher weight than largest 
    if (l < n && arr[left + l].weight > arr[left + largest].weight) 
        largest = l; 
  
    // If right child has higher weight than largest so far 
    if (r < n && arr[left + r].weight >  arr[left + largest].weight) 
        largest = r; 
  
    // If small is not root 
    if (largest !=  i) 
    { 
        swap(&arr[left + i], &arr[left + largest]); 
        heapify(arr, n, largest);
    } 
} 
  
// main function to do heap sort 
void heapSort(struct edge *arr, int n) 
{ 
    // Build heap (rearrange array) 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
  
    // One by one extract an element from heap 
    for (int i=n-1; i>0; i--) 
    {         
        swap(&arr[left], &arr[left + i]);
        heapify(arr, i, 0); 
    } 
}


void insert_edge(int start, int end, int weight){
    
    if( marked[start][end]){
        return;
    }

    if(left == -1 && right == -1){
        struct edge temp = {start, end, weight};
        priority_queue[0] = temp;
        left++;
        right++;
        return;
    }    
    
    struct edge temp = {start, end, weight};
    priority_queue[++right] = temp; 
}

struct edge get_min(){
    heapSort(priority_queue, right - left + 1);

    while (left <= right){
        struct edge temp = priority_queue[left];
        left ++;
        if ( mst_nodes[temp.start] && mst_nodes[temp.end] ){
            continue;
        }
        else{
            return temp;
        }
    }
}


// function to get graph
// takes adjacency matrix from user
void get_graph(){
    printf("No of vertices: %d\n", V);
    printf("Enter the adjacency matrix for the graph\n");
    for (int i=0; i<V; i++){
        for( int j = 0; j < V; j++){
            scanf("%d", &graph[i][j]);
        }
    }
}

// function to print graph
// prints adjacency matrix from user
void print_graph(){
    printf("The adjacency matrix for the graph\n");
    for (int i=0; i<V; i++){
        for( int j = 0; j < V; j++){
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main(){

    printf("MST for connected graph: \n");
    get_graph();

    // no of edges
    int no_edge = 0;
    int verbose = 0;

    printf("Verbose Mode: 0 for Off and 1 for On\n");
    scanf("%d",&verbose);

    memset(mst_nodes, false, sizeof(mst_nodes));

    // first node is included in the MST
    mst_nodes[0] = true;


    // In the MST we will have V-1 edges
    // as the number of nodes is V

    

    int total_weight = 0 ;
    printf("Edge --> Weight\n");
    while (no_edge < V-1) { // until the no_edges selected is V-1
        
        int min = INT_MAX;
        int x = 0;
        int y = 0;

        // for all the vertices included in the MST
        // look for all the adjecent vetices and
        // find the minimum edge


        // using priority queue
        if (verbose){
            printf("\n_____PQ______\n");
            for ( int k = left; k <= right; k++){
                printf("\npqn: %d %d %d", priority_queue[k].start, priority_queue[k].end, priority_queue[k].weight);
            }
            printf("\n_____________\n");

            printf("\n____Edge Selection_____\n");
        }
               
        
        for ( int i = 0; i < V; i++){
            if(mst_nodes[i]){
                for (int j = 0; j < V; j++)
                {
                    if (mst_nodes[j] != 1 && graph[i][j])
                    {
                        if (verbose) printf("\n__%d__%d__\n", i,j);
                        insert_edge(i,j,graph[i][j]);
                        marked[i][j] = 1;
                        marked[j][i] = 1;
                    }                   
                }
            }
        }


        if (verbose){
            printf("\n_____PQ______\n");
            for ( int k = left; k <= right; k++){
                printf("\npqn: %d %d %d", priority_queue[k].start, priority_queue[k].end, priority_queue[k].weight);
            }
            printf("\n_____________\n");
        }
        struct edge t = get_min();
        x = t.start;
        y = t.end;
        min = t.weight;

        printf("%d   to   %d --> %d\n", x,y,min);
        mst_nodes[y] = true;
        no_edge++;
        total_weight += min;
    }

    printf("\nTotal Weight: %d", total_weight);

    return 0;

}