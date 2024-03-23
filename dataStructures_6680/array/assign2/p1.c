/*Write a program to input a matrix and to determine if it is the asymmetrical matrix
( a matrix is said to be symmetric when A-A’).
*/
#include <stdio.h>
#define N 100
int main() {
    int a[N][N], t[N][N], n, i, j, f = 1;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            t[j][i] = a[i][j];

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