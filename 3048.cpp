#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name;
    int pos;
    int orient;
} Ant;


int compare ( const void* a, const void* b )
{
    if( (*(Ant*)a).pos > (*(Ant*)b).pos )
        return 1;
    return 0;
}

int main ( void )
{
    int an, bn;
    scanf( "%d %d", &an, &bn );
    Ant ants[ an + bn ] = { 0 };
    
    for( int i = 0; i < an; ++ i )
    {
        scanf( " %c", &ants[i].name );
        ants[ i ].pos = 2*(an-i)-1;
        ants[ i ].orient = 1;
    }
    for( int i = 0; i < bn; ++ i )
    {
        scanf( " %c", &ants[an+i].name );
        ants[an+i].pos = 2*an + 2*i;
        ants[an+i].orient = -1;
    }
    
    int t;
    scanf( "%d", &t );
    for( int i = 0 ; i < an+bn; ++ i )
    {
        ants[ i ].pos += ants[ i ].orient * t;
    }
    qsort( ants, an+bn, sizeof( Ant ), compare );
    for( int i = 0; i < an+bn; ++ i )
        printf( "%c", ants[ i ].name );
    
    return 0;
}