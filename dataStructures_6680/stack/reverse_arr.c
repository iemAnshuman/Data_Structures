#include <stdio.h>
#define MAX_SIZE 100

struct stack {
  int items[MAX_SIZE];
  int top;
};

void insti_stack(struct stack *s) { 
    s->top = -1;
}

int full(struct stack *s) {
  if (s->top == MAX_SIZE - 1) {
    return 1;
  }
  return 0;
}

int empty(struct stack *s) {
  if (s->top == -1) {
    return 1;
  }
  return 0;
}

void print(struct stack *s) {
  if (empty(s)) {
    printf("Underflow\n");
    return;
  }
  for (int i = 0; i <= s->top; i++) {
    printf("%d ", s->items[i]);
  }
  printf("\n");
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

int pop(struct stack *s)
{
  if(empty(s))
  {
    printf("Underflow\n");
    return __INT_MAX__;
  }
  int temp = s->items[s->top];
  s->top--;
  return temp;
}

struct stack reverse(struct stack *s)
{
  struct stack temp;
  // initialise temp
  insti_stack(&temp);

  while(!empty(s))
  {
    push(&temp, pop(s));
  }

  return temp;
}

int main()
{
    struct stack s;
    insti_stack(&s);
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int x;
        scanf("%d", &x);
        push(&s, x);
    }
    printf("The original stack is: ");
    print(&s);

    s = reverse(&s);
    printf("Reversed array is: ");
    print(&s);
    return 0;
}
