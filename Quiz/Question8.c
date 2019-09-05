#include <stdio.h>
int main()
{
    int x = 1;
    int n = 2;
    x = x | 1 << n; // Sets (n+1)th bit of x
    printf("%i\n",x);
    return 0;
}