#include <stdio.h>

int main ( void )
{
    int x, y, w, h, min;
    scanf( "%d %d %d %d", &x, &y, &w, &h );
    min = x;
    min = (y<min)?y:min;
    min = ((w-x)<min)?(w-x):min;
    min = ((h-y)<min)?(h-y):min;
    printf( "%d", min );
    return 0;
}