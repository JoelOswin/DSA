#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct polyNode{
    int coeff;
    int exponent;
    struct polyNode* link;
} polyNode;

polyNode* pread(int coeff[], int exponent[], int n);
void pwrite(polyNode* head);
polyNode* padd(polyNode* a, polyNode* b);
polyNode* psub(polyNode* a, polyNode* b);
polyNode* pmult(polyNode* a, polyNode* b);
float eval(polyNode* head, float x);
polyNode* perase(polyNode** head);