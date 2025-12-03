#include <stdio.h>

int fibo_iterative(int n){
    int a=0, b=1, c;
    for (int i=0; i<n; i++){
        if (n<=1)
            return n;
        c=a;
        a=b;
        b=c+b;
    }
    return a;
}

int fibo_recursive(int n){
    if (n<=1)
        return n;
    return (fibo_recursive(n-1) + fibo_recursive(n-2));
}

void main()
{
    printf("%d %d", fibo_recursive(5), fibo_iterative(5));
}