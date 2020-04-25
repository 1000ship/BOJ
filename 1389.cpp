#include <stdio.h>

int n, m;
int min = 999999999, minIdx = 0;
int relation[ 100 ][ 100 ] = { 0 };
int relationValue[ 100 ][ 100 ] = { 0 };

int isFriend ( int target, int friends[], int friendNum )
{
    for( int i = 0; i < friendNum; ++ i )
    {
        if( relation[ friends[ i ] ][ target ] )
            return 1;
    }
    return 0;
}

void findAndCheck ( int root, int targets[], int targetNumber, int check[], int level )
{
    int friendList[ 100 ], friendListLength = 0;
    for( int i = 0; i < 100; ++ i )
    {
        if( !check[ i ] )
        {
            if( isFriend( i, targets, targetNumber ) )
            {
                check[ i ] = 1;
                friendList[ friendListLength ++ ] = i;
                relationValue[ root ][ i ] = relationValue[ i ][ root ] = level;
            }
        }
    }
    if( friendListLength != 0 )
        findAndCheck( root, friendList, friendListLength, check, level + 1 );
}

int main ( void )
{
    int x, y;
    scanf( "%d %d", &n, &m );
    
    for( int i = 0; i < m; ++ i )
    {
        scanf( "%d %d", &x, &y );
        x--, y--;
        relation[ x ][ y ] = relation[ y ][ x ] = 1;
    }
    
    for( int i = 0; i < n; ++ i )
    {
        int check[ 100 ] = { 0 };
        int targets[ 1 ] = { i };
        check[ i ] = 1;
        findAndCheck ( i, targets, 1, check, 1 );
    }
    
    for( int i = 0; i < n; ++ i )
    {
        int sum = 0;
        for( int j = 0; j < n; ++ j )
            sum += relationValue[ j ][ i ];
        if( sum < min )
        {
            min = sum;
            minIdx = i;
        }
    }
    printf( "%d", minIdx + 1 );
    return 0;
}