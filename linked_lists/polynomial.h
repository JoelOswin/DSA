#include <stdio.h>
#include <stdlib.h>

typedef struct polyNode{
    int coeff;
    int exponent;
    struct polyNode* link; 
} polyNode;

polyNode* CreateNode(int, int);
void addTerm(polyNode**, int, int);
int deleteTerm(polyNode**, int);
polyNode* polyAdd(polyNode*, polyNode*); 
void printpoly(polyNode*);