#include <iostream>
using namespace std;

int main ( void )
{
    int n;
    cin >> n;
    int left = 100001, right = 0;
    for( int i = 0; i < n; ++ i ){
        int a, b;
        cin >> a >> b;
        if( right < a ) right = a;
        if( left > b ) left = b;
    }   
    int t = right - left;
    if( t < 0 ) t = 0;
    cout << t;
    return 0;
}
