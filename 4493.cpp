#include <stdio.h>

int getPoint ( char a, char b )
{
    switch ( a ) 
    {
        case 'R':
            switch( b )
            {
                case 'R':
                    return 0;
                case 'S':
                    return 1;
                case 'P':
                    return -1;
            }
        case 'S':
            switch( b )
            {
                case 'R':
                    return -1;
                case 'S':
                    return 0;
                case 'P':
                    return 1;
            }
        case 'P':
            switch( b )
            {
                case 'R':
                    return 1;
                case 'S':
                    return -1;
                case 'P':
                    return 0;
            }
    }
    return 12345;
}

int main ( void )
{
    int t;
    scanf( "%d", &t );
    
    int point;
    int n;
    for( int j = 0; j < t; ++ j )
    {
        scanf( "%d", &n );
        point = 0;
        for( int i = 0; i < n; ++ i )
        {
            char a, b;
            scanf( " %c %c", &a, &b );
            point += getPoint( a, b );
        }
        if( point > 0 )
            printf( "Player 1\n" );
        else if( point < 0 )
            printf( "Player 2\n" );
        else
            printf( "TIE\n" );
    }
    return 0;
}