#include <stdio.h>
#include <string.h>

void reverse(char arr[], int n)
{
    
}

int main()
{
    int n; 
    printf("Enter size: ");
    scanf("%d",&n);

    char buffer[n];
    //fgets(arr, sizeof(arr), stdin);
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        // Remove newline character, if present
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }

        printf("You entered: %s\n", buffer);
    } else {
        printf("No input read.\n");
    }
    return 0;
}