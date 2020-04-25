#include <stdio.h>

int main ( void )
{
    int a, b, c, d, e;
    scanf( "%d %d %d %d %d", &a, &b, &c, &d, &e );
    printf( "%d", ((a<0)?-a*c+d:0) + ((a>0)?e*(b-a):e*b) );
    return 0;
}