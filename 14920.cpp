#include <stdio.h>
#define ull unsigned long long

int main ( void )
{
    int n = 1;
    ull a;
    scanf( "%llu", &a );
    
    while( a != 1 )
    {
        n++;
        if( a % 2 == 0 )
        {
            a /= 2;
        }
        else
        {
            a *= 3;
            a++;
        }
    }
    printf( "%d", n );
    return 0;
}