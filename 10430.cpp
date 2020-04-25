//첫째 줄에 (A+B)%C, 둘째 줄에 (A%C + B%C)%C, 셋째 줄에 (A×B)%C, 넷째 줄에 (A%C × B%C)%C를 출력한다.

#include <stdio.h>

int main ( void )
{
    int a,b,c;
    scanf( "%d %d %d", &a, &b, &c );
    printf( "%d\n%d\n%d\n%d\n", (a+b)%c, (a%c + b%c)%c, (a*b)%c, (a%c*b%c)%c );
    return 0;
}