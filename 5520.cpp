#include <stdio.h>
#define FOR(i,v) for(int i = 0; i < v ; ++ i)

int history[ 9 ] = { 0 };

int movementValue[ 9 ] = { 0 };
int movement[ 9 ][ 9 ] = {
  //{ A, B, C, D, E, F, G, H, I }
    { 1, 1, 0, 1, 1, 0, 0, 0, 0 }, // ABDE
    { 1, 1, 1, 0, 0, 0, 0, 0, 0 }, // ABC
    { 0, 1, 1, 0, 1, 1, 0, 0, 0 }, // BCEF
    { 1, 0, 0, 1, 0, 0, 1, 0, 0 }, // ADG
    { 0, 1, 0, 1, 1, 1, 0, 1, 0 }, // BDEFH
    { 0, 0, 1, 0, 0, 1, 0, 0, 1 }, // CFI
    { 0, 0, 0, 1, 1, 0, 1, 1, 0 }, // DEGH
    { 0, 0, 0, 0, 0, 0, 1, 1, 1 }, // GHI
    { 0, 0, 0, 0, 1, 1, 0, 1, 1 }  // EFHI
};

int memory = 0, isEnd = 0;

int getMemory ( int mem, int idx )
{
    return (mem >> (idx * 3)) % 8;
}

void setMemory ( int* mem, int idx, int value )
{
    *mem -= getMemory( *mem, idx ) << (idx * 3);
    *mem += value << (idx * 3);
}

void addMemory ( int* mem, int idx, int value )
{
    int tmp = getMemory( *mem, idx ) + value;
    tmp %= 4;
    switch( tmp )
    {
        case -1:
            tmp = 3;
            break;
        case -2:
            tmp = 2;
            break;
        case -3:
            tmp = 1;
            break;
    }
    setMemory( mem, idx, tmp );
}

int getMovementValue ( int arr[] )
{
    int tmp = 0;
    for( int i = 0; i < 9; ++ i )
        if( arr[ i ] )
            addMemory( &tmp, i, 1 );
    return tmp;
}

int remake ( int value )
{
    int tmp = 0;
    FOR( i, 9 )
        tmp += ((value>>(i*3))%4)<<(i*3);
    return tmp;
}

void calculate ( int target, int count, int from )
{
    
    if( isEnd ) return;
    
    if( count == 0 )
    {
        if( !target )
            isEnd = true;
        return;
    }
    
    for( int i = from; i < 9; ++ i )
    {
        if( !isEnd )
        {
            if( history[ i ] == 3 )
                continue;
            history[ i ] ++;
        }
        calculate( remake( target + movementValue[ i ] ), count - 1, i );
        if( !isEnd ) history[ i ] --;
    }
}

int main ( void )
{
    int input;
    for( int i = 0; i < 9; ++ i )
    {
        scanf( "%d", &input );
        setMemory( &memory, i, input );
    }
    
    for( int i = 0; i < 9; ++ i )
        movementValue[ i ] = getMovementValue( movement[ i ] );
    
    // level개를 선택하는 중복조합, 될때까지 선택 수를 높혀 반복함.
    int level = 0;
    while( !isEnd )
    {
        calculate( memory, level++, 0 );
    }
    
    for( int i = 0; i < 9; ++ i )
        for( int j = 0; j < history[ i ]; ++ j )
            printf( "%d ", i + 1 );
    return 0;
}