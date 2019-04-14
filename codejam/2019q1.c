/* CodeJam2019.Q.P1 */


#include <stdio.h>
#include <string.h>

#define MAXTESTS 100
#define MAXLEN 100

int main()
{
    int T;
    char N[MAXTESTS][MAXLEN];
    int i, j;

    char A[MAXLEN];
    char B[MAXLEN];
    char B2[MAXLEN];
    int B2_len;

    memset(N, 0, sizeof(char) * MAXTESTS * MAXLEN);
    memset(A, 0, sizeof(char) * MAXLEN);
    memset(B, 0, sizeof(char) * MAXLEN);
    memset(B2, 0, sizeof(char) * MAXLEN);

    scanf("%d\n", &T);

    for (i = 0; i < T; i++) {
	scanf("%s\n", N[i]);	
    }

    for (i = 0; i < T; i++) {
	memset(A, 0, sizeof(char) * MAXLEN);	
	memset(B, 0, sizeof(char) * MAXLEN);	
	memset(B2, 0, sizeof(char) * MAXLEN);	

	//printf("processing %s\n", N[i]);
	
	for (j = strlen(N[i]) - 1; j >= 0; j--) {
	    //printf(" letter: %c\n", N[i][j]);
	    if (N[i][j] != '4') {
		A[j] = N[i][j];
		B[j] = '0';
	    } else {
		A[j] = '2';
		B[j] = '2';
	    }
	}

	B2_len = 0;
	for (j = 0; j < strlen(B); j++) {
	    if (B[j] != '0') {
		B2[B2_len++] = B[j];
	    } else {
		if (B2_len) {
		    B2[B2_len++] = B[j];
		}
	    }
	}

	printf("Case #%d: %s %s\n", i + 1, A, strlen(B2) == 0 ? "0" : B2);
    }

    return 0;
}
