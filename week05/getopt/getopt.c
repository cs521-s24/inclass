#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int o = 0;
    while (-1 != (o = getopt(argc, argv, "abcd:"))) {
        switch (o) {
        case 'a':
            printf("found an a!\n");
            break;
        case 'b':
            printf("found a b!\n");
            break;
        case 'c':
            printf("found a c!\n");
            break;
        case 'd':
            printf("found d = %d\n", atoi(optarg));
            break;
        }
    }

    while (optind < argc) {
        printf("non-option arg: %s\n", argv[optind]);
        optind++;
    }
}
