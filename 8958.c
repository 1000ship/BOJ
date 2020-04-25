#include <stdio.h>

int main ( void )
{
    int case_num;
    scanf( "%d", &case_num );
    
    char arr[80];
    for( int case_idx = 0; case_idx < case_num; ++ case_idx )
    {
        scanf( "%s", arr );
        
        int score = 0, combo = 0, i = 0;
        while( arr[ i ] != '\0' )
        {
            switch( arr[ i ] )
            {
                case 'O':
                    combo += 1;
                    score += combo;
                    break;
                case 'X':
                    combo = 0;
                    break;
            }
            ++i;
        }
        printf( "%d\n", score );
    }
}