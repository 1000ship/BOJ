#include <stdio.h>
#include <stdlib.h>

typedef struct digit_struct {
    int number;
    int cnt;
} Digit;

int compare ( const void* left, const void* right )
{
    Digit *x = (Digit*)left, *y = (Digit*)right;
    return x->cnt < y->cnt;
}

int main ( void )
{
    Digit digits[ 1000 ];
    int len = 0, n, c, value;
    scanf( "%d %d", &n, &c );
    for( int i = 0; i < n; ++ i )
    {
        scanf( "%d", &value );
        int idx = -1;
        for( int j = 0; j < len; ++ j )
            if( digits[ j ].number == value )
                idx = j, j = len;
        if( idx != -1 )
            digits[ idx ].cnt ++;
        else
        {
            digits[ len ].number = value;
            digits[ len++ ].cnt = 1;
        }
    }
    qsort( digits, len, sizeof( Digit ), compare );
    for( int i = 0; i < len; ++ i )
        for( int j = 0; j < digits[ i ].cnt; ++ j )
            printf( "%d ", digits[i].number );
    return 0;
}