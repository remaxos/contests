#include <stdio.h>

#define MAX 10001

int main(void) {
#if 0
    int t;
    long n;
    long i, j;
    int found;
    long dory;
    int mark;
    char marked_cities[MAX];
    
    FILE *f = fopen("input00.txt", "r");

    fscanf(f, "%d", &t);
    printf("t=%d\n", t);
    for (i = 0; i < t; i++) {
        fscanf(f, "%ld", &n);
        printf("N=%d\n", n);

        for (j = 0; j < MAX; j++)
            marked_cities[j] = 0;
        found = 0;
        dory = 0;
        mark = 0;
        while (!found) {
            
            if (!mark) {
                mark = 1;
            } else {
                marked_cities[dory] = 1;
                mark = 0;
            }
            
            long next_city = -1;
            for (j = dory + 1; j < n; j++) {
                if (marked_cities[j] == 0) {
                    next_city = j;
                    break;
                }
            }
           
            if (next_city == -1) {
                for (j = 0; j <= dory; j++) {
                    if (marked_cities[j] == 0) {
                        next_city = j;
                        break;
                    }
                }
            }
            
            //printf("    %d mark:%d next:%d\n", dory, mark, next_city);
            if (next_city == -1) {
                printf("%ld", dory + 1);
                found = 1;
            } else {
                dory = next_city;
            }
        }
    }
#endif
        
    return 0;
}
