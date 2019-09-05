#include <stdio.h>
int f ( int x , int * py , int ** ppz )
{
int y , z ;
** ppz += 1; // x = 4 y = 0 z = 0
z = ** ppz ; // x = 4 y = 0 z = 5
* py += 2;  //  x = 4 y = 0 z = 5
y = * py ;  //  x = 4 y = 7 z = 5
x += 3;     //  x = 7 y = 7 z = 5
return x + y + z ; // return 7 + 7 + 5 = 19
}
void main ()
{
int c , *b , ** a ;
c = 4;
b = & c ;
a = & b ;
printf ("% d " , f (c , b , a ));
return 0;
}