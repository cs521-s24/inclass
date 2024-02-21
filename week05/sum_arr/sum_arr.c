#include <stdio.h>
#include <stdlib.h>

#define MAX_ARR 32

int sum_arr(int *arr, int start, int end) {
    // Base case
    if (start == end - 1) {
        return arr[start];
    }

    // Recursive case
    return arr[start] + sum_arr(arr, start + 1, end);
}

int main(int argc, char *argv[]) {
    int arr[MAX_ARR];
    for (int i = 1; i < argc; i++) {
        // atoi() converts a char* to an int, base 10
        arr[i - 1] = atoi(argv[i]);
    }

    int sum = sum_arr(arr, 0, argc - 1);
    printf("sum: %d\n", sum);

    return 0;
}
