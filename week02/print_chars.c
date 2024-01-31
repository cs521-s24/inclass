#include <stdio.h>

void print_chars2(char *s) {
    // A pointer is just an address
    // An address is just a number
    do {
        printf("%c\n", *s);
        s++;
    } while (*s != '\0');
}

void print_chars(char *s) {
    // shows how pointers and arrays are the same thing
    int i = 0;
    do {
        printf("%c\n", s[i]);
        i++;
    } while (s[i] != '\0');
}

int main(int argc, char *argv[]) {
    print_chars2(argv[0]);
    return 0;
}
