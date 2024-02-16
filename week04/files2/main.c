#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char *fname = argv[1];
    char *data = argv[2];

    // mode "w" means "write"
    // absence of "b" (binary) means "text"

    FILE *f = fopen(fname, "w+");
    if (!f) {
        // perror() prints a human-readable version of errno
        perror("fopen");
        exit(-1);
    }

    size_t nwritten = fwrite(data, sizeof(*data), strlen(data), f);
    printf("nwritten: %ld\n", nwritten);

    // Move f's cursor back to the start so we can fread()
    fseek(f, 0, SEEK_SET);

    size_t len = strlen(data);
    char buf[len + 1];
    buf[len] = '\0';

    size_t nread = fread(buf, sizeof(buf[0]), len, f);
    printf("nread: %ld\n", nread);
    printf("buf: %s\n", buf);

    fclose(f);
}
