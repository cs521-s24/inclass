#include <string.h>

#include "scan.h"

int main(int argc, char *argv[]) {
    struct scan_table_st st;
    scan_table_init(&st);

    char *start = argv[1];
    char *end = argv[1] + strlen(argv[1]);
    scan_table_scan(&st, start, end);

    scan_table_print(&st);
    scan_table_free(&st);
}
