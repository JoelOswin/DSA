#include <stdio.h>

int count=0;

int factorial(int n)
{
    printf("size of n(int): %d\n", sizeof(n));
    if (n==1)
        return 1;
    else
        return n*factorial(n-1);
}

void main()
{
    printf("factorial of 5 %d", factorial(5));
    printf("\ncount : %d", count);
}