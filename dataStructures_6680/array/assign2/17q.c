/*
Q. 17. Game of Chocolates: As we all know small children love chocolates so 
one day their class teacher brought N chocolates where the cost of each 
chocolate is written on the cover of chocolate itself.
He asked them to do play a game. Game is described as follows-
They have to select a pair of adjacent chocolates and take out the expensive
chocolate by paying for the cheaper chocolate. The game ends when there is
only one chocolate left. He asked them to find out the minimum cost in which 
they can complete the game?

INPUT
The first line of the input contains T denoting the total number of games.
The first line of each game contains N denoting the total number of chocolates 
their class teacher initially brought for them. The next line contains N 
space-separated positive integers denoting the cost of chocolates.

OUTPUT
For each game output the minimum cost in which children can complete the game.

CONSTRAINTS
1 <= T <= 10
2 <= N <= 100000
1 <= Ai <= 100000
*/

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