#include <stdio.h>

int main ( void )
{
    unsigned long long n;
    scanf( "%llu", &n );
    printf( (n%2)?"SK":"CY" );
    return 0;
}