#include <stdio.h>
#define MAX 100

int main()
{
    printf("Enter string: ");
    char paran[MAX];
    fgets(paran,MAX,stdin);

    int par1 = 0, par2 = 0, par3 = 0;
    int ini1 = 0, ini2 = 0, ini3 = 0;

    for(int i=0; paran[i]!='\0'; i++)
    {
        if(paran[i] == ')' && par1 <= 0)
        {
            ini1++;
        }
        else if(paran[i] == '}' && par2 <= 0)
        {
            ini2++;
        }
        else if(paran[i] == ']' && par3 <= 0)
        {
            ini3++;
        }
        else if(paran[i] == '(')
        {
            par1++;
        }
        else if(paran[i] == '{')
        {
            par2++;
        }
        else if(paran[i] == '[')
        {
            par3++;
        }
        else if(paran[i] == ')')
        {
            par1--;
        }
        else if(paran[i] == '}')
        {
            par2--;
        }
        else if(paran[i] == ']')
        {
            par3--;
        }

        int sum = ini1 + ini2 + ini3 + par1 + par2 + par3;

        printf("%d\n",sum);
        return 0;
    }
}