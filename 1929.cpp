#include <stdio.h>

char check[ 1000001 ] = { 0 };

void calculate ( )
{
    check[ 0 ] = check[ 1 ] = 1;
    for( int i = 2; i < 1000001 ; ++ i )
    {
        if( !check[ i ] )
            for( int j = i * 2; j < 1000001; j += i )
                if( !check[ j ] ) check[ j ] = 1;
    }
}

int main(void)
{
    int a, b, tmp;
    scanf( "%d %d", &a, &b );
    
    calculate();
    
    for( int i = a; i <= b; ++ i )
        if( !check[ i ] ) printf( "%d\n", i );
    
    return 0;
}

