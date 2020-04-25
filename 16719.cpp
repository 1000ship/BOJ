#include <iostream>
#include <string>
using namespace std;


string makeWord( string &str, int check[] ){
	string tmp = "";
	for( int i = 0;i < str.length(); ++ i )
		if( check[i] )
			tmp += str[i];
	return tmp;
}

int main ()
{
	string str;
	cin >> str;
	int check[ str.length() ];
	for( int i = 0; i < str.length(); ++ i )
		check[ i ] = 0;
	int cnt = 0;
	while( cnt < str.length() ){
		string best;
		int where = -1;
		for( int i = 0; i < str.length(); ++ i )
			if( !check[i] )
			{
				check[i] = 1;
				string tmp = makeWord(str,check);
				if( where == -1 || best > tmp )
					best = tmp, where = i;
				check[i] = 0;
			}
		cnt++;
		check[where] = 1;
		cout << best << endl;
	}
	return 0;
}
