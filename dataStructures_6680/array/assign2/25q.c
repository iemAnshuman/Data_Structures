#include <stdio.h>

// Function to sort the array
void sort(int a[], int n) {
    int temp;
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(a[j] > a[j+1]) {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

// Function to calculate the maximum number of items
int maxI(int c[], int n, long long b) {
    sort(c, n); // Sorting the array
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(b >= c[i]) {
            b -= c[i]; // Subtracting the cost from the budget
            cnt++; // Increasing the count of items
        } else {
            break; // Stop if the budget can't cover the next item
        }
    }
    return cnt;
}

int main() {
    int n;
    long long b;
    printf("Enter the number of items and budget: ");
    scanf("%d %lld", &n, &b);
    
    int c[n];
    printf("Enter the cost of each item:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }
    
    printf("Maximum items you can buy: %d\n", maxI(c, n, b));
    
    return 0;
}
