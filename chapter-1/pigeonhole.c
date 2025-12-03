#include <stdio.h>
int func(int);

void pigeonhole(int (*func)(int), int n){
    for (int a=1; a<=n; a++){
        int val_a=func(a);
        for (int b=1; b<=n; b++){
            int val_b=func(b);
            if ((val_a==val_b)&&(a!=b)){
                printf("%d %d", a, b);
                return;
            }
        }
    }
    printf("None");
}

void main()
{
    pigeonhole(func,5);
}

int func(int x){
    return x%2;
}