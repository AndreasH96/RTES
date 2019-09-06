#include <stdio.h>
#define print (x) printf("%d ", x)
int x;
void Q(int z)
{
    z += x; // z = 7 + 5 = 12
    printf("%d ",z); // prints 12
}
void P(int *y)
{
    int x = *y + 2; // local x = 5 + 2 = 7
    Q(x);
    *y = x - 1; //global x = 6
    printf("%d ",x); // prints local x, therefore prints 7
}
main(void)
{
    x = 5;
    P(&x);
    printf("%d \n", x); // prints 6
}