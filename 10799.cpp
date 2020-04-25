#include <iostream>
#include <string.h>
using namespace std;



int main ( void )
{
    char str[100001];
    cin >> str;
    int cnt = 0;
    int len = strlen( str );
    
    int level = 0;
    for( int i = 0; i < len; ++ i )
    {
        char c = str[ i ];
        if( c == '(' && str[i+1] != ')' )
            cnt += 1, level += 1;
        else if( c == ')' && str[i-1] != '(' )
            level -= 1;
        else if( c == '(' && str[i+1] == ')' )
            i += 1, cnt += level;
    }
    cout << cnt;
    return 0;
}