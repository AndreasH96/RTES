#include <stdio.h>
extern int var; // var is declared but not defined, therefore no memory is allocated for it. 
int main()
{
    var = 10; // here var doesn't exist since it's not defined, therefore it's undefined.
    printf("% d ", var);
    return 0;
}