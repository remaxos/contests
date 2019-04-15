// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");
#include <stdlib.h>

typedef struct edge {
    char side; //starting/closing edge
    int point;
} Edge;

#define MAX 2000002 

int compar(const void *a, const void *b)
{
    Edge *ea = (Edge *)a;
    Edge *eb = (Edge *)b;
    
    if (ea->point < eb->point) {
        return 0;
    } else if (ea->point > eb->point) {
        return 1;
    } else {
        if (ea->side < eb->side)
            return 0;
        else
            return 1;
    }
}

int solution(int A[], int N) {
    int i;
    int open;
    int res;
    
    Edge edges[MAX]; 
    
    for (i = 0; i < N; i++) {
        edges[i].side = -1;
        edges[i].point = i - A[i];
        
        edges[i + N].side = 1;
        edges[i + N].point = i + A[i];
    }
    
    qsort(edges, 2 * N, sizeof(Edge), compar);

#if 0
    printf("\n");
    for (i = 0; i < 2 * N; i++) {
        if (edges[i].side == -1)
            printf("[");
        else
            printf("]");
            
        printf("%d ", edges[i].point);
    }
    printf("\n");
#endif
    
    open = 0;
    res = 0;
    for (i = 0; i < 2 * N; i++) {
        if (edges[i].side == -1) {
            open++;
        } else {
            open--;
            res += open;
        }
    }
    
    return res;
}
