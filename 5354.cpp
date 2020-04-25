#include <stdio.h>

int main ( void )
{
    int t;
    scanf( "%d", &t );
    for( int tc = 0; tc < t; ++ tc )
    {
        int size;
        scanf( "%d", &size );
        for( int i = 0; i < size; ++ i )
        {
            for( int j = 0; j < size; ++ j )
            {
                if( i != 0 && i != size-1 && j != 0 && j != size-1 )
                    printf( "J" );
                else
                    printf( "#" );
            }
            printf( "\n" );
        }
        printf( "\n" );
    }
    return 0;
}