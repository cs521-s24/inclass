#include <stdio.h>

int main(int argc, char *argv[]) {
    // char *prog_name = argv[0];

    char foo[] = "foo";
    printf("%s\n", foo);

    char char_arr[5] = {'f', 'o', 'o'};
    printf("%s\n", char_arr);

    for (int i = 0; i < argc; i++) {
        printf("argv[%d] = %s\n", i, argv[i]);
    }
}
