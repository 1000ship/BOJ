#include <iostream>
using namespace std;

class Cow {
public:
    int x;
    int y;
    bool alive;
    Cow(){
        alive = true;
    }
    int getValue( Cow cow ){
        return (x-cow.x)*(x-cow.x) + (y-cow.y)*(y-cow.y);
    }
};

class Distance {
public:
    int who;
    int value;
};

int main()
{
    int n;
    cin >> n;
    Cow cows[ n ];
    int distance[ n ][ n ] = { 0 };
    for( int i = 0; i < n; ++ i )
    {
        int x, y;
        cin >> x >> y;
        cows[ i ].x = x;
        cows[ i ].y = y;
    }
    for( int i = 0; i < n; ++ i )
        for( int j = i + 1; j < n; ++ j )
            distance[i][j] = distance[j][i] = cows[i].getValue(cows[j]);
    
    int remain = n;
    int turn = -1;
    while( remain > 1 )
    {
        turn += 1;
        if( turn == n ) turn = 0;
        if( !cows[turn].alive ) continue;
        
        int target;
        int min = 15000 * 15000 * 2 + 1;
        for( int i = 0; i < n; ++ i )
            if( turn == i ) continue;
            else if( cows[i].alive && min > distance[turn][i] )
                min = distance[turn][i], target = i;
        cows[target].alive = false;
        remain -= 1;
    }
    if( turn == -1 ) turn = 0;
    cout << turn+1;
    
    return 0;
}