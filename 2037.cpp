#include <stdio.h>
#include <string.h>

int main ( void )
{
    int p, w;
    char str[ 1000 ];
    
    scanf( "%d %d ", &p, &w );
	fgets(str, sizeof(str), stdin);
	
	//printf( "%d %d\n%s\nlen : %d\n", p, w, str, strlen( str ) );
	
    int type[ 27 ] = { 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9 };
    // 공백부터 A - Z
    
    int tm[ 27 ] = { 1, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4 };
    // 필요 타자 입력 수 * p
    
    int timer = 0;
    int currentType = 0;
    int len = strlen( str );
    for( int i = 0; i < len; ++ i )
    {
        char c = str[ i ];
        if( c != ' ' && !(c >= 'A' && c <= 'Z') ) break;
        int code = (c==' ')?0:c-'A'+1;
        
        if( currentType == type[ code ] && currentType != 1 )
            timer += w;
        currentType = type[ code ];
        timer += p * tm[ code ];
    }
    
    printf( "%d", timer );
    
    return 0;
}