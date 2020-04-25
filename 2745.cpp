#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int getValue( char x ){
    if( x >= '0' && x <= '9' )
        return x-'0';
    return x-'A'+10;
}

int main ( ) 
{
    string str;
    int jb; 
    cin >> str >> jb; 
    int result = 0;
    for( int i = 0; i < str.length(); ++ i ) 
        result += pow(jb,str.length()-i-1) * getValue(str[i]);
    cout << result;
    return 0;
}
