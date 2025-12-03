#include "polynomial.h"

void main()
{
    polyNode* a = CreateNode(1,2);
    addTerm(&a, 4, 1);
    addTerm(&a, 43,213);
    printpoly(a);
    printf("\n");
    deleteTerm(&a, 213);
    addTerm(&a, 4, 0);
    printpoly(a);
    printf("\n");

    polyNode* c = polyAdd(a,a);
    printpoly(c);
}