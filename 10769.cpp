#include <stdio.h>
#include <string.h>

int main ( void )
{
    char str[256];
    char happy[] = ":-)";
    char sad[] = ":-(";
    char *value;
    
    gets( str );
    int hCount = 0, sCount = 0;
    
    value = strstr( str, happy );
    while( value != NULL )
    {
        value += 3;
        hCount += 1;
        value = strstr( value, happy );
    }
    
    value = strstr( str, sad );
    while( value != NULL )
    {
        value += 3;
        sCount += 1;
        value = strstr( value, sad );
    }
    
    if( hCount == 0 && sCount == 0 )
        printf( "none" );
    else if( hCount > sCount )
        printf( "happy" );
    else if( hCount == sCount )
        printf( "unsure" );
    else
        printf( "sad" );
    
    return 0;
}