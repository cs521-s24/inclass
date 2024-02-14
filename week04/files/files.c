#include <stdio.h>
#include <string.h>

int main(int main, char *argv[]) {
    FILE *f = fopen("foo", "w");
    if (!f) {
        printf("fopen failed!\n");
    }

    char *p = "foo";
    int nwritten = fwrite(p, sizeof(char), strlen(p), f);
    if (nwritten != strlen(p)) {
        printf("fwrite failed!\n");
    }
    fclose(f);
}
