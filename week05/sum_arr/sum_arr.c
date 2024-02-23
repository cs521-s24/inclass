#include <stdio.h>
#include <stdlib.h>

#define MAX_ARR 32

int sum_arr(int *arr, int start, int end) {
    // Base case
    if (start == end) {
        return arr[start];
    }

    // Recursive case
    return arr[start] + sum_arr(arr, start + 1, end);
}

int main(int argc, char *argv[]) {
    int arr[MAX_ARR];
    int i;
    for (i = 0; i < argc - 1; i++) {
        // atoi() converts a char* to an int, base 10
        arr[i] = atoi(argv[i + 1]);
    }

    int sum = sum_arr(arr, 0, i - 1);
    printf("sum: %d\n", sum);

    return 0;
}
