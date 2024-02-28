#include <stdio.h>
#include <stdlib.h>

#include "rarray.h"
#include "util.h"

void test1(int len, char *arr[]) {
    struct rarray *ra = rarray_alloc(sizeof(int));
    rarray_verbose(ra, true);
    rarray_capacity(ra);
    rarray_size(ra);
    rarray_free(ra);
}

void test2(int len, char *arr[]) {
    struct rarray *ra = rarray_alloc(sizeof(int));
    rarray_verbose(ra, true);

    for (int i = 0; i < len; i++) {
        int i = atoi(arr[i]);
        rarray_append(ra, &i);
    }
    rarray_capacity(ra);
    rarray_size(ra);
    rarray_free(ra);
}

void test3(int len, char *arr[]) {
}

void test4(int len, char *arr[]) {
}

int main(int argc, char *argv[]) {
    if (argc < 2)
        fatal("Usage: %s <test number> [elem1 elem2 ...]");

    int arr_len = argc - 2;
    char **arr = &argv[2];

    switch (argv[1][0]) {
    case '1':
        test1(arr_len, arr);
        break;
    case '2':
        test2(arr_len, arr);
        break;
    case '3':
        test3(arr_len, arr);
        break;
    case '4':
        test4(arr_len, arr);
        break;
    default:
        fatal("unhandled test number");
    }
}
