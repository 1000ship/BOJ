#include <stdio.h>

int main ( void )
{
    int couldnt = 0;
    char str[501];
    int room[501] = { 0 };
    int count[501][2] = { { 0 } };
    int k = 0, cnt = 0, roomNum = 0;
    scanf( "%s", str );
    while( str[ k ] != 0 )
    {
        if( str[ k ] == 'X' )
        {
            cnt++;
        }
        else if( str[ k ] == '.' )
        {
            room[ roomNum ] = cnt;
            cnt = 0;
            roomNum++;
        }
        k++;
    }
    room[ roomNum ] = cnt;
    roomNum++;
    
    for( int i = 0; i < roomNum; ++ i )
    {
        if( room[ i ] % 2 == 1 )
        {
            couldnt = 1;
            break;
        }
        count[ i ][ 0 ] = room[ i ] / 4;
        room[ i ] %= 4;
        count[ i ][ 1 ] = room[ i ] / 2;
    }
    
    if( couldnt )
        printf( "-1" );
    else
    {
        for( int i = 0; i < roomNum; ++ i )
        {
            if( i ) printf( "." );
            for( int j = 0; j < count[ i ][ 0 ]; ++ j )
                printf( "AAAA" );
            for( int j = 0; j < count[ i ][ 1 ]; ++ j )
                printf( "BB" );
        }
    }
    return 0;
}