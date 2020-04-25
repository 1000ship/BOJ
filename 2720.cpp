#include <stdio.h>

int main ( void )
{
    int case_num, value;
    scanf( "%d", &case_num );
    for( int i = 0; i < case_num; ++ i )
    {
        scanf( "%d", &value );
        printf( "%d ", value / 25 );
        value %= 25;
        printf( "%d ", value / 10 );
        value %= 10;
        printf( "%d ", value / 5 );
        value %= 5;
        printf( "%d\n", value );
    }
    return 0;
}