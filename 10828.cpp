#include <iostream>
#include <vector>
using namespace std;

int main ( ){
    vector<int> list;
    int n;
    cin >> n;
    for( int i = 0; i < n; ++ i ){
string str;
cin >> str;
if( str == "push" )
{
int tmp;
cin >> tmp;
list.push_back( tmp );
} else if ( str == "pop" ){
if( list.size() == 0 )
cout << -1 << endl;
 else
{
cout << list.back() << endl;
list.pop_back();
}
} else if ( str == "size" ){
cout << list.size() << endl;
} else if ( str == "empty" ){
if( list.size() == 0 )
cout << 1 << endl;
else
cout << 0 << endl;
} else if ( str == "top" )
if( list.size() == 0 )
cout << -1 << endl;
else
cout << list[ list.size()-1 ] << endl;
    }
    return 0;
}
