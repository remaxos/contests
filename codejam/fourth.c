#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAXT 100
#define MAXN 1024
#define MAXB (MAXN - 1)
#define MAXF

#define MAXANSWER 100

FILE *f;

typedef struct interval {
    int a;
    int b;
} range;



/* a more generic list implementation */
typedef struct node {
    range *r;
    struct node *next;
} node;

node *list_add(node *list, range *r) {
    fprintf(f, "%s\n", __func__);


    node *n;
    node *idx;

    n = (node *)malloc(sizeof(node));
    n->r = r;
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

node *list_search(node *list, range *r) {
    node *idx;

    idx = list;
    while (idx) {
        if (idx->r == r)
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
        printf("(%d,%d)", idx->r->a, idx->r->b); 
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

int main()
{
    int T;
    int N, B, F;
    int i;
    node *w;
    range *r;

    f = fopen("debug.txt", "w");

    char answer[MAXANSWER];

    scanf("%d", &T);
    fprintf(f,"%d\n", T);

    for (i = 0; i < T; i++) {
	
	scanf("%d %d %d", &N, &B, &F);
	
	fprintf(f,"%d %d %d\n", N, B, F);

	r = (range *) malloc(sizeof(range));
	r->a = 0;
	r->b = N - 1;

	w = list_add(w, r);
	fflush(f);

	list_fprint(w, f);	
	while(1) {
	    /* divide entry list */
	    

	    /* construct the string */
	    /* send the string */
	    /* receive answer */
	    /* analyze answer */
	}
	

	/* send answer */
	
	/* receive answer */
	//memset(answer, 0, sizeof(char) * MAXANSWER);
	//scanf("%s", answer);
	//printf("%s\n", answer);


    }

    fclose(f);
    return 0;
}
