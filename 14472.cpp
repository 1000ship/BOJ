#include <stdio.h>

int height, width, size;
int arr[ 100 ][ 100 ] = { 0 };

int isOK1 ( int x, int y )
{
    // garo
    if( x+size-1 >= width )
        return 0;
    for( int i = 0; i < size; ++ i )
        if( arr[x+i][y] )
            return 0;
    return 1;
}

int isOK2 ( int x, int y )
{
    // sero
    if( y+size-1 >= height )
        return 0;
    for( int i = 0; i < size; ++ i )
        if( arr[x][y+i] )
            return 0;
    return 1;
}

int main ( void )
{
    scanf( "%d %d %d", &height, &width, &size );
    
    for( int i = 0; i < height; ++ i )
        for( int j = 0; j < width; ++ j )
        {
            char c;
            scanf( " %c", &c );
            if( c == '#' )
                arr[ j ][ i ] = 1;
        }
    
    int point = 0;
    for( int i = 0; i < width; ++ i )
        for( int j = 0; j < height; ++ j )
            point += isOK1( i, j ) + isOK2( i, j );
    printf( "%d", point );
    return 0;
}