#include <iostream>
#include <string>
using namespace std;

int main ( void )
{
    // 최대 10000자릿수
    string strA, strB;
    cin >> strA >> strB;
    
    int A[10000] = {0};
    int B[10000] = {0};
    int C[10001] = {0};
    for(int i = 0; i < strA.length(); ++ i)
        A[i] = strA[strA.length()-1-i] - '0';
    for(int i = 0; i < strB.length(); ++ i)
        B[i] = strB[strB.length()-1-i] - '0';
    for(int i = 0; i < 10000; ++i)
    {
        C[i] += A[i] + B[i];
        C[i+1] = C[i] / 10;
        C[i] %= 10;
    }

    bool isStart = false;
    for(int i = 10000; i >= 0; --i)
    {
        if( C[i] != 0 )
            isStart = true;
        if( isStart )
            cout << C[i];
    }
    return 0;
}