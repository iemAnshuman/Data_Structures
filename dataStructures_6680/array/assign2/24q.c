/*
Q. 24. The sum in a Range: You are given an array of N positive integers and Q number of queries. In each query you are given two integers L and R find the sum of elements between L and R both inclusive.

Input The first line contains two integers N and Q denoting the number of elements and number of queries respectively. The next line contains N positive integers denoting the array elements. Each of the next Q lines contains two space-separated positive integers L and R.

Output For each query print the sum of elements between L and R inclusive in a new line.

Constraints 1 <= N <= 10^5 1 <= Q <= 10^5 1 <= A[i] <= 10^9 1 <= L <= R <= N


*/

#include <stdio.h>

void calcPS(int a[], int ps[], int n) {
    ps[0] = a[0];
    for (int i = 1; i < n; i++) {
        ps[i] = ps[i - 1] + a[i];
    }
}

int rsq(int ps[], int l, int r) {
    if (l == 0) {
        return ps[r];
    } else {
        return ps[r] - ps[l - 1];
    }
}

int main() {
    int n, q;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int ps[n];
    calcPS(arr, ps, n);
    
    printf("Enter the number of queries: ");
    scanf("%d", &q);
    
    printf("Enter each query in the form of two integers (L and R) representing the range:\n");
    for (int i = 0; i < q; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        l--; r--;
        printf("Sum of elements from %d to %d is: %d\n", l + 1, r + 1, rsq(ps, l, r));
    }
    
    return 0;
}
