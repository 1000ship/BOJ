#include <stdio.h>

int n, t, g;
int minBtn = 999999;
int rec[100000];

void calc ( int num, int cnt )
{
    //printf( "num: %d, cnt: %d\n", num, cnt );
    
    // 기록 갱신
    if( rec[num] == -1 || rec[num] > cnt )
        rec[num] = cnt;
    else if( rec[num] <= cnt ) return;
    
    // 정답이면 기록도 했으니까 그만해
    if( num == g )
        return;
    // 최대횟수 넘어가도 그만해
    if( cnt == t ) return;
        
        
    // A Button
    if( num != 99999 )
        calc( num + 1, cnt + 1 );
        
    // B button
    int next_num = num * 2;
    if( next_num <= 99999 )
    {
        int dev;
        for( dev = 1; next_num / dev > 0; dev *= 10);
        dev /= 10;
        next_num -= dev;
        calc( next_num, cnt + 1 );
    }
    
}

int main ( void )
{
    for( int i = 0; i < 100000; ++ i )
        rec[ i ] = -1;
    scanf( "%d %d %d", &n, &t, &g );
    calc( n, 0 );
    
    if( rec[ g ] == -1 )
        printf( "ANG" );
    else
        printf( "%d", rec[ g ] );
    
    return 0;
}