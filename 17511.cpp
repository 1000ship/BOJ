#include <iostream>
#include <vector>
using namespace std;

int N, M;
int *arr;

int main ( void )
{
	int i;
	cin >> N >> M;
	arr = new int[N];
	for(i = 0; i < N; ++ i )
		arr[i] = 1;
	for(i = 0; i < M; ++ i )
	{
		int a, b;
		cin >> a >> b;
		arr[b-1] = 0;	
	}

	vector<int> result;
	for(i = 0; i < N; ++ i )
		if( arr[i] )
			result.push_back(i+1);
	
	cout << result.size() << endl;
	for(i = 0; i < result.size(); ++ i )
		cout << result[i] << ' ';
	return 0;
}