// cool things to do with floats

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define DOUBLE_MAX 1.79769313486231570e+308

int main()
{
    while(1)
    {
        // menu 
    printf("Menu:\n");
    printf("0. Exit\n");
    printf("1. 0.0/0.0\n");
    printf("2. sqrt(neg float)\n");
    printf("3. doing something with INFINITY\n");
    printf("4. operations on NAN\n");

    printf("5. non-zero / zero\n");
    printf("6. Overflow\n");
    printf("7. log(0.0) or exp(0.0)\n");
    printf("8. Overflow due to strtof() or atof()\n");
    printf("9. INFINITY - INFINITY\n");

    printf("100. INF operator NAN\n");

    // choice for menu
    int choice;
    printf("Enter choice: ");
    scanf("%d",&choice);

    // switch for performing menu
    double r;
    switch (choice)
    {
    case 0:
    {
        return 0;
    }
    case 1:
    {
        double n = 0.0;
        r = n/n;
        printf("%lf\n",r);
        continue;
    }
    case 2:
    {
        r = sqrt(-1.0);
        printf("%lf\n",r);
        continue;
    }
    case 3: 
    {
        r = 0.0 * INFINITY;
        // double r = INFINITY;
        // double r = INFINITY + INFINITY;
        printf("%lf\n",r);
        continue;
    }
    case 4:
    {
        r = NAN * 2.0;
        printf("%lf\n",r);
        continue;
    }
    case 5:
    {
        r = 10.0 / 0.0;
        printf("%lf\n",r);
        continue;
    }
    case 6: 
    {
        r = DOUBLE_MAX * 2.0;
        printf("%lf\n",r);
        continue;
    }
    case 7: 
    {
        r = log(0.0);
        printf("%lf\n",r); // -inf
        r = exp(1000.0); // inf
        printf("%lf\n",r); 
        continue;
    }
    case 8:
    {
        float res = strtof("1e400", NULL);
        printf("%f\n",res);
        continue;
    }
    case 9:
    {
        r = INFINITY - INFINITY;
        printf("%lf\n",r); 
        continue;
    }
    case 100:
    {
        r = INFINITY * NAN;
        printf("%lf\n",r); 
        continue;
    }
    default:
        printf("\nInvalid Input\n");
        return 1;
    }
    }
}

