#include <stdio.h>
#include <string.h>

#define MAXTEST 100
#define MAXSIZE 50000

int main()
{
    int T;
    int N[MAXTEST];
    char path[2 * MAXSIZE - 1];
    int p[2 * MAXSIZE - 2];
    int z[2 * MAXSIZE - 2];
    char rez[2 * MAXSIZE - 1];
    int rezlen;
    int plen;
    int i, j, k;
    char c;


    scanf("%d\n", &T);
    //printf("%d\n", T);

    for (i = 0; i < T; i++) {
	memset(path, 0, sizeof(char) * (2 * MAXSIZE - 1));

	scanf("%d\n", N + i);	
	//printf("%d\n", N[i]);

	scanf("%s\n", path);
	//printf("%s\n", path);

	int south = 0;
	int right = 0;
	plen = 0;
	for (j = 0; j < strlen(path); j++) {
	    if (south == right) {
		p[plen] = south;
		if (path[j] == 'S')
		    z[plen] = 0;
		else
		    z[plen] = 1;

		plen++;
	    } 

	    if (path[j] == 'S') {
		south++;
	    } else {
		right++;
	    }
	}

	p[plen] = south;
	z[plen++] = 2;

	memset(rez, 0, sizeof(char) * (2 * MAXSIZE - 1));
	rezlen = 0;

	//printf("inflx:\n");
	for (j = 0; j < plen - 1; j++) {
	    int tmp;
	    //printf("(%d, %d) ->", p[j], z[j]);

	    tmp = p[j + 1] - p[j];
	    //printf("%d ", tmp);
	    if (z[j] == 0) {
		for (k = 0; k < tmp; k++) {
		    rez[rezlen++] = 'E';
		}
		for (k = 0; k < tmp; k++) {
		    rez[rezlen++] = 'S';
		}
	    } else {
		for (k = 0; k < tmp; k++) {
		    rez[rezlen++] = 'S';
		}
		for (k = 0; k < tmp; k++) {
		    rez[rezlen++] = 'E';
		}
	    }
	    //printf("[%s]\n", rez);

	}

	printf("Case #%d: %s\n", i + 1, rez);
    }

    return 0;
}
