#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int x, ele[ 6 ], num = 0;
int arr[ 720 ] = { 0 }, cnt = 0;

int sel[ 6 ] = { 0 };
bool isSel[ 6 ] = { 0 };

int compare ( const void* first, const void* second )
{
    if( *(int*)first > *(int*)second ) return 1;
    return 0;
}

void calc ( int depth )
{
    /*for( int i = 0; i < depth; ++ i )
        printf( "%d, ", sel[ i ] );
    printf( "\n: depth -> %d\n", depth );*/
    
    if( depth == num )
    {
        if( sel[ num-1 ] == 0 ) return;
        int tmp = 0;
        for( int i = 0; i < num; ++ i )
            tmp += sel[ i ] * pow( 10, i );
        arr[ cnt ] = tmp;
        cnt++;
        return;
    }
    
    for( int i = 0; i < num; ++ i )
    {
        if( isSel[ i ] ) continue;
        sel[ depth ] = ele[ i ], isSel[ i ] = 1;
        calc( depth + 1 );
        isSel[ i ] = 0;
    }
}

int main ( void )
{
    scanf( "%d", &x );
    
    for( int i = 1; x / i > 0; i *= 10)
        ele[ num ] = (x/i) % 10, num ++;
    
    calc( 0 );
    qsort( arr, cnt, sizeof(int), compare );
    
    int i, isFind = 0;
    for( i = 0; i < cnt; ++ i )
    {
        if( isFind && arr[ i ] != x )
            break;
        else if( arr[ i ] == x )
            isFind = 1;
    }
    
    if( i == cnt ) printf( "0" );
    else printf( "%d", arr[ i ] );
    
    return 0;
}