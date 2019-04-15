#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();

// Complete the twoStrings function below.

// Please either make the string static or allocate on the heap. For example,
// static char str[] = "hello world";
// return str;
//
// OR
//
// char* str = "hello world";
// return str;
//
int dm[255];

char* twoStrings_v1(char* s1, char* s2) {
    
    int i;
    char *yes = "YES";
    char *no = "NO";
    
    for (i = 0; i < 255; i++) {
        dm[i] = 0;
    }

    for (i = 0; i < strlen(s1); i++) {
        dm[s1[i]]++;
    }

    for (i = 0; i < strlen(s2); i++) {
        if (dm[s2[i]]) {
            return yes;
        }
    }

    return no;
}

char* twoStrings(char* s1, char* s2) {
    
    char i;
    int j;
    char *yes = "YES";
    char *no = "NO";
    int found_in_first = 0;
    int found_in_second = 0;
    
    for (i = 'a'; i <= 'z'; i++) {
	found_in_first = 0;
	found_in_second = 0;
	    
        for (j = 0; j < strlen(s1); j++) {
	     if (s1[j] == i)
 	         found_in_first = 1;
	}

	for (j = 0; j < strlen(s2); j++) {
	     if (s2[j] == i)
 	         found_in_second = 1;
	}

	if (found_in_first == 1 && found_in_second == 1)
	    return yes;
    }

    return no;
}

int main()
{
    FILE* fin = fopen("input04.txt", "r");
    FILE* fptr = fopen("result", "w");


    long q, q_itr;
    char* q_endptr;
    fscanf(fin, "%ld", &q);
    char s1[100000];
    char s2[100000];

    for (int q_itr = 0; q_itr < q; q_itr++) {
        fscanf(fin, "%s", s1);
	//printf("l=%ld\n", strlen(s1));
        fscanf(fin, "%s", s2);
	//printf("l=%ld\n", strlen(s2));

        char* result = twoStrings(s1, s2);
        printf("%s\n", result);
    }

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}

