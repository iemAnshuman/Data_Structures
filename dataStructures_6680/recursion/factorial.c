#include <stdio.h>

int factorial(int n)
{
    if(n == 1)
    {
        return 1;
    }
    return factorial(n-1)*n;
}

int main()
{
    int n;
    printf("Enter number: ");
    scanf("%d",&n);
    printf("%d",factorial(n));
}