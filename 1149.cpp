#include <iostream>
#include <algorithm>
using namespace std;

int main ( void )
{
    int n;
    cin >> n;
    int r[n], g[n], b[n];
    cin >> r[0] >> g[0] >> b[0];
    for( int i = 1; i < n; ++ i )
    {
        int R, G, B;
        cin >> R >> G >> B;
        r[i] = min( g[i-1]+R, b[i-1]+R);
        g[i] = min( r[i-1]+G, b[i-1]+G);
        b[i] = min( r[i-1]+B, g[i-1]+B);
    }
    int result = min( r[n-1], min(g[n-1],b[n-1]) );
    cout << result;
    return 0;
}