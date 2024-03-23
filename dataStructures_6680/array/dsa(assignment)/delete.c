#include <stdio.h>

int ls(int ar[], int n, int x) {
    int i;
    for (i = 0; i < n; i++)
        if (ar[i] == x)
            return i;
    return -1;
}

int bs(int ar[], int l, int r, int x) {
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (ar[m] == x)
            return m;
        if (ar[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}

int main() {
    int n; 
    printf("Enter size: ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0; i<n; i++)
    {
        printf("Enter elements: ");
        scanf("%d",&arr[i]);
    }
    int x, ch, res;
    printf("Enter 1 for Linear Search, 2 for Binary Search: ");
    scanf("%d", &ch);
    printf("Enter the number to search: ");
    scanf("%d", &x);
    
    if (ch == 1) {
        res = ls(arr, n, x);
        if(res != -1)
            printf("Element found at index %d using Linear Search.\n", res);
        else
            printf("Element not found.\n");
    } else if (ch == 2) {
        res = bs(arr, 0, n - 1, x);
        if(res != -1)
            printf("Element found at index %d using Binary Search.\n", res);
        else
            printf("Element not found.\n");
    } else {
        printf("Invalid choice.\n");
    }
    
    return 0;
}
