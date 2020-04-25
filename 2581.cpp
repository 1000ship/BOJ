#include <stdio.h>

char check[ 10001 ] = { 0 };

void calculate ( )
{
    check[ 0 ] = check[ 1 ] = 1;
    for( int i = 2; i < 10001 ; ++ i )
    {
        if( !check[ i ] )
            for( int j = i * 2; j < 10001; j += i )
                if( !check[ j ] ) check[ j ] = 1;
    }
}

int main(void)
{
    int a, b, tmp = 0, first = -1;
    scanf( "%d", &a );
    scanf( "%d", &b );
    
    calculate();
    
    for( int i = a; i <= b; ++ i )
        if( !check[ i ] )
        {
            tmp += i;
            if( first == -1 ) first = i;
        }
        
    if( first == - 1 ) printf( "-1" );
    else printf( "%d\n%d", tmp, first );
    
    return 0;
}

