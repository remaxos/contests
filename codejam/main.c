#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXT 20
#define MAXN 365
#define MAXM 1000001

#define NHOLES 18

int T, N, M;
int p[7] = {2, 3, 5, 7, 11, 13, 17};
int R[MAXN][18];
int Rt[MAXN];
char l1[10000];
char l2[10000];

int letters(int a)
{
    int l = 0;

    while(a) {
	l++;
	a = a / 10;
    }

    return l;
}

int main()
{
    //FILE *f = fopen("debug.txt", "w");

    int t;
    scanf("%d %d %d", &T, &N, &M); 
    //fprintf(f, "T=%d\n", T);
    //fprintf(f, "N=%d\n", N);
    //fprintf(f, "M=%d\n", M);
    //fflush(f);

    int i, j;
    int res;
    int rindex;
    int found;

    t = 0; 
    while (t < T) {
	//fprintf(f, "Test case #%d\n", t);
	//fflush(f);

	for (i = 0; i < N; i++) {

	    memset(l1, 0, sizeof(char) * 10000);
	    memset(l2, 0, sizeof(char) * 10000);

	    for (j = 0; j < 18; j++) {
		sprintf(l1, "%s %d", l1, p[i % 7]);
	    }

	    //fprintf(f, "Q:%s\n", l1);
	    //fflush(f);

	    printf("%s\n", l1);
	    fflush(stdout);

	    rindex = 0;
	    //fprintf(f, "R: ");
	    //fflush(f);
	    for (j = 0; j < 18; j++) {
		scanf("%d", &R[i][j]);
		fflush(stdin);

		//fprintf(f, "%d ", R[i][j]);
		//fflush(f);
	    }

	    //fprintf(f, "\n");
	    //fflush(f);
	}

	for (i = 0; i < 7; i++) {
	    Rt[i] = 0;
	    for (j = 0; j < 18; j++) {
		Rt[i] += R[i][j];
	    }
	}

	for (i = 1; i <= M; i++) {
	    found = 1;
	    for (j = 0; j < 7; j++) {
		if ((i < Rt[j]) || (i - Rt[j]) % p[j]) {
		    found = 0;
		    break;
		}
	    }

	    if (found) {
		printf("%d\n", i);
		fflush(stdout);

		//fprintf(f, "cand: %d\n", i);
		//fflush(f);

		break;
	    }
	}

	scanf("%d", &res);

	//fprintf(f, "res: %d\n", res);
	//fflush(f);

	if (res == -1)
	    return 0;

	t++;
    }

    //fclose(f);

    return 0;
}
