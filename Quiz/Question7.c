#include <stdio.h>
int *A, stkTop;
int stkFunc(int opcode, int val)
{
    static int size = 0, stkTop = 0;
    switch (opcode)
    {
    case -1:
        size = val;
        break;
    case 0:
        if (stkTop < size)
            A[stkTop++] = val;
         break;
    default:
        if (stkTop)
            return A[--stkTop];
    }
    return -1;
}
int main()
{
    int B[20];
    A = B;
    stkTop = -1;
    stkFunc(-1, 10);
    stkFunc(0, 5);  //inputs 5 into position 0
    stkFunc(0, 10); // inputs 10 into position 1
    printf("%d\n", stkFunc(1, 0) + stkFunc(1, 0)); // adds 10 to 5 printing 15
}