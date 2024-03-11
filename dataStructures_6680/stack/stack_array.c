#include <stdio.h>
// #include <stdlib.h>
#define MAX_SIZE 100

// created a structure for stack
struct stack {
  int items[MAX_SIZE];
  int top;
};

// intialize the stack
void insti_stack(struct stack *s) { s->top = -1; }

// check if the stack is full
int full(struct stack *s) {
  if (s->top == MAX_SIZE - 1) {
    return 1;
  }
  return 0;
}

// check if the stack is empty
int empty(struct stack *s) {
  if (s->top == -1) {
    return 1;
  }
  return 0;
}

// print the stack
void print(struct stack *s) {
  if (empty(s)) {
    printf("Underflow\n");
    return;
  }
  for (int i = 0; i <= s->top; i++) {
    printf("%d ", s->items[i]);
  }
}

void push(struct stack *s, int data) {
  if (full(s)) {
    printf("Overflow\n");
    return;
  }
  (s->top)++;
  s->items[s->top] = data;
  return;
}

void peek(struct stack *s) {
  if (empty(s)) {
    printf("Underflow\n");
    return;
  }
  printf("%d ", s->items[s->top]);
}

int pop(struct stack *s) {
  if (empty(s)) {
    printf("Underflow\n");
    return -1;
    // to do: debug
  }
  printf("%d ", s->items[s->top]);
  (s->top)--;
  return s->items[s->top];
}

int main() {
  struct stack s;
  insti_stack(&s);
  while (1) {
    printf("Menu: \n");
    printf("1. Push an element\n");
    printf("2. Pop an element\n");
    printf("3. Peek an element\n");
    printf("4. Exit\n");
    printf("5. Print the stack\n");

    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    if (choice == 1) {
      int data;
      printf("Enter the data: ");
      scanf("%d", &data);
      push(&s, data);
    } else if (choice == 2) {
      pop(&s);
    } else if (choice == 3) {
      peek(&s);
    } else if (choice == 4) {
      break;
    } else if (choice == 5) {
      print(&s);
    }
    else {
      printf("Invalid choice\n");
    }
  }
  return 0;
}
