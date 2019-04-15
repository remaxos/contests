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
    FILE *f = fopen("debug.txt", "w");

    int t;
    scanf("%d %d %d", &T, &N, &M); 
    fprintf(f, "T=%d\n", T);
    fprintf(f, "N=%d\n", N);
    fprintf(f, "M=%d\n", M);
    fflush(f);

    int i, j;
    int res;
    int rindex;

    t = 0; 
    while (t < T) {
	for (i = 0; i < N; i++) {

	    memset(l1, 0, sizeof(char) * 10000);
	    memset(l2, 0, sizeof(char) * 10000);

	    for (j = 0; j < 18; j++) {
		sprintf(l1, "%s %d", l1, p[i % 7]);
	    }
	    //sprintf(l1, "%s\n", l1);

	    fprintf(f, "Q:%s\n", l1);
	    fflush(f);

	    printf("%s\n", l1);
	    fflush(stdout);

	    //scanf("%s\n", l2);

	    //fprintf(f, "R: %s\n", l2);
	    //fflush(f);

	    rindex = 0;
	    fprintf(f, "R: ");
	    for (j = 0; j < 18; j++) {
		scanf("%d", &R[i][j]);
		//sscanf(l2 + rindex, "%d", &R[i][j]);
		//fprintf(f, "%s\n", l2 + rindex);
		//rindex += letters(R[i][j]) + 1;
		fprintf(f, "%d ", R[i][j]);
	    }

	    fprintf(f, "\n");
	    fflush(f);
	}

	printf("100\n");
	fflush(stdout);
	scanf("%d", &res);

	fprintf(f, "%d\n", res);

	t++;
    }

    fclose(f);

    return 0;
}
