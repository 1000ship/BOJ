#include <iostream>
#include <math.h>
using namespace std;

int main (void){
    int n, result;
    cin >> n;
    int a, b, c;
    cin >> a >> b >> c;
    int r, d, what;
    r = b / a;
    d = b - a;
    if( d == c - b ) 
        what = 1;
    else
        what = 0;
    if( what )
        result = a + (d*(n));
    else
        result = a * pow( r, n );
    cout << result;
    return 0;
}
