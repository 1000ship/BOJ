#include <stdio.h>
#define repeat(i,v) for(int i=0; i<v; ++ i)

int main ( void )
{
    int n, m;
    char arr[ 10 ][ 10 ], tmp;
    scanf( "%d %d", &n, &m );
    repeat( i, n )
    {
        repeat( j, m )
            scanf( " %c", &arr[i][j] );
    }
    
    repeat( i, n )
    {
        repeat( j, m )
            printf( "%c", arr[i][m-j-1] );
        printf( "\n" );
    }
    return 0;
}