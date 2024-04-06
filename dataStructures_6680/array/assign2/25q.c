/*
Q. 25. Buy Maximum Items: You are given N items where the cost of the ith item is Ci and you have a total budget B find the maximum number of items you can buy within that budget.

Input The first line of the input contains N denoting the total number of items and B denoting the budget. The next line contains N space-separated positive integers denoting the cost of the ith item.

Output Print the maximum number of items you can buy within the given budget.

Constraints 1 <= N <= 10^5 1 <= B <= 10^15 1 <= A[i] <= 10^9
*/

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
    int count = 0;
    for(int i = 0; i < n; i++) {
        if(b >= c[i]) {
            b -= c[i]; // Subtracting the cost from the budget
            count++; // Increasing the count of items
        } else {
            break; // Stop if the budget can't cover the next item
        }
    }
    return count;
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
