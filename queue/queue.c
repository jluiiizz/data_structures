#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 100

struct queue {
    int items[MAX_SIZE];
    int head;
    int tail;
};

struct queue* create_queue() {
    struct queue* q = malloc(sizeof(struct queue));
    q->head = -1;
    q->tail = -1;
    return q;
}

int is_full(struct queue* q) {
    if (q->tail == MAX_SIZE - 1) {
        return 1;
    } else {
        return 0;
    }
}

int is_empty(struct queue* q) {
    if (q->tail == -1) {
        return 1;
    } else {
        return 0;
    }
}

void enqueue(struct queue* q, int value) {
    if (is_full(q)) {
        printf("\nQueue is full!\n");
    } else {
        if (q->head == -1) {
            q->head = 0;
        }
        q->tail++;
        q->items[q->tail] = value;
    }
}

int dequeue(struct queue* q) {
    int item;
    if (is_empty(q)) {
        printf("\nQueue is empty!\n");
        item = -1;
    } else {
        item = q->items[q->head];
        q->head++;
        if (q->head > q->tail) {
            q->head = q->tail = -1;
        }
    }
    return item;
}

void print_queue(struct queue* q) {
  int i = q->head;

  if (is_empty(q)) {
    printf("Queue is empty");
  } else {
    printf("\nQueue: \n");
    for (i = q->head; i < q->tail + 1; i++) {
      printf("%d ", q->items[i]);
    }
    printf("\n");
  }
}

int main() {
    struct queue* q = create_queue();

    enqueue(q, 1);
    enqueue(q, 10);

    print_queue(q);

    enqueue(q, 7);
    enqueue(q, 13);
    dequeue(q);

    print_queue(q);
    
    enqueue(q, 9);
    enqueue(q, 24);
    enqueue(q, 32);
    enqueue(q, 53);
    dequeue(q);
    dequeue(q);

    print_queue(q);

    return 0;
}