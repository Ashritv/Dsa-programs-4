#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack* stack) {
    stack->top = -1;
}

int isempty(Stack* stack) {
    return stack->top == -1;
}

int isfull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(Stack* stack, int item) {
    if (isfull(stack)) {
        printf("Stack overflow\n");
        return;
    }

    FILE* file = fopen("stack.txt", "a");
    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }
    fprintf(file, "%d\n", item);
    fclose(file);

    stack->items[++stack->top] = item;
}

int pop(Stack* stack) {
    if (isempty(stack)) {
        printf("Stack underflow\n");
        return -1;
    }
    FILE* file = fopen("stack.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return -1;
    }

    int item, previous;
    while (fscanf(file, "%d", &item) == 1) {
        previous = item;
    }
    fclose(file);
    FILE* tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        printf("Error opening file\n");
        return -1;
    }

    file = fopen("stack.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return -1;
    }

    while (fscanf(file, "%d", &item) == 1) {
        if (item != previous) {
            fprintf(tempFile, "%d\n", item);
        }
    }

    fclose(file);
    fclose(tempFile);

    remove("stack.txt");
    rename("temp.txt", "stack.txt");

    stack->top--;
    return previous;
}

int peek(Stack* stack) {
    if (isempty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }

    FILE* file = fopen("stack.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return -1;
    }

    int item, previous;
    while (fscanf(file, "%d", &item) == 1) {
        previous = item;
    }
    fclose(file);

    return previous;
}

int main() {
    Stack stack;
    initialize(&stack);
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    printf("Popped: %d\n", pop(&stack));
    printf("Popped: %d\n", pop(&stack));
    printf("Top element: %d\n", peek(&stack));
    return 0;
}

