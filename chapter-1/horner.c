#include <stdio.h>
#include <math.h>

float horner(float x, int n, int coeffs[]){
    float solution=0;
    if (n%2==0){
        solution=solution + (coeffs[0]*(pow(x,n-1)));
        n-=1;
    }
    for (int i=n; i>0; i-=2){
        if (i==1){
            solution+=coeffs[1];
            solution*=x;
            solution+=coeffs[0];
            break;
        }

        solution+=(coeffs[i]*x + coeffs[i-1])*x;
    }

    return solution;
}

void main(){
    int arr[]={1,-4,4};
    printf("%d", horner(3,2,arr));
}