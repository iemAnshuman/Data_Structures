/*
One spring day on his way to university Radha found an array A. 
Radha likes to split arrays into several parts. This time Radha 
decided to split the array A into several possibly one new arrays 
so that the sum of elements in each of the new arrays is not zero. 
One more condition is that if we place the new arrays one after 
another they will form the old array A. Radha is tired now so he 
asked you to split the array. Help Radha!

Input The first line contains single integer n (1 ≤ n ≤ 100) — the 
number of elements in the array A. The next line contains n integers 
a1 a2 ... an ( - 103 ≤ ai ≤ 103) — the elements of the array A.

Output If it is not possible to split the array A and satisfy all 
the constraints print a single line containing "NO" (without quotes). 
Otherwise in the first line print "YES" (without quotes). In the next 
line print single integer k — the number of new arrays. In each of the 
next k lines print two integers li and ri which denote the subarray 
A[li... ri] of the initial array A being the i-th new array. Integers 
li ri should satisfy the following conditions: l1 = 1 rk = n ri + 1 = li + 1 
for each 1 ≤ i < k. If there are multiple answers print any of them. 
Examples input 3 1 2 -3 output YES 2 1 2 3 3 input 8 9 -12 3 4 -4 -10 7 3 
output YES 2 1 2 3 8 input 1 0 output NO input 4 1 2 3 -5
*/

#include <stdio.h>

int main() {
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // First, check if it's possible to have a non-zero sum subarray
    int totalSum = 0;
    for(int i = 0; i < n; i++) {
        totalSum += arr[i];
    }

    if(totalSum == 0) {
        // It's not possible to split the array in a way that meets the requirements
        printf("NO\n");
        return 0;
    }

    // It's always possible to meet the requirement if total sum is not 0
    printf("YES\n");

    // Find the first non-zero sum subarray if necessary
    int subarraySum = 0;
    int splitIndex = -1;
    for(int i = 0; i < n; i++) {
        subarraySum += arr[i];
        if(subarraySum != 0) {
            splitIndex = i;
            break;
        }
    }

    if(splitIndex == n - 1) {
        // The whole array is a valid subarray
        printf("1\n1 %d\n", n);
    } else {
        // There are at least two subarrays
        printf("2\n");
        printf("1 %d\n", splitIndex + 1);
        printf("%d %d\n", splitIndex + 2, n);
    }

    return 0;
}
