#include <stdbool.h>
#include <stdio.h>

#include "scan.h"

/*
    scan_table_new() {
        walk list from head to !next
        calloc new token (calloc zero-initializes)
        link new token to end of list
    }
*/

void scan_table_init(struct scan_table_st *st) {
    st->len = 0;
    st->head = NULL;
}

/*
    scan_intlit() // if start == end
    scan_binlit() // "
    scan_hexlit()
    scan_whitespace() // while *start == ' ' || *start == '\t'
*/
char *scan_symbol(struct scan_token_st *token, char *start, char *end,
                  char ch) {
    token->name[0] = ch;
    switch (ch) {
    case '+':
        token->id = TK_PLUS;
        break;
        //...
    }
    token->name[1] = '\0';

    // return next char to start scanning
    return start + 1;
}

char *scan_one_token(struct scan_token_st *token, char *start, char *end) {
    if (start[0] == '0' && start[1] == 'b') {
        start = scan_binlit(token)
        // move start forward to next char to start scanning
    }
    switch (*start) {
    case '+':
        start = scan_symbol(token, *start);
    }

    /* if start == end */
    return start;
}

void scan_table_scan(struct scan_table_st *st, char *start, char *end) {
    while (true) {
        struct scan_token_st *token = scan_token_new(st);
        start = scan_one_token(token, start, end);
        if (token->id == TK_EOT) {
            break;
        }
    }
}

void scan_table_print(struct scan_table_st *) {
    // walk linked list printing token ID and name
    // use SCAN_STRINGS[token_id]
}

void scan_table_free(struct scan_table_st *) {
    // free linked list one node at a time
}
