#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *p = (int *)malloc(sizeof(int));
    p = NULL; // setting p to NULL before freeing it leads to a dangling pointer
    free(p);
}