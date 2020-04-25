#include <stdio.h>

int n, t, min_t = -1;
int tree[ 100 ][ 21 ] = { 0 };
int save[ 100 ][ 21 ] = { 0 };

void simulate ( int x_pos, int y_pos, int use_t )
{
    //printf( ">> x:%d  y:%d  %d\n", x_pos, y_pos, use_t );
    
    //끝까지 도달
    if( x_pos == n )
    {
        if( min_t == -1 || min_t > use_t ) min_t = use_t;
        return;
    }
    
    //dynamic
    if( min_t == 0 ) return;
    if( !save[ x_pos ][ y_pos ] )
        save[ x_pos ][ y_pos ] = use_t + 1;
    else if( save[ x_pos ][ y_pos ] <= use_t + 1 )
        return;
    else
        save[ x_pos ][ y_pos ] = use_t + 1;
    
    for( int i = 0; i < 20; ++ i )
    {
        int hole = tree[ x_pos ][ i ];
        if( hole == 0 ) break;
        
        if( hole == y_pos || hole == y_pos + 1 || hole == y_pos - 1 || hole == y_pos * 2 || (y_pos>10 && hole==20) )
            simulate( x_pos + 1, hole, use_t );
        else if( use_t < t && (min_t == -1 || min_t > use_t) )
            simulate( x_pos + 1, hole, use_t + 1 );
    }
}

int main ( void )
{
    scanf( "%d", &n );
    scanf( "%d", &t );
    for( int i = 0; i < n; ++ i )
    {
        int num;
        scanf( "%d", &num );
        for( int j = 0; j < num; ++ j )
        {
            int tmp;
            scanf( "%d", &tmp );
            tree[ i ][ j ] = tmp;
        }
    }
    simulate( 0, 1, 0 );
    printf( "%d", min_t );
    return 0;
}