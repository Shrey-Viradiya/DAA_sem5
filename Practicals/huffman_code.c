// Huffman coding in C
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct huffman_node
{
    int frequency;
    char character;
    struct huffman_node * left;
    struct huffman_node * right;
};

typedef struct huffman_node huffman_node;

int left = -1;
int right = -1;
huffman_node priority_queue[256];

void swap(huffman_node *a, huffman_node *b ){
    huffman_node temp = *a;
    *a = *b;
    *b = temp;
}

int max( int a,  int b)
{
    return a > b ? a : b;
}

int huffman_node_height(huffman_node *node)
{
    unsigned int height = 0;
    if (node->left || node->right) {
        height = max(node->left ? huffman_node_height(node->left) : 0,
                node->right ? huffman_node_height(node->right) : 0) + 1;
    }
    return height;
}

void heapify(huffman_node *arr, int n, int i) 
{ 
    int largest = i; // Initialize largest as root 
    int l = 2*i + 1; // left = 2*i + 1 
    int r = 2*i + 2; // right = 2*i + 2 
  
    // If left child has higher frequency than largest 
    if (l < n && arr[left + l].frequency > arr[left + largest].frequency) 
        largest = l; 
  
    // If right child has higher frequency than largest so far 
    if (r < n && arr[left + r].frequency >  arr[left + largest].frequency) 
        largest = r; 
  
    // If small is not root 
    if (largest !=  i) 
    { 
        swap(&arr[left + i], &arr[left + largest]); 
        heapify(arr, n, largest);
    } 
} 
  
// main function to do heap sort 
void heapSort(huffman_node *arr, int n) 
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

void insert_node(int frequency, char character, huffman_node * left_node, huffman_node * right_node){

    if(left == -1 && right == -1){
        huffman_node temp = {frequency, character, left_node, right_node};
        priority_queue[0] = temp;
        left++;
        right++;
        return;
    }
    
    huffman_node temp = {frequency, character, left_node, right_node};
    priority_queue[++right] = temp;
}

huffman_node get_min(){
    heapSort(priority_queue, right - left + 1);

    while (left <= right){
        huffman_node temp = priority_queue[left];
        left ++;
        return temp;
        
    }
}

void print(char letter, const unsigned int *arr, size_t len)
{
    unsigned int i;
    printf("%c: ", letter);
    for (i = 0; i < len; i++) {
        printf("%u", arr[i]);
    }
    putchar('\n');
}

void huffman_node_encodings(huffman_node node, int *arr, int pos)
{
    if (node.left) {
        arr[pos] = 0;
        huffman_node_encodings(*node.left, arr, pos + 1);
    }
    if (node.right) {
        arr[pos] = 1;
        huffman_node_encodings(*node.right, arr, pos + 1);
    }
    if (!(node.left || node.right)) {
        print(node.frequency, arr, pos);
    }
}

void huffman_coding(char *letters, int *frequencies, int size){
    for (int i = 0; i < size; i++)
    {
        insert_node(frequencies[i], letters[i], NULL, NULL);
    }

    while (right - left + 1 != 1)
    {
        huffman_node left_node = get_min();
        huffman_node right_node = get_min();
        insert_node(left_node.frequency + right_node.frequency, '$', &left_node, &left_node);
    }

    huffman_node top = get_min();

    int *arr;
    arr = malloc(huffman_node_height(&top) * sizeof(unsigned int));
    huffman_node_encodings(top, arr, 0);    
}

int main(){

    printf("Huffman Coding\n");
    char letters[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int frequencies[] = {35, 8, 4, 23, 10, 2};
    int size = 6;

    huffman_coding(letters, frequencies, size);
    return 0;
}