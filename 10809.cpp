#include <stdio.h>
#include <string.h>

int main ( void )
{
    char str[100];
    scanf("%s", str);
    
    int k = 0;
    for( int i = 0; i < 26; ++ i )
    {
        char *what = strchr( str, { 'a'+i } );
        int idx = (what==0)?-1:what-str;
        printf( "%d ", idx );
    }
    return 0;
}