#include <iostream>
#include <cmath>
using namespace std;


void debug ( int *nodes, int idx, int left, int right )
{
    int mid = (left+right)/2;
    cout << '<' << left << ',' << right << '/' << idx << ',' << nodes[idx] << '>' << endl;
    if( left == right ) return;
    debug( nodes, idx*2+1, left, mid );
    debug( nodes, idx*2+2, mid+1, right );
}

int min ( int a, int b )
{
    return (a>b)?b:a;
}

void update( int *nodes, int idx )
{
    while( true )
    {
        idx /= 2;
        nodes[idx] = min(nodes[idx*2+1], nodes[idx*2+2]);
        if(idx==0)
            break;
    }
}

int range( int *nodes, int idx, int left, int right, int from, int to)
{
    if( left == from && right == to )
        return nodes[idx];
    int mid = (left+right)/2;
    if( to <= mid )
        return range(nodes, idx*2+1, left, mid, from, to);
    if( mid < from )
        return range(nodes, idx*2+2, mid+1, right, from, to);
    return min(range(nodes, idx*2+2, mid+1, right, mid+1, to ), range(nodes, idx*2+1, left, mid, from, mid ));
}

int main ( void )
{
    cin.tie(NULL);

    int N;
    cin >> N;
    int LEVEL = int(ceil(log2(N))) + 1; // 1부터 시작
    int CELL_NUMBER = int(pow(2,LEVEL)) - 1;
    int LEAF_IDX = int(pow(2,LEVEL-1)) - 1;
    int nodes[ CELL_NUMBER ];
    cout << CELL_NUMBER << ',' << LEAF_IDX << endl;
    for(int i = 0; i < CELL_NUMBER; ++ i )
        nodes[i] = 1000000001;
    for(int i = 0; i < N; ++ i)
    {
        int in;
        cin >> in;
        nodes[LEAF_IDX + i] = in;
        update(nodes, LEAF_IDX+i);
    }

    debug(nodes, 0, 0, N-1);

    int M;
    cin >> M;
    for(int t = 0; t < M; ++ t)
    {
        int a, b, c;
        cin >> a >> b >> c;
        b -= 1;
        switch( a )
        {
            case 1:
                nodes[LEAF_IDX+b] = c;
                update( nodes, LEAF_IDX+b );
                break;
            case 2:
                c -= 1;
                cout << range(nodes, 0, 0, N-1, b, c ) << endl;
                break;
        }
    }
    return 0;
}