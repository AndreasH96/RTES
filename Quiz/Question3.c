#include  <stdio.h>
int  foo(int* a, int* b){  //switches the values of a and b
int  sum = *a + *b;
*b = *a; //b is now a
return *a = sum - *b; //a is now a + b - a, therefore a is now b, 
}
int  main(){
    int i = 0, j = 1, k = 2, l;
    l = i++ || foo(&j, &k); // l is now 1 since foo returns the value 2
    printf ("%d %d %d %d", i, j, k, l);return  0; //1211
    }