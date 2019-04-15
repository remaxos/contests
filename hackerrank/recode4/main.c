#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX 2000001

long tastiness(char *s) {
    int i;
    long left_cakes = 0;
    long right_pies = 0;
    
    long total = 0;
    
    for (i = 0; i < strlen(s); i++) {
        if (s[i] == 'c') {
            left_cakes++;
        } else {
            total += left_cakes;
        }
    }
    
    
    for (i = strlen(s) - 1; i >= 0; i--) {
        if (s[i] == 'p') {
            right_pies++;
        } else {
            total += right_pies;
        }
    }
    
    return total;
}

int main() {
    int i;
    char s[MAX];
    scanf("%s", s);
    
    //printf("%d", tastiness(s));
    
    long first_cake = -1;
    long last_pie = -1;

    long before_swap_tastiness = tastiness(s);
    
    for (i = 0; i < strlen(s); i++) {
        if (s[i] == 'c' && first_cake == -1) {
            first_cake = i;
        } 
        
        if (s[i] == 'p') {
            last_pie = i;
        }
    }
    
    //printf("%d %d", first_cake, last_pie);
    
    if (first_cake == -1 || last_pie == -1) {
        printf("%ld", tastiness(s));
        return 0;
    }

    s[first_cake] = 'p';
    s[last_pie] = 'c';
    
    long after_swap_tastiness = tastiness(s);

    if (after_swap_tastiness < before_swap_tastiness) 
	    printf("%ld", after_swap_tastiness);
    else
	    printf("%ld", before_swap_tastiness);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
