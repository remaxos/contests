#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAXT 100
#define MAXR 20
#define MAXC 20

int v[MAXR][MAXC];

int T, R, C;

int group(int ai, int aj, int bi, int bj)
{
    if (ai == -1 && aj == -1)
	return 0;

    if (ai == bi)
	return 1;

    if (aj == bj)
	return 1;

    if ((ai - aj) == (bi - bj))
	return 1;

    if ((ai + aj) == (bi + bj))
	return 1;

    return 0;
}

typedef struct point {
    int x;
    int y;
} point;

typedef struct down {
    int *v;
    int ci, cj;
    point *sol; 

    int soli[MAXR * MAXC];
    int solj[MAXR * MAXC];
    int len;
} down;


typedef struct up {
    int sol; 
} up;


up *rec(down *d)
{
    int i, j;
    int final;
    int found;
    up *u;

#if 0
    for (i = 0; i < d->len; i++) {
	printf("(%d,%d) ", d->soli[i], d->solj[i]);
    }
    printf("\n");

    sleep(1);
#endif

    u = (up *)malloc(sizeof(up));
    u->sol = 0;

    if (d->len == R * C) {
	printf("POSSIBLE\n");

	for (i = 0; i < d->len; i++) {
	    printf("%d %d\n", d->soli[i] + 1, d->solj[i] + 1);
	}

	u->sol = 1;
	return u;
    }

    found = 0;
    for (i = 0; i < R; i++) {
	for (j = 0; j < C; j++) {
	    if (!group(d->ci, d->cj, i, j) && !*(d->v + i * MAXR + j)) {
		found = 1;

		down *dn = (down *)malloc(sizeof(down));		
		dn->ci = i;
		dn->cj = j;
		dn->v = (int *)malloc(sizeof(int) * MAXR * MAXC);
		memcpy(dn->v, d->v, sizeof(int) * MAXR * MAXC);

		memcpy(dn->soli, d->soli, sizeof(int) * MAXR * MAXC);
		memcpy(dn->solj, d->solj, sizeof(int) * MAXR * MAXC);
		dn->len = d->len;

		dn->soli[dn->len] = i;
		dn->solj[dn->len] = j;
		dn->len++;
		*(dn->v + i * MAXR + j) = 1;

		up *un = rec(dn);
		if (un->sol) {
		    u->sol = un->sol;
		    free(un);
		    goto out;
		} else {
		    free(un);
		}
	    }
	}
    }

    if (!found) {
	u->sol = 0;	
    }

out:
    free(d->v);
    free(d);

    return u;
}


int main()
{
    int i, j;
    int found;
    int valid;
    int len;
    int t;
    
    int ci, cj;

    memset(v, 0, sizeof(int) * MAXR * MAXC);

    scanf("%d", &T);
    t = 0;

    while(t < T) {
	scanf("%d %d\n", &R, &C);
	
	down *d = (down *)malloc(sizeof(down));
	d->ci = -1;
	d->cj = -1;

	memset(d->soli, 0, sizeof(int) * MAXR * MAXC);
	memset(d->solj, 0, sizeof(int) * MAXR * MAXC);
	d->len = 0;

	d->v = (int *)malloc(sizeof(int) * MAXR * MAXC);
	memset(d->v, 0, sizeof(int) * MAXR * MAXC);

	printf("Case #%d: ", t + 1);
	fflush(stdout);
	up *u = rec(d);
	if (u->sol == 0) {
	    printf("IMPOSSIBLE\n");
	}

#if 0
	found = 1;
	ci = cj = 0; /* start from 0 */
	soli[0] = solj[0] = 0;
	//v[0][0] = 1;
	len = 1;
	while(found) {
	    found = 0; 
	    for (i = 0; i < R; i++) {
		for (j = 0; j < C; j++) {
		    if (!group(ci, cj, i, j) && !v[i][j]) {
			ci = i;
			cj = j;

			soli[len] = i;
			solj[len] = j;
			len++;
			v[i][j] = 1;
			found = 1;
		    }
		}
	    }
	}

	valid = 1;	
	for (i = 0; i < R; i++) {
	    if (valid == 0)
		break;

	    for (j = 0; j < C; j++) {
		if (!v[i][j]) {
		    valid = 0;
		    break;
		}
	    }
	}
	if (valid == 0)
	    printf("invalid\n");
	else {
	    printf("valid\n");
	    for (i = 0; i < R * C; i++) {
		printf("%d %d\n", soli[i], solj[i]);
	    }
	}
#endif

	t++;
    }


    return 0;
}
