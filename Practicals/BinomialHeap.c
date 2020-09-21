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

    // algorithm at http://staff.ustc.edu.cn/~csli/graduate/algorithms/book6/chap20.htm
    // https://gist.github.com/chinchila/81a4c9bfd852e775f2bdf68339d212a2
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


void insert_in_heap( heap_t *heap, int value )
{
	node_t *node = create_node( value );
	heap_t *temp = create_head();
	temp->head = node;
	heap->head = heap_union( heap, temp );
	free( temp );
    printf("Done\n");
}


int main(){
    heap_t *heap = create_head();
    
    // take user input and create insert into heap
    int n;
    printf("Enter the number of elements: \n");
    scanf("%d",&n);

    printf("Start entering numbers to insert into binomail heap:");
    for (int i; i<n;i++){
        int value;
        scanf("%d",&value);
        insert_in_heap(heap, value);
    }
    
    return 0;
}