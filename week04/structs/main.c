#include <stdio.h>
#include <string.h>

#include "main.h"

// Pass a names_t "by value"
void print_names_val(struct names_t name) {
    printf("first: %s\n", name.first);
    printf("last: %s\n", name.last);
    strncpy(name.first, "foo", 3);
}

// Pass a names_t "by reference"
void print_names(struct names_t *name) {
    printf("first: %s\n", name->first);
    printf("last: %s\n", name->last);
}

int main(int argc, char *argv[]) {
    int count = (argc - 1) / 2;
    struct names_t names[count];
    memset(names, 0, sizeof(struct names_t) * count);

    for (int i = 0; i < count; i++) {
        strncpy(names[i].first, argv[(i * 2) + 1], NAME_LEN);
        strncpy(names[i].last, argv[(i * 2) + 2], NAME_LEN);
    }

    // print_names(&names[0]);
    // print_names(&names[0]);

    print_names_val(names[0]);
    print_names_val(names[0]);

    return 0;
}
