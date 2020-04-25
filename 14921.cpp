#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int type;
    int origin;
} Number;

int compare ( const void* a, const void* b )
{
    if( (*(Number*)a).value > (*(Number*)b).value )
        return 1;
    return 0;
}

int main ( void )
{
    int n;
    int existPlus = 0, existMinus = 0;
    scanf( "%d", &n );
    
    Number nums[ n ] = { 0 };
    for( int i = 0 ; i < n; ++i )
    {
        int tmp;
        scanf( "%d", &tmp );
        if( tmp > 0 ) existPlus = 1;
        if( tmp < 0 ) existMinus = 1;
        nums[i].value = (tmp>=0)?tmp:-tmp;
        if( tmp == 0 )
            nums[i].type = -i;
        else if( tmp > 0 )
            nums[i].type = 1;
        else
            nums[i].type = 2;
        nums[i].origin = tmp;
    }
    qsort( nums, n, sizeof( Number ), compare );
    
    
    
    if( existMinus && existPlus )
    {
        int min = 200000000;
        int then = 0;
        int type = nums[0].type;
        for( int i = 1; i < n; ++ i)
        {
            if( nums[i].type != type )
            {
                int tmp = nums[i].value - nums[i-1].value;
                type = nums[i].type;
                if( min > tmp )
                {
                    min = tmp;
                    then = nums[i].origin + nums[i-1].origin;
                }
            }
        }
        printf( "%d", then );
    }
    else
        printf("%d", nums[0].origin + nums[1].origin);
    return 0;
}