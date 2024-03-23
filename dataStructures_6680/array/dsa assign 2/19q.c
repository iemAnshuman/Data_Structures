#include <stdio.h>

void sort(int *p, int n) {
    int i, j, t;
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(p[j] > p[j+1]) {
                t = p[j];
                p[j] = p[j+1];
                p[j+1] = t;
            }
        }
    }
}

int main() {
    int n, i;
    scanf("%d", &n);
    int a[n], b[n];
    
    for(i = 0; i < n; i++) scanf("%d", &a[i]);
    for(i = 0; i < n; i++) scanf("%d", &b[i]);
    
    sort(a, n); // Ascending sort for A
    sort(b, n); // Ascending sort for B, to reverse later
    
    // Reverse B to descending order
    int t;
    for(i = 0; i < n/2; i++) {
        t = b[i];
        b[i] = b[n-i-1];
        b[n-i-1] = t;
    }
    
    int s = 0;
    for(i = 0; i < n; i++) s += a[i] * b[i];
    
    printf("%d", s);
    
    return 0;
}
