#include <stdio.h>

int main()
{
    int a, b, c, max, min;
    scanf( "%d %d %d", &a, &b, &c );
    max = (a>b)?a:b;
    max = (max>c)?max:c;
    min = (a>b)?b:a;
    min = (min>c)?c:min;
    printf( "%d", a+b+c-max-min );
    return 0;
}

