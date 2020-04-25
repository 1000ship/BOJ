#include <stdio.h>

#define V 0
#define H 1

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define TURN 4

typedef struct wood_struct {
    int x;
    int y;
    int rotation;
} Wood;

int n, map[ 50 ][ 50 ] = { 0 }, result = -1;
int min[ 50 ][ 50 ][ 2 ] = { 0 }; // for dynamic programming
Wood start, end;

int isEmpty ( int dx, int dy )
{
    int x = start.x + dx, y = start.y + dy;
    return x >= 0 && x < n && y >= 0 && y < n && map[ x ][ y ] != 1;
}

// up is -, down is +, left is -, right is +
int canUp ( )
{
    if( start.rotation == V )
        return isEmpty( 0, -2 );
    else
        return isEmpty( 0, -1 ) & isEmpty( -1, -1 ) & isEmpty( 1, -1 );
}

int canDown ( )
{
    if( start.rotation == V )
        return isEmpty( 0, 2 );
    else
        return isEmpty( 0, 1 ) & isEmpty( -1, 1 ) & isEmpty( 1, 1 );
}

int canLeft ( )
{
    if( start.rotation == V )
        return isEmpty( -1, 0 ) & isEmpty( -1, 1 ) & isEmpty( -1, -1 );
    else
        return isEmpty( -2, 0 );
}

int canRight ( )
{
    if( start.rotation == V )
        return isEmpty( 1, 0 ) & isEmpty( 1, 1 ) & isEmpty( 1, -1 );
    else
        return isEmpty( 2, 0 );
}

int canTurn ( )
{
    return isEmpty( -1, -1 ) & isEmpty( 0, -1 ) & isEmpty( 1, -1 )
            & isEmpty( -1, 0 )                  & isEmpty( 1, 0 )
            & isEmpty( -1, 1 ) & isEmpty( 0, 1 ) & isEmpty( 1, 1 );
}

// 5 act-types -> up, down, left, right, turn
void calculate ( int step )
{
    // get rid of the case
    if( min[ start.x ][ start.y ][ start.rotation ] != 0
        && min[ start.x ][ start.y ][ start.rotation ] <= step )
        return;
    
    // save
    if( min[ start.x ][ start.y ][ start.rotation ] == 0
        || min[ start.x ][ start.y ][ start.rotation ] > step )
    {
        min[ start.x ][ start.y ][ start.rotation ] = step;
    }
    
    // check
    if( start.x == end.x && start.y == end.y && start.rotation == end.rotation )
    {
        if( result == -1 || result > step )
            result = step;
        return;
    }
    
    if( canUp() )
    {
        start.y -= 1;
        calculate( step + 1 );
        start.y += 1;
    }
    
    if( canDown() )
    {
        start.y += 1;
        calculate( step + 1 );
        start.y -= 1;
    }
    
    if( canLeft() )
    {
        start.x -= 1;
        calculate( step + 1 );
        start.x += 1;
    }
    
    if( canRight() )
    {
        start.x += 1;
        calculate( step + 1 );
        start.x -= 1;
    }
    
    if( canTurn() )
    {
        start.rotation = !start.rotation;
        calculate( step + 1 );
        start.rotation = !start.rotation;
    }
}

int main ( void )
{
    // map setting
    scanf( "%d", &n );
    start.x = -1, end.x = -1, start.rotation = -1, end.rotation = -1;
    for( int y = 0; y < n; ++ y )
    for( int x = 0; x < n; ++ x )
    {
        char c;
        scanf( " %c", &c );
        switch( c )
        {
            case '1':
                map[ x ][ y ] = 1;
                break;
            case 'B':
                map[ x ][ y ] = 0;
                if( start.x == -1 )
                {
                    start.x = x, start.y = y;
                }
                else
                {
                    if( start.rotation == -1 )
                        if( start.x != x ) start.rotation = H;
                        else start.rotation = V;
                    start.x += x, start.y += y;
                }
                break;
            case 'E':
                map[ x ][ y ] = 0;
                if( end.x == -1 )
                {
                    end.x = x, end.y = y;
                }
                else
                {
                    if( end.rotation == -1 )
                        if( end.x != x ) end.rotation = H;
                        else end.rotation = V;
                    end.x += x, end.y += y;
                }
                break;
            case '0':
                map[ x ][ y ] = 0;
                break;
        }
    }
    start.x /= 3, start.y /= 3, end.x /= 3, end.y /= 3;
    
    // back tracking
    calculate( 0 );
    
    if( result == -1 )
        printf( "0" );
    else
        printf( "%d", result );
    return 0;
}