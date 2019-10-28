#include <iostream>
#include <vector>
#include <algorithm>
#define ull unsigned long long
using namespace std;

class Edge {
	public:
	int start;
	int end;
	ull value;

	Edge( int start, int end, ull value ){
		this->start = start;
		this->end = end;
		this->value = value;
	}
};

bool compare (Edge a, Edge b){
	return a.value < b.value;
}

int main ( void )
{
	int n;
	cin >> n;

	ull sum = 0;
	int cnt = 0;
	int owner[n];
	for( int i = 0; i < n; ++ i )
		owner[i] = i;

	vector<Edge> edges;
	edges.reserve(n-1);

	int edge_size = 0;
	for( int i = 0; i < n; ++ i )
		for( int j = 0; j < n; ++ j )
		{
			ull in;
			cin >> in;
			if( j <= i ) continue;
			edges.push_back( Edge( i, j, in ) );
			edge_size++;
		}
	sort( edges.begin(), edges.end(), compare );
	for( int i = 0; i < edge_size; ++ i )
	{
		int s = edges[i].start;
		int e = edges[i].end;
		while( s != owner[s] ) s = owner[s];
		while( e != owner[e] ) e = owner[e];
		if( s == e )
			continue;
		if( s > e )
			owner[s] = e;
		else
			owner[e] = s;
		sum += edges[i].value;
		cnt++;
		if( cnt == n-1 )
			break;
	}
	cout << sum;
	return 0;
}
