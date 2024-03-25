#include <stdio.h>

int main() {
    int t, n, a[100], i, j, k, temp;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        
        for(i = 1; i <= n; i++) {
            temp = a[n-1];
            for(j = n-1; j > 0; j--) {
                a[j] = a[j-1];
            }
            a[0] = temp;
            
            if(n-i >= 0) {
                for(k = n-i; k < n-1; k++) {
                    a[k] = a[k+1];
                }
            } else {
                for(k = 0; k < n-1; k++) {
                    a[k] = a[k+1];
                }
            }
            n--;
        }
        
        printf("The answer is: %d\n", a[0]);
    }
    return 0;
}
