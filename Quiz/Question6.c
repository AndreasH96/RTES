#include  <stdio.h>
int  main(){
    int c = 5, no = 10;
    do {
        no /= c; //Division by 0 leads to runtime error 
        } while(c--);
        
        printf  ("%d\n", no);
        return  0;
}