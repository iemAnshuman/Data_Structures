#include <stdio.h>

int main() {
    int a[] = {1, 2, 3, 4, 5};
    int* p[5];
    int i;

    for(i = 0; i < 5; i++)
        p[i] = &a[i];

    for(i = 0; i < 5; i++)
        printf("%d ", *p[i]);

    return 0;
}

