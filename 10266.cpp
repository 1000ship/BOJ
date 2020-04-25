#include <stdio.h>

int main ( void )
{
    int isPossible = 0;
    char angle1[ 360000 ] = { 0 }, angle2[ 360000 ] = { 0 };
    int n, tmp, gap1[ 400000 ] = { 0 }, gap2[ 200000 ] = { 0 };
    
    scanf( "%d", &n );
    for( int i = 0; i < n; ++ i )
    {
        scanf( "%d", &tmp );
        angle1[ tmp ] = 1;
    }
    for( int i = 0; i < n; ++ i )
    {
        scanf( "%d", &tmp );
        angle2[ tmp ] = 1;
    }
    
    int idx1 = -1, idx2 = -1, flag1 = 0, flag2 = 0;
    for( int i = 0; i < 360000; ++ i )
    {
        if( angle1[ i ] )
        {
            if( idx1 == -1 )
                idx1++, gap1[ n - 1 ] = i - flag1;
            else
                gap1[ idx1 ] = i - flag1, idx1++;
            flag1 = i + 1;
        }
        if( angle2[ i ] )
        {
            if( idx2 == -1 )
                idx2++, gap2[ n - 1 ] = i - flag2;
            else
                gap2[ idx2++ ] = i - flag2;
            flag2 = i + 1;
        }
    }
    gap1[ idx1 ] += 360000 - flag1, gap2[ idx2 ] += 360000 - flag2;
    for( int i = 0; i < n; ++ i )
        gap1[ n + i ] = gap1[ i ];
    
    //-----------------------------------
    int fail[ n ];
    for( int i = 0; i < n; ++ i ) fail[ i ] = 0;
    for( int i = 1, j = 0; i < n; i ++ ){
        while( j > 0 && gap2[i] != gap2[j]) j = fail[ j - 1 ];
        if( gap2[ i ] == gap2[ j ] ) fail[ i ] = ++ j;
    }
    
    for(int i = 0, j = 0; i < 2 * n; i++){
        // 현재 글자가 불일치하면 fail 값을 계속 따라감
        while(j > 0 && gap1[i] != gap2[j]) j = fail[ j - 1 ];
        // 현재 글자가 일치
        if( gap1[ i ] == gap2[ j ] ){
            if( j == n - 1 ){
                isPossible = 1;
                j = fail[j];
            }
            else j++;
        }
    }
    //-------------------------------------
    
    if( isPossible )
        printf( "possible" );
    else
        printf( "impossible" );
    return 0;
}