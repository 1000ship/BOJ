//첫째 줄에 빈 칸을 사이에 두고 x(1≤x≤12)와 y(1≤y≤31)이 주어진다.
//참고로 2007년에는 1, 3, 5, 7, 8, 10, 12월은 31일까지, 4, 6, 9, 11월은 30일까지, 2월은 28일까지 있다.

#include <stdio.h>

int main ( void )
{
    int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 };
    int m, d, value = 0;
    scanf( "%d %d", &m, &d );
    for( int i = 0; i < m - 1; ++ i )
        value += days[ i ];
    value += d;
    
    switch( value % 7 )
    {
        case 0:
            printf( "SUN");
            break;
        case 1:
            printf( "MON");
            break;
        case 2:
            printf( "TUE");
            break;
        case 3:
            printf( "WED");
            break;
        case 4:
            printf( "THU");
            break;
        case 5:
            printf( "FRI");
            break;
        case 6:
            printf( "SAT");
            break;
    }
    return 0;
}
//첫째 줄에 x월 y일이 무슨 요일인지에 따라 SUN, MON, TUE, WED, THU, FRI, SAT중 하나를 출력한다.