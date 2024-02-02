#include <stdio.h>
#include <string.h>

void overrun_cpy(char *str, int max) {
    strncpy(str, "bar", max);
    printf("init using strcpy: %s\n", str);
}

void overrun_cat(char *str, int max) {
    strncat(str, "barlskdjf sldkjf lsdkjf lsdkjf", max);
}

int main(int argc, char *argv[]) {
    char buf[4]; // uninitialized memory

    buf[0] = 'f';
    buf[1] = 'o';
    buf[2] = 'o';
    buf[3] = '\0';
    printf("init by chars: %s\n", buf);

    overrun_cpy(buf, sizeof(buf) - 1);

    // read contents of buf
    printf("char by char: ");
    for (int i = 0; i < 32; i++) {
        printf("%d\n", buf[i]);
    }

    char *p = buf;
    p[0] = 'x';
    *p = 'y';
    char ch = *p;

    char *p2 = p; // does not alloc. ref to same buf mem
}
