#include <stdio.h>
//음주코딩
int main ( void )
{
    int n;
    scanf("%d", &n);
    for( int i = n; i > 0; -- i )
    {
        for(int j =0; j < i ; ++ j )
            printf("*");
        printf("\n");
    }
    return 0;
}