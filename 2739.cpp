#include <stdio.h>

int main ( void )
{
    int level;
    scanf( "%d", &level );
    
    for ( int i = 1; i <= 9; ++ i )
    {
        printf( "%d * %d = %d\n", level, i, level * i);
    }
    return 0;
}