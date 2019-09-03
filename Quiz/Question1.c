#include <stdio.h>
int main(){
    char x;
    char buf[10];
    printf("Waiting ... \n");
    x = getchar();
    fgets(buf, sizeof(buf), stdin);
    printf("Got it! \n");
    putchar(x);
    printf("\n");
    printf(buf);
    printf("\n");
    
}