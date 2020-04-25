#include <stdio.h>

int n, m, d;
int turn, monCnt;
int arr[16][16];
int max = 0;

int abs ( int x )
{
    return (x>0)?x:-x;
}

class Monster {
public:
    int x; // will be added by 1
    int y;
    int getd( int a )
    {
        return (n-(x+turn)) + abs(a-y);
    }
};
Monster *mons;


void calc ( int a1, int a2, int a3 )
{
    int kill = 0;
    int castle = 0;
    bool isKilled[ monCnt ] = { 0 };
    turn = 0;
    while( kill + castle < monCnt )
    {
        // attack
        int a1t = -1, a2t = -1, a3t = -1;
        int a1d = -1, a2d = -1, a3d = -1;
        for( int i = 0; i < monCnt; ++ i )
        {
            if( isKilled[i] ) continue;
            if( n - mons[i].x <= turn )
            {
                if( !isKilled[i] )
                    isKilled[i] = true, castle++;
                continue;
            }
            int tmp;
            tmp = mons[i].getd(a1);
            if( (a1d == -1 || a1d > tmp) && tmp <= d )
                a1d = tmp, a1t = i;
            tmp = mons[i].getd(a2);
            if( (a2d == -1 || a2d > tmp) && tmp <= d )
                a2d = tmp, a2t = i;
            tmp = mons[i].getd(a3);
            if( (a3d == -1 || a3d > tmp) && tmp <= d )
                a3d = tmp, a3t = i;
        }
        if( a1t != -1 && !isKilled[a1t] ){
            isKilled[a1t] = true;
            kill++;
        }
        if( a2t != -1 && !isKilled[a2t] ){
            isKilled[a2t] = true;
            kill++;
        }
        if( a3t != -1 && !isKilled[a3t] ){
            isKilled[a3t] = true;
            kill++;
        }
        // move
        turn++;
    }
    if( max < kill )
        max = kill;
}

int main ( void )
{
    scanf( "%d %d %d", &n, &m, &d );
    monCnt = 0;
    for( int i = 0; i < n; ++ i )
        for( int j = 0; j < m; ++ j )
        {
            int tmp;
            scanf( "%d", &tmp );
            arr[i][j] = tmp;
            if( tmp ) monCnt ++;
        }
    mons = new Monster[monCnt];
    monCnt = 0;
    for( int j = 0; j < m; ++ j )
        for( int i = 0; i < n; ++ i )
        {
            if( arr[i][j] )
            {
                mons[monCnt].x = i;
                mons[monCnt].y = j;
                monCnt++;
            }
        }
    
    for( int i = 0; i < m; ++ i )
        for( int j = i + 1; j < m; ++ j )
            for( int k = j + 1; k < m; ++ k )
                calc( i, j, k );
    printf( "%d", max );
    return 0;
}