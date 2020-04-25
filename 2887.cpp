#include <stdio.h>
#include <stdlib.h>

typedef struct planet_struct {
    int id;
    int x;
    int y;
    int z;
} Planet;

typedef struct line_struct {
    int start;
    int end;
    long long value;
} Line;

long long absValue ( long long x )
{
    return (x<0)?-x:x;
}

long long getDistance ( Planet p1, Planet p2 )
{
    long long result = absValue(p1.x - p2.x), tmp;
    tmp = absValue(p1.y - p2.y);
    if( result > tmp ) result = tmp;
    tmp = absValue(p1.z - p2.z);
    if( result > tmp ) result = tmp;
    return result;
}

int compareX ( const void* a, const void* b )
{
    Planet* x = (Planet*)a;
    Planet* y = (Planet*)b;
    return x->x > y->x;
}

int compareY ( const void* a, const void* b )
{
    Planet* x = (Planet*)a;
    Planet* y = (Planet*)b;
    return x->y > y->y;
}

int compareZ ( const void* a, const void* b )
{
    Planet* x = (Planet*)a;
    Planet* y = (Planet*)b;
    return x->z > y->z;
}

int compareLine ( const void* a, const void* b )
{
    Line* x = (Line*)a;
    Line* y = (Line*)b;
    return x->value > y->value;
}

long long getKruskal ( Line lines[], int n, int m )
{
    long long sum = 0;
    int state[ n ];
    for( int i = 0; i < n; ++ i )
        state[ i ] = i;
    for( int i = 0; i < m; ++ i )
    {
        int start = state[ lines[ i ].start ];
        int end = state[ lines[ i ].end ];
        while( start != state[ start ] ) start = state[ start ];
        while( end != state[ end ] ) end = state[ end ];
        if( start != end )
        {
            sum += lines[ i ].value;
            if( start < end )
                state[ end ] = start;
            else
                state[ start ] = end;
        }
    }
    return sum;
}

int main ( void )
{
    int n;
    scanf( "%d", &n );
    
    Planet planets[ n ];
    for( int i = 0; i < n; ++ i )
    {
        planets[i].id = i;
        scanf( "%d %d %d", &planets[i].x, &planets[i].y, &planets[i].z );
    }
    
    Line lines[ n * 3 ];
    int num = 0;
    
    for( int j = 0; j < 3; ++ j )
    {
        switch( j )
        {
            case 0:
                qsort( planets, n, sizeof( Planet ), compareX );
                break;
            case 1:
                qsort( planets, n, sizeof( Planet ), compareY );
                break;
            case 2:
                qsort( planets, n, sizeof( Planet ), compareZ );
                break;
        }
        for( int i = 0; i < n - 1; ++ i )
        {
            lines[ num ].start = planets[i].id;
            lines[ num ].end = planets[i+1].id;
            lines[ num ].value = getDistance( planets[ i ], planets[ i + 1 ] );
            num++;
        }
    }
    qsort( lines, num, sizeof( Line ), compareLine );
    
    long long result = getKruskal( lines, n, num );
    printf( "%lld", result );
    return 0;
}