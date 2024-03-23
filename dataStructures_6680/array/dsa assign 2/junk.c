#include <stdio.h>
#include <stdlib.h>

void sortBinary(int *a, int n) {
    int i = 0, j = n - 1;
    while (i < j) {
        while (a[i] == 0 && i < j) i++;
        while (a[j] == 1 && i < j) j--;
        if (i < j) {
            a[i] = 0;
            a[j] = 1;
            i++;
            j--;
        }
    }
}

int main() {
    int n = 10, *a;
    a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sortBinary(a, n);
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    free(a);
    return 0;
}
