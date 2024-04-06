/*
Q. 16. You have a row of binary digits arranged randomly. 
Arrange them in such an order that all 0’s precede all 1’s or vice versa. 
The only constraint in arranging them is that you are allowed to 
interchange the positions of binary digits if they are not similar. 
Write a program in C using the pointer to solve the problem.
*/

#include <stdio.h>

// Function to rearrange the binary digits
void rearrange(int *arr, int size) {
    int left = 0, right = size - 1;
    
    while(left < right) {
        // Move left pointer until we find a 1
        while(arr[left] == 0 && left < right) {
            left++;
        }
        
        // Move right pointer until we find a 0
        while(arr[right] == 1 && left < right) {
            right--;
        }
        
        // If there is a pair of 1 at left and 0 at right, swap them
        if(left < right) {
            arr[left] = 0;
            arr[right] = 1;
            left++;
            right--;
        }
    }
}

int main() {
    int n;
    printf("Enter size: ");
    scanf("%d",&n);

    int arr[n]; 
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Original array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    rearrange(arr, n);
    
    printf("Rearranged array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
