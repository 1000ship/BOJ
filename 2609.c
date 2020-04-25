//첫째 줄에는 입력으로 주어진 두 수의 최대공약수를,둘째 줄에는 입력으로 주어진 두 수의 최소 공배수를 출력한다.

#include <stdio.h>

int bbb ( int a, int b, int c )
{
    return a*b/c;
}

int aaa ( int a, int b )
{
    int min = (a>b)?b:a;
    for( int i = min; i >= 1; -- i )
    {
        if( a % i == 0 && b % i == 0 )
            return i;
    }
    return 1;
}

int main ( void )
{
    int a, b;
    scanf( "%d %d", &a, &b );
    
    int c = aaa( a, b );
    printf( "%d\n%d", c, bbb(a,b,c) );
    return 0;
}