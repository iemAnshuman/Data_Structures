/*
Linked list without pointers can't be implemented as 
the essence of a linked list involves pointing from one 
node to the next. The cloest we can get is by mimicing 
the the behavior of a linked list using arrays.
*/

#include <stdio.h>

#define MAX_NODES 100
#define NULL_INDEX -1

// Simulated node structure
typedef struct {
    int value;
    int next;
} Node;

// Simulated linked list using an array
Node list[MAX_NODES];

// Initialize the list
void initList() {
    for(int i = 0; i < MAX_NODES; i++) {
        list[i].next = NULL_INDEX;
    }
}

// Insert at the beginning of the list
void insert(int value) {
    int i;
    for (i = 0; i < MAX_NODES && list[i].next != NULL_INDEX; i++);
    if (i == MAX_NODES) {
        printf("List is full\n");
        return;
    }
    
    list[i].value = value;
    list[i].next = 0; 
    i=0;
}

// Function to print the list
void printList() {
    int index = 0; 
    while(index != NULL_INDEX) {
        printf("%d ", list[index].value);
        index = list[index].next;
    }
    printf("\n");
}


int main() {
    initList(); 
    insert(1);
    insert(2);
    insert(3);
    printList(); 
    
    return 0;
}
