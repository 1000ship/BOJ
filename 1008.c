#include <stdio.h>

int main ( void )
{
    long double a, b;
    scanf( "%llf %llf", &a, &b );
    printf( "%.10llf", a/b );
    return 0;
}