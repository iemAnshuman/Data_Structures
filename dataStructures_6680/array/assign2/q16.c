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
    int arr[8] = {1, 1, 0, 1, 0, 1, 0, 0}; 
    int size = sizeof(arr)/sizeof(arr[0]);
    
    printf("Original array: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    rearrange(arr, size);
    
    printf("Rearranged array: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
