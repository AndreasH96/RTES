#include <stdio.h>
int main(void)
{
    int i;
    int *ptr = (int *)malloc(5 * sizeof(int));

    for (i = 0; i < 5; i++)
        *(ptr + i) = i;
    // *ptr is now pointing to the first value of an integer array [0,1,2,3,4]
    printf("% d ", *ptr++);     //prints 0, *ptr is now pointing to 1
    printf("% d ", (*ptr)++);   //prints 1, *ptr is still pointing att position 1 but has incremented
                                //the value, the array is now [0,2,2,3,4]
                                //                               ^
    printf("% d ", *ptr);       //prints 2, *ptr still points at position 1 
                                //[0,2,2,3,4]
                                //   ^
    printf("% d ", *++ptr);     //prints 2, this time from position 2, [0,2,2,3,4]
                                //                                          ^ 
    printf("% d ", ++*ptr);     //prints 3, *ptr is still pointing at position 2, it has simply fetched
                                // the value and incremented it, the array is now [0,2,3,3,4]
                                //                                                     ^
}