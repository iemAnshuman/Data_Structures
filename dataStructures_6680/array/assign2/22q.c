/*
Q. 22. Tom and Balls: Tom has N boxes of balls. In one minute he can either add or remove a ball from any box. Can you tell the minimum amount of time in which he can make the gcd of all the balls divisible by K?

Input The first line of the input contains T denoting the total number of test cases. The first line of each test case contains N denoting the total number of boxes. Followed by N space-separated positive integers where ith number denotes the number of balls in the ith box.

Output Print the minimum amount of time in which gcd of all balls can be divisible by K.

Constraints 1 <= T <= 10 1 <= N <= 10^5 1 <= K <= 10^9 1 <= number of balls in a box <= 10^5


*/

#include <stdio.h>
#include <stdlib.h>

// to calculate GCD of two numbers
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

// Function to find the minimum operations needed
int minOperations(int arr[], int n, int k) {
    int total = 0;
    
    int current = arr[0];
    for (int i = 1; i < n; i++) {
        current = gcd(current, arr[i]);
    }
    printf("GCD: %d\n",current);
    // If the GCD is already divisible by K, no operations are needed
    if (current % k == 0) {
        return 0;
    }
    
    // Adjust each box to make the GCD divisible by K
    if(k > current)
    {
        if(k-current > current)
        {
            return current;
        }
        return k-current;
    }
    total = current % k;
    return total;
}

int main() {
    int t; 
    printf("Enter number of testcases:");
    scanf("%d",&t);
    while(t--)
    {
    int n, k;
    printf("Enter the number of boxes (N) and the divisor (K): ");
    scanf("%d %d", &n, &k);
    
    int arr[n];
    printf("Enter the number of balls in each box:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int result = minOperations(arr, n, k);
    printf("Minimum operations required: %d\n", result);
    }
    return 0;
}
