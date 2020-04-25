#include <stdio.h>

int main ( void )
{
    int n;
    scanf( "%d", &n );
    
    int point = 0;
    int arr[ 11 ] = { 0 };
    for( int i = 0; i < n; ++ i )
    {
        int who, where;
        scanf( "%d %d", &who, &where );
        if( !where ) where = -1;
        
        if( arr[ who - 1 ] && arr[ who - 1 ] != where )
            point++;
        arr[ who - 1 ] = where;
    }
    printf( "%d", point );
    return 0;
}