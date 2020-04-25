#include <stdio.h>
#include <stdlib.h>

#define ROAD 0
#define WALL 1
#define KEY(i) i+2

typedef struct point_struct {
    int x;
    int y;
} Point;

typedef struct line_struct {
    int start;
    int end;
    int value;
} Line;

int n, m;
int map[ 50 ][ 50 ] = { 0 };
int relation[ 251 ][ 251 ] = { 0 };
Point keys[ 251 ];

void expanding( int check[][50], Point arr[], int num, int step, int layer )
{
    Point stack[ num * 4 ];
    int len = 0;
    for( int i = 0; i < num; ++ i )
    {
        int x = arr[i].x, y = arr[i].y;
        if( map[x][y] > WALL && map[x][y] != KEY( layer ) )
        {
            int target = map[x][y] - 2;
            if( relation[target][layer] == 0 || relation[target][layer] > step )
                relation[target][layer] = relation[layer][target] = step;
        }
        
        if( x > 0 && !check[x-1][y] && map[x-1][y] != WALL )
            stack[len].x = x-1, stack[len].y = y, check[x-1][y]=1, len++;
        if( x < n-1 && !check[x+1][y] && map[x+1][y] != WALL )
            stack[len].x = x+1, stack[len].y = y, check[x+1][y]=1, len++;
        if( y > 0 && !check[x][y-1] && map[x][y-1] != WALL )
            stack[len].x = x, stack[len].y = y-1, check[x][y-1]=1, len++;
        if( y < n-1 && !check[x][y+1] && map[x][y+1] != WALL )
            stack[len].x = x, stack[len].y = y+1, check[x][y+1]=1, len++;
    }
    
    if( len != 0 )
        expanding( check, stack, len, step + 1, layer );
}

void startExpanding ( int x, int y, int layer )
{
    int check[ 50 ][ 50 ] = { 0 };
    Point arr[1];
    arr[ 0 ].x = x, arr[ 0 ].y = y;
    check[ x ][ y ] = 1;
    expanding( check, arr, 1, 0, layer );
}

int compareLine ( const void* a, const void* b )
{
    Line* l1 = (Line*)a;
    Line* l2 = (Line*)b;
    return l1->value > l2->value;
}

int getKruskal( Line lines[], int n, int m )
{
    int result = 0;
    int state[ n ];
    for( int i = 0; i < n; ++ i )
        state[ i ] = i;
    for( int i = 0; i < m; ++ i )
    {
        int start = state[ lines[i].start ];
        int end = state[ lines[i].end ];
        while( start != state[ start ] ) start = state[ start ];
        while( end != state[ end ] ) end = state[ end ];
        if( start != end )
        {
            result += lines[ i ].value;
            if( start < end )
                state[ end ] = start;
            else
                state[ start ] = end;
        }
    }
    return result;
}

int main ( void )
{
    char c;
    int idx = 0;
    
    //FILE* f = fopen( "sample.txt", "r" );
    //fscanf( f, "%d %d", &n, &m );
    scanf( "%d %d", &n, &m );
    for( int y = 0; y < n; ++ y )
    for( int x = 0; x < n; ++ x )
    {
        //fscanf( f, " %c", &c );
        scanf( " %c", &c );
        switch( c )
        {
            case '0':
                map[ x ][ y ] = ROAD;
                break;
            case '1':
                map[ x ][ y ] = WALL;
                break;
            case 'S':
                map[ x ][ y ] = KEY( m );
                keys[ m ].x = x;
                keys[ m ].y = y;
                break;
            case 'K':
                map[ x ][ y ] = KEY( idx );
                keys[ idx ].x = x;
                keys[ idx ].y = y;
                idx++;
                break;
        }
    }
    
    for( int i = 0; i <= m; ++ i )
        startExpanding( keys[i].x, keys[i].y, i );
    
    int result = 0;
    Line lines[ m * (m+1) / 2 ];
    int num = 0;
    for( int i = 0; i < m; ++ i)
    {
        for( int j = i + 1; j <= m; ++ j )
        {
            lines[num].start = i;
            lines[num].end = j;
            lines[num].value = relation[i][j];
            num++;
            if( relation[i][j] == 0 )
                i = m, j = m + 1, result = -1;
        }
    }
    if( result != -1 )
    {
        qsort( lines, num, sizeof( Line ), compareLine );
        result = getKruskal( lines, m + 1, num );
    }
    
    printf( "%d", result );
    
    return 0;
}