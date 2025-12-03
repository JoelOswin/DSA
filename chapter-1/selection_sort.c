#include <stdio.h>
#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))
void selection_sort(int [], int);

void selection_sort(int list[], int n)
{
    int temp,min;
    for (int i=0; i<n-1; i++){
        min=i;
        for (int j=i; i<n; j++){
            if (list[j]<list[min])
                j=min;
            SWAP(list[i],list[min],temp);
        }
    }
}

void main()
{
    int list[]={10,6,9,3,5};
    selection_sort(list,5);
    for (int i=0; i<5; i++){
        printf("%d ", list[i]);
    }
}