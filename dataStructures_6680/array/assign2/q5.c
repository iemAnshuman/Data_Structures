// matrix is symmetrical or asymmetrical?

#include <stdio.h>
#define N 100

int main() {
    int a[N][N], t[N][N], n, i, j, f = 0;
    // size input
    scanf("%d", &n);

    // matrix input
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    // rotate
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            t[j][i] = a[i][j];

    // check
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (a[i][j] != t[i][j]) 
            {
                f = 1;
                break;
            }

    if (f)
        printf("Matrix is asymmetric.\n");
    else
        printf("Matrix is symmetric.\n");
    return 0;
}
