#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

void print_list(struct node *head) {
    while (head) {
        printf("value: %d\n", head->value);
        head = head->next;
    }
}

void free_list(struct node *head) {
    while (head) {
        struct node *tmp = head->next;
        free(head);
        head = tmp;
    }
}

int main(int argc, char *argv[]) {
    struct node *n1 = malloc(sizeof(struct node));
    if (!n1) {
        printf("failed to malloc n1\n");
        exit(-1);
    }
    n1->value = 1;

    struct node *n2 = malloc(sizeof(struct node));
    if (!n2) {
        printf("failed to malloc n2\n");
        exit(-1);
    }

    n1->next = n2;
    n2->value = 2;

    struct node *n3 = malloc(sizeof(struct node));
    if (!n3) {
        printf("failed to malloc n3\n");
        exit(-1);
    }

    n2->next = n3;
    n3->value = 3;
    n3->next = NULL;

    print_list(n1);

    free_list(n1);
}
