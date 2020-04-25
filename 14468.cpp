#include <stdio.h>

int main ( void )
{
    int arr[ 26 ][ 2 ] = { 0 };
    for( int i = 0; i < 52; ++ i )
    {
        char c;
        scanf( "%c", &c );
        if( !arr[ c-'A' ][ 0 ] )
            arr[ c-'A' ][ 0 ] = i + 1;
        else
            arr[ c-'A' ][ 1 ] = i + 1;
    }
    
    int point = 0;
    for( int i = 0; i < 26; ++ i )
    {
        for( int j = 0; j < 26; ++ j )
        {
            int cnt = 0;
            if( arr[i][0] <= arr[j][0] && arr[j][0] <= arr[i][1] )
                cnt++;
            if( arr[i][0] <= arr[j][1] && arr[j][1] <= arr[i][1] )
                cnt++;
            if( cnt == 1 )
                point++;
        }
    }
    printf( "%d", point/2 );
    return 0;
}