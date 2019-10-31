#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main ( void )
{
    string str;
    cin >> str;

    stack<char> hong;
    stack<char> ik;
    
    for( int i = 0; i < str.length(); ++ i )
        hong.push(str[i]);
    
    int num;
    cin >> num;
    for(int i = 0; i < num; ++ i)
    {
        char cmd;
        scanf(" %c", &cmd);
        switch( cmd )
        {
            case 'L':
                if( !hong.empty() )
                {
                    ik.push(hong.top());
                    hong.pop();
                }
                break;
            case 'D':
                if( !ik.empty() )
                {
                    hong.push(ik.top());
                    ik.pop();
                }
                break;
            case 'P':
                scanf(" %c", &cmd);
                hong.push(cmd);
                break;
            case 'B':
                if( !hong.empty() )
                    hong.pop();
                break;
        }
    }

    while( !hong.empty() )
    {
        ik.push(hong.top());
        hong.pop();
    }
    while( !ik.empty() )
    {
        printf("%c", ik.top());
        ik.pop();
    }
    return 0;
}