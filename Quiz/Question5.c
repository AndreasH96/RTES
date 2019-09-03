#include  <stdio.h>
#define  ISEQUAL(X, Y) X == Y
int  main()
{
    #if  ISEQUAL(X, 0)      //X will be automatically assigned 0 since null doesn't exist in C
        printf ("RTES ");
    #else
        printf ("Quiz ");
    #endif

    return  0;
    }