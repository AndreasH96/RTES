#include <stdio.h>
int main()
{
    int a[] = {1, 2, 3, 4, 5, 6};
    int *ptr = (int *)(&a + 1);//will add 8 to the address since siceof(int) is 8
    printf("%d ", *(ptr - 1)); // prints out 6
    return 0;
}