/* TODO: let us hope that the link will always work:
 * https://www.hackerrank.com/contests/recode-4/challenges/shinigami-eyes
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAXK 16
#define MAX_DIGITS 5000

char *a[10] = {
    "0"
    "1",
    "10",
    "11",
    "100",
    "101",
    "110",
    "111",
    "1000",
    "1001",
};

void decstr_to_binstr(char *sdec, char *sbin)
{
	int i, j;

	for (int i = 0; i < strlen(sdec); i++) {
				
	}
}

char *bin_add_str(char *s1, char *s2) {
	int i, j;
	int l1 = strlen(s1);
	int l2 = strlen(s2);
	int iter;
	int leftover;
	int lres = l1 > l2 ? l1 : l2;

	printf("%s + %s\n", s1, s2);
	
	char *sres = (char *)malloc(sizeof(char) * (lres + 1));
	memset(sres, 0, sizeof(char) * (lres + 1));

	printf("res=[%s] lres:%d\n", sres, lres);

	leftover = 0;
	for (i = l1 - 1, j = l2 - 1, iter = lres - 1; i >= 0 || j >= 0; i--, j--, iter--) {
		if (i < 0) {
			if (s2[j] == '1') {
				if (leftover)
					sres[iter] = '0';
				else
					sres[iter] = '1';
			} else {
				if (leftover)
					sres[iter] = '1';
				else
					sres[iter] = '0';
			}

			continue;
		} else if (j < 0) {
			if (s1[i] == '1') {
				if (leftover)
					sres[iter] = '0';
				else
					sres[iter] = '1';
			} else {
				if (leftover)
					sres[iter] = '1';
				else
					sres[iter] = '0';
			}

			continue;
		}
			
		printf("   i=%d, j=%d, iter=%d\n", i, j, iter);
		if (s1[i] == '1' && s2[j] == '1') {
			printf("1\n");
			if (leftover) {
				sres[iter] = '1';
			} else {
				sres[iter] = '0';
				leftover = 1;
			}
		} else if ((s1[i] == '0' && s2[j] == '1') || (s1[i] == '1' && s2[j] == '0')) {
			printf("2\n");
			if (leftover) {
				sres[iter] = '0';
			} else {
				sres[iter] = '1';
				leftover = 0;
			}
		} else {
			printf("3\n");
			if (leftover) {
				sres[iter] = '1';
				leftover = 0;
			} else {
				sres[iter] = '0';
			}
		}
	}

	printf("[");
	for (i = 0; i < lres; i++) {
		printf("%c", sres[i]);
	}
	printf("] lres=%d\n", lres);

	/* TODO: leftover = 1 */
	return sres;
}

int main() {
    int t;
    int i, j; 
    int digits;
    char n[MAX_DIGITS];
    char str[1000000];
    long k;


	    char c;

    FILE *f = fopen("input2", "r");

    t = 1;

    fscanf(f, "%d", &t);
    printf("t=%d\n", t);
    
    for (i = 0; i < t; i++) {
        fscanf(f, "%d", &digits);
        fscanf(f, "%ld", &k);
        printf("|n|=%d k=%ld\n", digits, k);
	printf("n=[");
	fscanf(f, "%s", str);
	printf("%s", str);
	printf("]\n");
    }

    char *s1 = "1001";
    char *s2 = "100";

    printf("[%s]\n", bin_add_str(s1, s2));

    fclose(f);
    return 0;
}

