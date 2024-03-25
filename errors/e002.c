#include <stdio.h>

int main()
{
    int a = 10;
    printf("%c",a);

    /*
    //similar case
    char c = 'a';
    printf("%d",c);
    */
}

/*
In this case, a is an integer with the value 10. When passed to printf with the %c format specifier,
a is implicitly converted to an unsigned char, and the character with the ASCII value of 10 
(which is a newline character in ASCII) is printed. This behavior is defined and expected according 
to the C standard, which is why a compiler might not issue a warning for this specific case.
*/