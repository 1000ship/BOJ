#include <stdio.h>

char arr[4194304] = {0};

int check ( int  x )
{
    char value = 1;
    value <<= x % 8;
    int result = arr[ x >> 3 ] & value;
    arr[ x >> 3 ] |= value;
    return result;
}

int main()
{
    int result, n;
    
    while(1)
    {
        result = scanf("%d",&n);
        if( result == EOF ) break;
        if( !check( n ) )
            printf("%d ", n);
    }
    return 0;
}

