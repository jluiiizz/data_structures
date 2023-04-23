#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 100

// Needed to make print_stack easier
int count = 0;

struct stack {
    int items[MAX_SIZE];
    int top;
};

struct stack* create_stack() {
    struct stack* s = malloc(sizeof(struct stack));
    s->top = -1;
    return s;
}

int is_full(struct stack* s) {
    if (s->top == MAX_SIZE - 1) {
        return 1;
    } else {
        return 0;
    }
}

int is_empty(struct stack* s) {
    if (s->top == -1) {
        return 1;
    } else {
        return 0;
    }
}

void push(struct stack* s, int new_item) {
    if (is_full(s)) {
        printf("\nStack full!\n");
    } else {
        s->top++;
        s->items[s->top] = new_item;
    }
    count++;
}

void pop(struct stack* s) {
    if (is_empty(s)) {
        printf("\nStack empty!\n");
    } else {
        s->top--;
    }
    count--;
}

void print_stack(struct stack *s) {
    printf("Stack: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", s->items[i]);
    }
    printf("\n");
}

int main() {
    struct stack* s = create_stack();

    push(s, 1);

    print_stack(s);

    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 6);

    print_stack(s);

    pop(s);
    pop(s);

    print_stack(s);

    return 0;
}