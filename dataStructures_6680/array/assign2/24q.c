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
