/*
Q. 18. Rotate and delete: As usual Babul is again back with his problem and now with numbers. 
He thought of an array of numbers in which he does two types of operation that is rotation 
and deletion. His processes of doing these 2 operations are that he first rotates the array 
in a clockwise direction then deletes the last element. In short he rotates the array nth times 
and then deletes the nth last element. If the nth last element does not exist then he deletes 
the first element present in the array. So your task is to find out which is the last element 
that he deletes from the array so that the array becomes empty after removing it.

For example A = {123456}. He rotates the array clockwise i.e. after rotation the array A = {612345}
and delete the last element that is {5} so A = {61234}. Again he rotates the array for the second 
time and deletes the second last element that is {2} so A = {4613} doing these steps when 
he reaches 4th time 4th last element does not exists so he deletes 1st element ie {1} so A={36}. 
So continuing this procedure the last element in A is {3} so o/p will be 3.

Input: The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains two lines. The first line of each test case contains an integer N. Then in the next line are N space-separated values of the array A.

Output: For each test case in a new line print the required result.

Constraints: 1<=T<=100 1<=N<=100 1<=A[i]<=10^7
*/

#include <stdio.h>

// Function to perform the rotation and deletion operations on the array
int sol(int arr[], int n) {
    int pos = n-1;
    
    while (n > 1) {
        // Rotate the array clockwise
        int last = arr[n-1];
        for (int i = n-1; i > 0; i--) {
            arr[i] = arr[i-1];
        }
        arr[0] = last;
        
        if(pos > n-1)
        {
            pos = 0;
        }
        
        // Delete the element at delPos
        for (int i = pos; i < n-1; i++) {
            arr[i] = arr[i+1];
        }
        n--; 
        pos++; 
    }
    
    
    return arr[0];
}

int main() {
    int t, n;
    scanf("%d", &t); 
    
    while (t--) {
        scanf("%d", &n); 
        int arr[100]; 
        
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        
        printf("Last element: %d\n", sol(arr, n));
    }
    
    return 0;
}
