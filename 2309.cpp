#include <stdio.h>
#include <stdlib.h>

int compare ( const void* a, const void* b )
{
    if( *(int*)a > *(int*)b )
        return 1;
    return 0;
}

int main ( void )
{
    int arr[ 9 ];
    for( int i = 0; i < 9; ++ i )
        scanf( "%d", &arr[ i ] );
    qsort( arr, 9, sizeof( int ), compare );
    
    for( int i = 0; i < 8; ++ i )
        for( int j = i + 1; j < 9; ++ j )
        {
            int sum = 0;
            for( int k = 0; k < 9; ++ k )
                if( k != i && k != j ) sum += arr[ k ];
            if( sum == 100 )
            {
                for( int k = 0; k < 9; ++ k )
                    if( k!= i && k != j )
                    {
                        printf( "%d\n", arr[ k ] );
                    }
                return 0;
            }
        }
    return 0;
}