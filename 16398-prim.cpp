#include <iostream>
#define ull unsigned long long
using namespace std;

int min ( int a, int b )
{
	return (a>b)?b:a;
}

int main ( void )
{
	int n;
	cin >> n;

	int relation[n][n];
	for( int i = 0; i < n; ++ i )
		for( int j = 0; j < n; ++ j )
			cin >> relation[i][j];
	
	ull sum = 0;
	bool selected[n];
	int distance[n];
	for( int i = 0; i < n; ++ i )
		distance[i] = 2 << 29, selected[i] = false;
	
	distance[0] = 0;
	for( int test_case = 0; test_case < n; ++ test_case )
	{
		int who = -1;
		int m = 2 << 29;
		for( int i = 0; i < n; ++ i )
			if( !selected[i] && m > distance[i] )
				m = distance[i], who = i;
		selected[who] = true;
		sum += distance[who];
		for(int k = 0; k < n; ++ k)
			distance[k] = min(distance[k], relation[who][k]);
	}

	cout << sum;
}