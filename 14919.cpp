#include <stdio.h>
#include <math.h>

int main ( void )
{
    int m;
    scanf( "%d", &m );
    
    int interval =  1000000 / m;
    int mod = 1000000 % m;
    int cnt[m] = { 0 };
    
    char str[10];
    while( scanf("%s", &str) != EOF)
    {
        int tmp = 0;
        for( int i = 2; str[ i ] != 0; ++ i )
            tmp += (str[i]-'0') * (int)pow(10, 7-i);
        
        int idx = tmp / interval;
        if( idx != 0 && mod != 0 && tmp % interval == 0 )
            idx --;
        cnt[ idx ]++;
    }
    
    for( int i = 0; i < m; ++ i )
        printf( "%d ", cnt[ i ] );
    return 0;
}