#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10000000

/* TODO: There is a big unresolved mistery here as I am not able to further
 * shrink the time needed for this solution. Therefore, <2s for input04.txt
 * looks like a very wet dream as everything looks indispensible.
 *
 * Maybe there is a mathematical solution!
 */

int main(void) {
    int t;
    long n;
    long i, j;
    int found;
    long dory;
    int mark;
    char *marked_cities = (char *)malloc(sizeof(char) * MAX);
    
    FILE *f = fopen("input04.txt", "r");

    fscanf(f, "%d", &t);
    for (i = 0; i < t; i++) {
        fscanf(f, "%ld", &n);
        //printf("N=%ld\n", n);

        memset(marked_cities, 0, sizeof(char) * MAX);
        dory = 0;
        mark = 0;
        found = 0;
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
            
            //printf("    %ld mark:%d next:%ld\n", dory, mark, next_city);
            if (next_city == -1) {
                printf("%ld\n", dory + 1);
                found = 1;
            } else {
                dory = next_city;
            }
        }
    }
        
    return 0;
}
