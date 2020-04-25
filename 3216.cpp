#include <iostream>
#include <string.h>
using namespace std;

int abs (int x )
{
    return (x>0)?x:-x;
}

int main ( void )
{
    int n;
    cin >> n;
    int d[n], v[n];
    for( int i = 0; i < n; ++ i )
        cin >> d[i] >> v[i];
    int t = v[0];
    int yy = d[0];
    for( int i = 1; i < n; ++ i )
    {
        int tmp = v[i];
        if( tmp <= yy )
            yy -= tmp, tmp = 0;
        else
            tmp -= yy, yy = 0;
        t += tmp;
        yy += d[i];
    }
    cout << t;
    return 0;
}