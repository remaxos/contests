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
char** split_string(char*);

#define MAX 100001

// Complete the maxSubsetSum function below.
int maxSubsetSum(int arr_count, int* arr) {
    int i, j;

    int S[MAX][MAX];

    //memset(S, 0, sizeof(int) * MAX * MAX);

    for (i = 0; i < arr_count; i++) {       
        for (j = 0; j < arr_count; j++) {
            S[i][j] = 0;
        }
    }

#if 0
    printf("arr_count:%d\n", arr_count);
    for (i = 0; i < arr_count; i++) {
        printf("%d\n", i);
        for (j = 0; j < arr_count; j++) {
            //printf("    %d %ld", j, S[i][j]);
        }
    }


    for (i = 0; i < arr_count; i++) {
        S[i][i] = arr[i];
        S[i][i + 1] = arr[i] > arr[i + 1] ? arr[i] : arr[i + 1]; 
        for (j = i + 2; j < arr_count; j++) {
            if (arr[j] > 0)
                S[i][j] = arr[j] + S[i][j - 2];
            else
                S[i][j] = S[i][j - 2];
        }
    }

    for (i = 0; i < arr_count; i++) {
        printf("\n");
        for (j = 0; j < arr_count; j++) {
            printf("%ld ", S[i][j]);
        }
    }
#endif
    return 0;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");
    FILE* fin = fopen("data.in", "r");

    char* n_endptr;
    char n_str[1000];
    fscanf(fin, "%s", n_str);
    
    printf("%s\n", n_str);

    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    char str[1000];
    fscanf(fin, "%s", str);
    printf("%s\n", str);

    char** arr_temp = split_string(str);

    int* arr = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        char* arr_item_endptr;
        char* arr_item_str = *(arr_temp + i);
        int arr_item = strtol(arr_item_str, &arr_item_endptr, 10);

        if (arr_item_endptr == arr_item_str || *arr_item_endptr != '\0') { exit(EXIT_FAILURE); }

        *(arr + i) = arr_item;
    }

    int arr_count = n;

    int res = maxSubsetSum(arr_count, arr);

    fprintf(fptr, "%d\n", res);

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

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!line) {
            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);
    } else {
        data = realloc(data, data_length + 1);

        data[data_length] = '\0';
    }

    return data;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);

        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}

