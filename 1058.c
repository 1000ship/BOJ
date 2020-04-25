#include <stdio.h>

int n, friends[50][50], friends2[50][50], result[ 50 ];

void makefriend ( int a, int b )
{
	friends2[ a ][ b ] = friends2[ b ][ a ] = 1;
}

void find_friends2 ( int whose )
{
	for( int i = 0; i < n; ++ i ){
		if( i == whose || !friends[ whose ][ i ] ) continue;
		for( int j = 0; j < n; ++ j )
		{
			if( whose == j ) continue;
			if( friends[ i ][ j ] ) makefriend( whose, j );
		}
	}
	int cnt = 0;
	for( int i = 0; i < n; ++ i )
		if( friends2[ whose ][ i ] ) cnt++;
	result[ whose ] = cnt;
}

int main(void) {
	char c;
	scanf( "%d", &n );
	for( int i = 0; i < n; ++ i ){
		for( int j = 0; j < n; ++ j ){
			scanf("%c", &c);
			if( c != 'Y' && c != 'N' ) scanf("%c", &c);
			if( c == 'Y' ) friends[ i ][ j ] = friends2[ i ][ j ] = 1;
			else if ( c == 'N' ) friends[ i ][ j ] = friends2[ i ][ j ] = 0;
		}
	}
	
	for( int i = 0; i < n; ++ i )
		find_friends2( i );
	
	int max = 0;
	for( int i = 0; i < n; ++ i )
		if( result[ i ] > max ) max = result[ i ];
	/* check
	for( int i = 0; i < n; ++ i ){
		for( int j = 0; j < n; ++ j ){
			printf( "%d", friends2[ i ][ j ] );
		}
		printf( "\n" );
	}
	//*/
	
	printf( "%d", max );
	
	return 0;
}
