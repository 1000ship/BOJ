//두 자연수 A와 B가 주어진다. 이 때, A+B, A-B, A*B, A/B(몫), A%B(나머지)를 출력하는 프로그램을 작성하시오. 

#include <stdio.h>

int main ( void )
{
    int a, b;
    scanf( "%d %d", &a, &b );
    printf( "%d\n%d\n%d\n%d\n%d\n", a+b, a-b, a*b, a/b, a%b );
    return 0;
}