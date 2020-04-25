#include <stdio.h>
#include <math.h>

int n;
int arr[ 100 ][ 100 ] = { 0 };

typedef struct {
    int x;
    int y;
    int c;
} Point;

int getDistance ( Point g, Point i )
{
    return abs(g.x-i.x) + abs(g.y-i.y) - 1;
}

void makeGround ( int x, int y, int c )
{
    if( x < 0 || y < 0 || x >= n || y >= n || arr[ x ][ y ] != -1 ) return;
    if( arr[ x ][ y ] == -1 )
    {
        arr[x][y] = c;
        makeGround(x+1,y,c);
        makeGround(x-1,y,c);
        makeGround(x,y+1,c);
        makeGround(x,y-1,c);
    }
}

int main ( void )
{
    scanf( "%d", &n );
    
    int groundCnt = 0;
    for( int i = 0; i < n; ++ i )
        for( int j = 0; j < n; ++ j )
            scanf( "%d", &arr[ i ][ j ] );
    for( int i = 0; i < n; ++ i )
        for( int j = 0; j < n; ++ j )
            if( arr[i][j] == 1 ) arr[i][j] = -1, groundCnt++;
    
    int islandCnt = 0;
    for( int i = 0; i < n; ++ i )
    {
        for( int j = 0; j < n; ++ j )
        {
            if( arr[i][j] == -1 )
            {
                islandCnt++;
                makeGround( i, j, islandCnt );
            }
        }
    }
    if( islandCnt <= 1 )
    {
        printf( "0" );
        return 0;
    }
    
    Point grounds[ groundCnt ] = { 0 };
    groundCnt = 0;
    for( int i = 0; i < n; ++ i )
        for( int j = 0; j < n; ++ j )
            if( arr[i][j] >= 1 )
            {
                grounds[groundCnt].x = i, grounds[groundCnt].y = j;
                grounds[groundCnt].c = arr[i][j];
                groundCnt++;
            }
    
    int min = -1;
    int gIdx, iIdx;
    for( int i = 0; i < groundCnt; ++ i)
    {
        for( int j = i + 1; j < groundCnt; ++ j )
        {
            if( grounds[i].c == grounds[j].c ) continue;
            
            int distance = getDistance( grounds[i], grounds[j] );
            if( min == -1 || min > distance )
            {
                //printf("\nr : %lf\n", distance );
                //printf( "g : %d %d\ni: %d %d\n", grounds[i].x,grounds[i].y, grounds[j].x, grounds[j].y);
                min = distance;
                gIdx = i;
                iIdx = j;
            }
        }
    }
    
    /*
    for( int i = 0; i < n; ++ i )
    {
        printf( "\n" );
        for( int j = 0; j < n; ++ j )
            printf( "%d ", arr[i][j] );
    }
    */
    
    printf( "%d", min );
    
    return 0;
}