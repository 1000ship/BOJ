#include <stdio.h>

int main()
{
   int n;
   scanf( "%d", &n );
   
   int arr[ 50 ];
   for( int i = 0; i < n; ++ i )
   {
       scanf( "%d", &arr[ i ] );
   }
   
   int cnt, max;
   
    cnt = 0; max = 0;
    for( int i = 0; i < n; ++ i )
        if( max < arr[ i ] ) max = arr[ i ], cnt++;
    printf( "%d\n", cnt );
    
    cnt = 0; max = 0;
    for( int i = n - 1; i >= 0; -- i )
        if( max < arr[ i ] ) max = arr[ i ], cnt++;
    printf( "%d", cnt );
    
   return 0;
}