#include <stdio.h>
#include <string.h>

#define ARR_LEN 64

void print_str(char *s) {
    s[0] = 'x';
    printf("s: %s\n", s);

    int sz = sizeof(s); // 8, probably not what you want
}

int main(int argc, char *argv[]) {
    // These string literals are allocated in global data
    // They can not be modified
    char *passwords[3] = {"password", "foobar", "niners"};

    // char *p = malloc(32);
    // int sz = sizeof(p);

    char buf[ARR_LEN + 1];
    printf("buf: %p\n", buf);
    strncpy(buf, passwords[0], ARR_LEN);
    strncat(buf, "hello there happy C programmers", ARR_LEN - strlen(buf));

    print_str(buf);

    // int len = strlen(passwords[0]);
    // char buffer[len + 1];
    // strncpy(buffer, "hello", len);
    // printf("buffer: %s\n", buffer);

    // passwords[0][0] = 'x';

    return 0;
}
