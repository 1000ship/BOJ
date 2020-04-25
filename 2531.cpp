#include <stdio.h>

int n, d, k, c;
int arr[ 30001 ] = { 0 };
int check[ 3001 ] = { 0 };
int current = 0;
int max = 0;

int get ( int idx )
{
    if( idx >= n ) idx %= n;
    return arr[ idx ];
}

int main ( void )
{
    scanf( "%d %d %d %d", &n, &d, &k, &c );
    for( int i = 0; i < n; ++ i )
        scanf( "%d", &arr[ i ] );
    for( int i = 0; i < k; ++ i )
    {
        if( check[ get(i) ] == 0 ) current += 1;
        check[ get(i) ]++;
    }
    max = current;
    if( check[ c ] == 0 ) max += 1;
    
    for( int i = 1; i < n; ++ i )
    {
        check[ get(i-1) ]--;
        if( check[ get(i-1) ] == 0 ) current -= 1;
        if( check[ get(i+k-1) ] == 0 ) current += 1;
        check[ get(i+k-1) ]++;
        if( current + ((check[c]==0)?1:0) > max )
            max = current + ((check[c]==0)?1:0);
    }
    printf( "%d", max );
    return 0;
}