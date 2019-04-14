/* TODO: this document will contain all the useful stuff for quick solving of the 
tedious and repetitive stuff */

/************** LISTS ******************/

/* a more generic list implementation */
typedef struct node {
    void *value;
    struct node *next;
} node;

/* just a basic int list (better than nothing) */
typedef struct node {
    int value;
    struct node *next;
} node;

node *list_add(node *list, int value) {
    node *n;
    node *idx;

    n = (node *)malloc(sizeof(node));
    n->value = value;
    n->next = NULL;

    if (list == NULL) {
        return n; 
    }

    idx = list;
    while (idx->next != NULL) {
        idx = idx->next;
    }

    idx->next = n;

    return list;
}

node *list_search(node *list, int value) {
    node *idx;

    idx = list;
    while (idx) {
        if (idx->value == value)
            return idx;

        idx = idx->next;
    }

    return NULL;
}

node *list_del(node *list, node *n) {
    node *idx;

    if (list == n) {
        node *ret = list->next;
        free(list);

        return ret;
    }

    idx = list;
    while (idx->next) {
        if (idx->next == n) {
            idx->next = idx->next->next;
            free(n);
            return list;
        }

        idx = idx->next;
    }

    return list;
}

void list_print(node *list) {
    node *idx;

    idx = list;

    printf("\n[");
    while(idx) {
        printf("%d ", idx->value); 
        idx = idx->next;
    }
    printf("]\n");
}

void list_fprint(node *list, FILE *f) {
    node *idx;

    idx = list;

    fprintf(f, "\n[");
    while(idx) {
        fprintf(f, "(%d,%d)", idx->r->a, idx->r->b); 
        idx = idx->next;
    }
    fprintf(f, "]\n");
    fflush(f);
}


/*************** HEAPS *******************/
--> TODO


/************** STRINGS ******************/
--> TODO


/*************** STACK *****************/
#define MAX_STACK 1000000

typedef struct stack {
    void* v[MAX_STACK];
    int top;
} stack;

int push(stack *s, void *elem)
{
    if (s->top == MAX_STACK - 1) {
        printf("BUFFER OVERFLOW\n");
        return -1;
    }

    s->v[s->top++] = elem;
    return 0;
}

int pop(stack *s, void **elem)
{

    if (s->top == 0) {
        printf("BUFFER_UNDERFLOW\n");
        return -1;
    }
    s->top--; 
    *elem = s->v[s->top];
    return 0;
}

int empty(stack *s)
{
    return s->top == 0;
}

int count(stack *s)
{
    return s->top;
}


/* a specific stack implementation (int) */
#define MAX_STACK 1000000

typedef struct stack {
    int v[MAX_STACK];
    int top;
} stack;

int push(stack *s, int elem)
{
    if (s->top == MAX_STACK) {
        printf("BUFFER OVERFLOW\n");
        return -1;
    }

    s->v[s->top] = elem;
    s->top++;
    return 0;
}

int pop(stack *s, int *elem)
{
    if (s->top == 0) {
        printf("BUFFER_UNDERFLOW\n");
        return -1;
    }
    
    s->top--;
    *elem = s->v[s->top];

    return 0;
}

int empty(stack *s)
{
    return s->top == 0;
}

int count(stack *s)
{
    return s->top;
}


/*************** NON-RECURSIVE BACKTRACK **************/

/* pseudocode (using a stack) */
boolean solve(Node n) {
put node n on the stack;
while the stack is not empty {
    if the node at the top of the stack is a leaf {
        if it is a goal node, return true
        else pop it off the stack
    }
    else {
        if the node at the top of the stack has untried children
            push the next untried child onto the stack
        else pop the node off the stack

}
return false
}

/* generic C */


/******************* RECURSIVE BACKTRACK ****************/

/* pseudocode backtrack recursive */
boolean solve(Node n) {
    if n is a leaf node {
        if the leaf is a goal node, return true
        else return false
    } else {
        for each child c of n {
            if solve(c) succeeds, return true
        }
        return false
    }
}

/* generic C */
typedef struct down {
    //TODO
} down;


typedef struct up {
    //TODO
} up;

up *rec(down *d)
{
    int i, j;
    up *u = (up *)malloc(sizeof(up));

#if 0
    //print intermediate solution 

    sleep(1);
#endif

    if (/* final solution */)  {
	//TODO
    }

    for (i = 0; i < /* TODO */; i++) {
	for (j = 0; j < /* TODO */; j++) {
	    if (/* TODO */) {

		down *dn = (down *)malloc(sizeof(down));		
		/* TODO: prepare dn using d*/

		up *un = rec(dn);
		if (/* TODO: analyze un*/) {
		    
		}
	    }
	}
    }

out:
    free(d);

    return u;
}
/*********************************************************/

/************** SORTING ***************/
#include <stdlib.h>

int compar(const void *a, const void *b) 
{
    int *aa = (int *)a;
    int *bb = (int *)b;

    return *aa > *bb;
}

qsort(a, n, sizeof(int), compar);

/************** UTILS ***************/
#define TODO 100
    size_t lnsz = 0;
    char *ser[TODO];

    for (i = 0; i < TODO; i++)
        ser[i] = NULL;

    for (j = 0; j < TODO; j++) {
        getline(&ser[j], &lnsz, fin);
        printf("%d:%s ", j, ser[j]);
    }


