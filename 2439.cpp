#include <stdio.h>

// 술먹고 코딩중
int main ( void )
{
    int n;
    scanf("%d", &n);
    for(int i=0; i < n; ++ i )
        for(int j=0; j<n; ++ j )
            printf( (j == n - 1 )?"%c\n":"%c", (i+j>n-2)?'*':' ' );
    return 0;
}