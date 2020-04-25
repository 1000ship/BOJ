#include <stdio.h>

int min = 999999999;

void calculate ( int n, int cnt )
{
	if( n == 1 )
	{
		if( min > cnt ) min = cnt;
		return;
	}
	if( min <= cnt ) return;
	
	if( n % 3 == 0 ) calculate( n / 3, cnt + 1 );
	if( n % 2 == 0 ) calculate( n / 2, cnt + 1 );
	calculate( n - 1, cnt + 1 );
}

int main()
{
	int n;
	scanf( "%d", &n );
	calculate( n, 0 );
	printf( "%d", min );
	return 0;
}