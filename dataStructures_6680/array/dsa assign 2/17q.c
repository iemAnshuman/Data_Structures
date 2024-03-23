/*
Explanation:-
Here we have to find the minimum cost by:-
0) Create a var = 0
1) choose a pair
2) remove the larger value in pair
3) continue till only one is left

by observing, we notice that the smaller one is never being removed 
which means, we will be choosing the same value for the whole
algorithm and removing the adjacent one.
*/

#include <stdio.h>
#include <stdlib.h>

void sol(int n, int cost[])
{
    if(n==0)
    {
        printf("Action not possible\n");
    }
    int sm = INT16_MAX;
    for(int i=0; i<n; i++)
    {
        if(sm > cost[i])
        {
            sm = cost[i];
        }
    }
    if(n>1)
    {
        sm = (n-1)*sm;
    }
    printf("Minimum cost is %d\n",sm);
}   

int main()
{
    int t; // number of testcases
    printf("Enter number of testcases: ");
    scanf("%d",&t);
    while(t--)
    {
        int n; // number of chocolates
        printf("Enter number of chocolates: ");
        scanf("%d",&n);
        int cost[n]; // cost of each chocolates
        for(int i=0; i<n; i++)
        {
            scanf("%d",&cost[i]);
        }

        // output
        sol(n,cost);
    }
}