#define SCAN_TOKEN_LEN 32

enum scan_token_enum {
    TK_INTLIT, /* -123, 415 */
    TK_BINLIT, /* 0b10, 0b1001 */
    TK_HEXLIT, /* 0x7f, 0x12ce */
    TK_LPAREN, /* ( */
    TK_RPAREN, /* ) */
    TK_PLUS,   /* + */
    TK_MINUS,  /* - */
    TK_MULT,   /* * */
    TK_DIV,    /* / */
    TK_EOT,    /* end of text */
};

#define SCAN_STRINGS                                                           \
    {"TK_INTLIT", "TK_BINLIT", "TK_HEXLIT", "TK_LPAREN", "TK_RPAREN",          \
     "TK_PLUS",   "TK_MINUS",  "TK_MULT",   "TK_DIV",    "TK_EOT"};

struct scan_token_st {
    enum scan_token_enum id;
    char name[SCAN_TOKEN_LEN + 1];
    struct scan_token_st *next;
};

struct scan_table_st {
    struct scan_token_st *head;
    int len;
};

void scan_table_init(struct scan_table_st *);
void scan_table_scan(struct scan_table_st *, char *, char *);
void scan_table_print(struct scan_table_st *);
void scan_table_free(struct scan_table_st *);
