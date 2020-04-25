#include <stdio.h>

void swap ( char *arr, int a, int b )
{
    int tmp = arr[ a ];
    arr[ a ] = arr[ b ];
    arr[ b ] = tmp;
}

int main()
{
    char arr[4] = { 1, 0, 0, 2 };
    char c;
    
    while( (c=getchar()) != EOF )
    {
        switch( c )
        {
            case 'A':
                swap( arr, 0, 1 );
            break;
            case 'B':
                swap( arr, 0, 2 );
            break;
            case 'C':
                swap( arr, 0, 3 );
            break;
            case 'D':
                swap( arr, 1, 2 );
            break;
            case 'E':
                swap( arr, 1, 3 );
            break;
            case 'F':
                swap( arr, 2, 3 );
            break;
        }
    }
    
    int i, min = 0, max = 0;
    for( i = 0; i < 4; ++ i )
        if( arr[ i ] == 1 ) min = i + 1;
        else if( arr[ i ] == 2 ) max = i + 1;
        
    printf( "%d %d", min, max );

    return 0;
}

