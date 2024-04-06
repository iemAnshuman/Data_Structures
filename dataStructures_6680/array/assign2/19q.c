/*
Q. 19. Minimize the sum of product: Given two arrays A and B of equal size n the task 
is to find the minimum value of A[0] * B[0] + A[1] * B[1] +…+ A[n-1] * B[n-1] where 
shuffling of elements of arrays A and B is allowed.

Examples:

Input : A[] = {3 1 1} and B[] = {6 5 4}. Output : 23 Minimum value of S = 16 + 15 + 3*4 = 23.

Input : A[] = { 6 1 9 5 4 } and B[] = { 3 4 8 2 4 } Output : 80. Minimum value of S = 18 + 44 + 
54 + 63 + 9*2 = 80.

Input: The first line of input contains an integer denoting the no of test cases. Then T test 
cases follow. Each test case contains three lines. The first line of input contains an 
integer N denoting the size of the arrays. In the second line is N space-separated values of 
the array A[] and in the last line are N space-separated values of the array B[].

Output: For each test case in a new line print the required result.

Constraints: 1<=T<=100 1<=N<=50 1<=A[]<=20
*/

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
    printf("Enter size: ");
    scanf("%d", &n);
    int a[n], b[n];
    
    printf("Enter elements of first array:\n");
    for(i = 0; i < n; i++) scanf("%d", &a[i]);
    printf("Enter elements of second array:\n");
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
    
    printf("Result: %d", s);
    
    return 0;
}
