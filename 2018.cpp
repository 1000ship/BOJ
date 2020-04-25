#include <stdio.h>
#define llu unsigned long long

int n;

llu sum ( llu n )
{
    return n * (n+1) / 2;
}

llu AtoB ( llu a, llu b )
{
    if( a == b ) return a;
    return sum(b) - sum(a) + a;
}

int calc ( int len, int from, int to )
{
    int n_from = from, n_to = to;
    int mid = (from+to)/2;
    llu tmp = AtoB( (llu)mid, (llu)(mid+len-1) );
    if( n > tmp )
        n_from = mid;
    else if( n < tmp )
        n_to = mid;
    else if( n == tmp )
    {
        //printf( ">> from: %d, to: %d, mid: %d / n(%d), tmp(%llu) / n_from: %d, n_to: %d\n", from, to, mid, n, tmp, n_from, n_to );
        return 1;
    }
    
    if( to - from <= 1 ) return 0;
    
    //printf( "from: %d, to: %d, mid: %d / n(%d), tmp(%llu) / n_from: %d, n_to: %d\n", from, to, mid, n, tmp, n_from, n_to );
    return calc( len, n_from, n_to );
}

int main ( void )
{
    int maxLen = 0;
    scanf( "%d", &n );
    
    do
        maxLen++;
    while( maxLen * (maxLen+1) <= 2 * n );
    maxLen--;
    
    int cnt = 0;
    for( int len = 1; len <= maxLen; ++ len )
    {
        //printf("Len : %d\n", len );
        int from = 1, to = n+1;
        if( calc( len, from, to ) )
            cnt++;
    }
    printf( "%d", cnt );
    return 0;
}