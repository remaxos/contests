#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAXT 100
#define MAXN 20000
#define MAXL 100


typedef struct sol {
    int order;
    int value;
}sol;


int compar(const void *a, const void *b) 
{
    sol *aa = (sol *)a;
    sol *bb = (sol *)b;

    return aa->value > bb->value;
}

int main()
{
    int T;
    int i, j;
    int L;
    int N;

    unsigned long int l[MAXL];

    sol s1[MAXL + 1];
    sol s2[MAXL + 1];
    int ls[MAXL + 1];
    int sol1 = 1;
    int sol2 = 1;

    int order[26];

    int prime[MAXN];
    for (i = 0; i <= MAXN; i++) {
	prime[i] = 1;
    }
    
    for (i = 2; i <= sqrt(MAXN); i++) {
	if (prime[i]) {
	    for (j = i * i; j <= MAXN; j += i)
		prime[j] = 0;
	}
    }
    
#if 0
    for (i = 2; i <= MAXN; i++) {
	if (prime[i]) 
	    printf("%d\n", i);
    }
#endif

    scanf("%d", &T);
    //printf("%d\n", T);


    for (i = 0; i < T; i++) {
	memset(l, 0, sizeof(unsigned long int) * MAXL);
	memset(s1, 0, sizeof(int) * (MAXL + 1));
	memset(s2, 0, sizeof(int) * (MAXL + 1));
	memset(ls, 0, sizeof(int) * (MAXL + 1));
	sol1 = 1;
	sol2 = 1;


	for (j = 0; j < 26; j++) {
	    order[j] = j;
	}

	scanf("%d %d\n", &N, &L);
	//printf("%d %d\n", N, L);

	for (j = 0; j < L; j++) {
	   scanf("%lu", l + j);
	   //printf("%lu ", l[j]);
	}
	//printf("\n");


	for (unsigned long int k = 2; k <= MAXN; k++) {
	    if (prime[k] && (l[0] % k == 0) && prime[l[0] / k]) {
		//printf("%ld %ld\n", k, l[0] / k);
		s1[0].order = 0;
		s1[0].value = k;

		s1[1].order = 1;
		s1[1].value = l[0] / k;

		s2[0].order = 0;
		s2[0].value = l[0] / k;

		s2[1].order = 1;
		s2[1].value = k;
		break;
	    }

	}

	//sol 1
	for (j = 1; j < L; j++) {
	    if (l[j] % s1[j].value == 0) {
		s1[j + 1].order = j + 1;
		s1[j + 1].value = l[j] / s1[j].value;
	    } else {
		sol1 = 0;
		break;
	    }
	}

	if (sol1) {
#if 0
	    for (j = 0; j < L + 1; j++) {
		printf("(%d, %d) ", s1[j].order, s1[j].value);
	    }
	    printf("\n");
#endif

	    qsort(s1, L + 1, sizeof(sol), compar);
#if 0
	    for (j = 0; j < L + 1; j++) {
		printf("(%d, %d) ", s1[j].order, s1[j].value);
	    }
	    printf("\n");
#endif

	    int prev_val = 0;
	    int letter = 0;
	    for (j = 0; j < L + 1; j++) {
		if (prev_val != s1[j].value)
		    letter++;

		ls[s1[j].order] = letter;
		prev_val = s1[j].value;
	    }

	    printf("Case #%d: ", i + 1);
	    for (j = 0; j < L + 1; j++) {
		printf("%c", ls[j] + 64);
	    }
	    //printf(" %d\n", j);
	    printf("\n");
	    continue;
	}

	//printf("2nd\n");

	for (j = 1; j < L; j++) {
	    if (l[j] % s2[j].value == 0) {
		s2[j + 1].order = j + 1;
		s2[j + 1].value = l[j] / s2[j].value;
	    } else {
		//printf("l[%d] = %lu s2[%d].value=%d\n", j, l[j], j, s2[j].value);
		sol2 = 0;
		break;
	    }
	}

	//printf("sol2=%d\n", sol2);

	if (sol2) {

	    qsort(s2, L + 1, sizeof(sol), compar);

	    int prev_val = 0;
	    int letter = 0;
	    for (j = 0; j < L + 1; j++) {
		if (prev_val != s2[j].value)
		    letter++;

		ls[s2[j].order] = letter;
		prev_val = s2[j].value;
	    }

	    printf("Case #%d: ", i + 1);
	    for (j = 0; j < L + 1; j++) {
		printf("%c", ls[j] + 64);
	    }
	    printf("\n");
	}
    }

    return 0;
}
