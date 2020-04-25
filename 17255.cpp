#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> possible;

void my_union( string str ){
    if( find( possible.begin(), possible.end(), str ) == possible.end() )
        possible.push_back( str );
}

void func(string &str, int left, int right, string result){
    if( right - left >= str.length())
        my_union( result );
    if( left > 0 ) 
        func(str,left-1,right,result+"-"+str.substr(left-1,right-left+1));
    if( right < str.length() )
        func(str,left,right+1, result+"-"+str.substr(left,right-left+1));
}

int main(void){
    string str;
    cin >> str;
    for( int i = 0; i < str.length(); ++ i ){
        string tmp = str.substr(i,1);
        func(str, i, i+1, tmp);
    }   

    //for( int i = 0; i < possible.size(); ++ i )
    //  cout << possible[i] << endl;
    cout << possible.size();
    return 0;
}
