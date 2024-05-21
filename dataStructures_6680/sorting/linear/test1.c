#include <stdio.h>
#define MAX 100

struct stack{
    int top;
    char items[MAX];
};

void is_balanced(char paran[], int n)
{
    if(n==0)
    {
        return;
    }
    int count = 0;
    int prev = 0;
    struct stack s;
    s.top = -1;

    for(int i=0; i<n; i++)
    {
        if(paran[i] == '(' || paran[i] == '{' || paran[i] == '[')
        {
            s.items[++s.top] = paran[i];
        }
        else if(paran[i] == ')' || paran[i] == '}' || paran[i] == ']')
        {
            char temp = s.items[s.top--];
            if(!((temp == '(' && paran[i] == ')') || (temp == '{' && paran[i] == '}') || (temp == '[' && paran[i] == ']')))
            {
                while(paran[i] != '\0' || paran[i] != '{' || paran[i] != '(' || paran[i] != '[')
                {
                    i++;
                    if(count > prev)
                    {
                        prev = count;
                        count = 0;
                    }
                }
                i--;
            }
            else 
            {
                count++;
            }
        }
    }

    if(prev > count)
    {
        printf("%d",prev*2);
    }
    else{
        printf("%d",count*2);
    }
}

int main()
{
    printf("Enter string: ");
    char paran[MAX];
    fgets(paran, MAX, stdin);

    is_balanced(paran, MAX);

    return 0;
}