#include<stdio.h>
#include<stdlib.h>

typedef struct node_t {
	int value;
	int degree;
	struct node_t *child;
	struct node_t *parent;
	struct node_t *brother;
} node_t;

typedef struct heap_t {
	node_t *head;
} heap_t;

node_t *create_node( int value )
{
	node_t *node = malloc( sizeof ( node_t ) );
	node->value = value;
	node->degree = 0;
    node->brother = NULL;
    node->parent = NULL;
    node->child = NULL;
	return node;
}

heap_t *create_head()
{
	heap_t *heap = malloc( sizeof ( heap_t ) );
	heap->head = NULL;
	return heap;
}

node_t *heap_merge(heap_t *heap1, heap_t *heap2){
    if (heap1->head == NULL) return heap2->head;
    if (heap2->head == NULL) return heap1->head;

    node_t *head;
    node_t *h1_iter = heap1->head;
    node_t *h2_iter = heap2->head;
    node_t *tail;

    if (heap1->head->degree <= heap2->head->degree){
        head = heap1->head;
        h1_iter = h1_iter->brother;
    }
    else{
        head = heap2->head;
		h2_iter = h2_iter->brother;
    }
    tail = head;

    while(h1_iter != NULL && h2_iter != NULL){
        if(h1_iter->degree <= h2_iter->degree){
            tail->brother = h1_iter;
            h1_iter = h1_iter->brother;
        }
        else{
            tail->brother = h2_iter;
            h2_iter = h2_iter->brother;
        }
        tail = tail->brother;
    }

    tail->brother = (h1_iter != NULL) ? h1_iter : h2_iter;

    return head;
}

node_t *heap_union(heap_t *original, heap_t *new){

    node_t *new_head = heap_merge( original, new );

    original = NULL;
    new = NULL;

    if (new_head == NULL){
        return new_head;
    }

    node_t *prev = NULL;
    node_t *x = new_head;
    node_t *next = new_head->brother;

    while( next != NULL){
        if((x->degree != next->degree) || (next->brother!=NULL && (next->brother->degree == x->degree))){
            prev = x;
			x = next;
        }
        else
		{
            if( x->value < next->value )
			{
				x->brother = next->brother;
				next->parent = x;
				next->brother = x->child;
				x->child = next;
				x->degree++;
			}
			else
			{
				if( prev == NULL )
					new_head = next;
				else
					prev->brother = next;

				x->parent = next;
				x->brother = next->child;
				next->child = x;
				next->degree++;

				x = next;
			}
		}

		next = x->brother;
        }

	return new_head;

}

void heap_remove( heap_t *heap, node_t *head, node_t *bef ){
    if( head == heap->head )
		heap->head = head->brother;
	else
		bef->brother = head->brother;

    node_t *new_head = NULL;
    node_t *child = head->child;

    while (child != NULL)
    {
        node_t *next = child->brother;
        child->brother = new_head;
        child->parent = NULL;
        new_head = child;
        child = next;
    }

    heap_t *temp= create_head();
    temp->head = new_head;
    heap->head = heap_union( heap, temp );
	free( temp );    
}

node_t *heap_min(heap_t *heap){
    if(heap->head == NULL) return NULL;

    node_t *min = heap->head;
    node_t *min_prev = NULL;
    node_t *next = min->brother;
    node_t *next_prev = min;

    while( next != NULL){
        if (next -> value < min->value){
            min = next;
            min_prev = next_prev;
        }

        next_prev = next;
        next = next->brother;
    }

    heap_remove(heap, min, min_prev);
    return min;
}


void insert_in_heap( heap_t *heap, int value )
{
	node_t *node = create_node( value );
	heap_t *temp = create_head();
	temp->head = node;
	heap->head = heap_union( heap, temp );
	free( temp );
    printf("Done\n");
}

void heap_free( heap_t *h )
{
	while( heap_min( h ) );
	free( h );
}

struct node_t* find_node(struct node_t* heap, int k) {
    struct node_t* x = heap;
    struct node_t* found = NULL;
    if (x->value == k) {
        found = x;
        return found;
    }
    if (x->child != NULL && found == NULL) {
        found = find_node(x->child, k);
    }
 
    if (x->brother != NULL && found == NULL) {
        found = find_node(x->brother, k);
    }
    return found;
}

int heap_decrease_key(struct heap_t* H, int i, int k) {
    int temp;
    struct node_t* p;
    struct node_t* y;
    struct node_t* z;
    p = find_node(H->head, i);
    if (p == NULL) {
        printf("\nInvalid Key");
        return 0;
    }
    if (k > p->value) {
        printf("\nNew Key is greater than available one.");
        return 0;
    }
    p->value = k;
    y = p;
    z = p->parent;
    while (z != NULL && y->value < z->value) {
        temp = y->value;
        y->value = z->value;
        z->value = temp;
        y = z;
        z = z->parent;
    }
    printf("\nKEY REDUCED SUCCESSFULLY!");
}

int delete_node(struct heap_t* H, int k) {
    struct node_t* np;
    if (H->head == NULL) {
        printf("\nHEAP EMPTY");
        return 0;
    }
 
    heap_decrease_key(H, k, -1000);
    np = heap_min(H);
    if (np != NULL)
        printf("\nNODE DELETED SUCCESSFULLY");
    return 0;
}


int main(){
    heap_t *heap = create_head();
    
    // take user input and create insert into heap
    int n;
    
    printf("\n1: Insert element");
    printf("\n2: Extract minimum");
    printf("\n3. Delete a node");
    printf("\n0: Exit");
    printf("\n==================");
    
    while (1)
    {
        int a;
        printf("\nEnter Your choice: ");
        scanf("%d", &a);

        switch (a)
        {
        case 0:
            printf("\nExiting!\n");
            heap_free( heap );
            return 0;
        
        case 1:
            printf("\nEnter the integer to input: ");
            int temp;
            scanf("%d", &temp);
            insert_in_heap(heap, temp);
            break;

        case 2:
            printf("\nMinimum Element: ");
            node_t *min = heap_min( heap );
            if( min != NULL ) printf( "%d\n", min->value );
            break;

        case 3:
            printf("\nDelete the node: ");
            int abc;
            scanf("%d",&abc);
            delete_node(heap, abc);
            break;

        default:
            printf("\nEnter Correct Option: ");
            break;
        }
    }
    
    
    return 0;
}