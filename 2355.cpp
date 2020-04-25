#include <stdio.h>
#define ll long long

ll abs ( ll n )
{
    return (n<0)?-n:n;
}

ll sum ( ll what )
{
    return what * (what + 1) / 2;
}

int main ( void )
{
    ll a, b;
    scanf( "%lld %lld", &a, &b );
    
    bool isDiff = (a<0&&b>=0) || (a>=0&&b<0);
    ll small, big;
    if (abs(a)>abs(b))
        big=a, small=b;
    else
        big=b, small=a;
    ll tmp = sum( abs(big) ) - sum( abs(small) );
    if( !isDiff ) tmp += abs(small);
    if( big < 0 ) tmp *= -1;
    
    printf( "%lld", tmp );
    return 0;
}