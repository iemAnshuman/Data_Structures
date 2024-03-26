#include <stdio.h>

// Function to print array in reverse order
void print(int arr[], int size) {
    printf("Array in reverse order:\n");
    for(int i = size - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int elements[10]; 
    
    // Taking input for 10 elements
    printf("Enter 10 elements for the array:\n");
    for(int i = 0; i < 10; i++) {
        scanf("%d", &elements[i]);
    }
    
    // Calling the function to print array in reverse
    print(elements, 10);
    
    return 0;
}

