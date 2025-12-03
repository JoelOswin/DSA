#include "circular_poly.h"

void main()
{
    int coeff[] = {1,4,4};
    int exponent[] = {2,1,0};
    polyNode* head = pread(coeff, exponent, 3);
    polyNode* head1 = pread(coeff, exponent, 3);

    float answer = eval(head, 2.0);
    printf("%f", answer);

    perase(&head);
    pwrite(head);
}