#include <stdio.h>

// 타일 코드 레이어, 낮은 레이어 값을 지닌 인근 타일을 삼킬 수 있다.
// 예를 들어 PET과 WATER 모두 ROAD로 확장할 수 있고,
// WATER는 PET으로 정해진 타일조차 삼킬 수 있다.
#define ROAD 0  // 아무 것도 없는 길
#define PET 1   // 고슴도치, 확장하게 되며 최단거리를 찾기 위해 물처럼 사방으로 퍼진다.
#define WATER 2 // 물, 확장하게 되며 고슴도치의 이동경로와 길을 삼켜버린다.
#define STONE 3 // 돌, 제자리에 있으나 삼켜지지 않음
#define EXIT 4  // 출구, 제자리에 있으며 삼켜지지 않고, PET이 주변에 다가오길 기다림.

// 2차원 배열 arr[~~][2] 사용 시, 두 번째 인덱스는 행, 열을 의미하는데,
// 0과 1로 표현하기에 헷갈릴까봐 ROW, COL로 이름을 붙이게 했다.
#define ROW 0
#define COL 1

// R, C는 전체 맵 크기, map 배열은 각 타일마다 레이어 값을 지니며, day는 이동거리
// endR, endC는 출구의 행, 열 값
int R, C, map[ 50 ][ 50 ] = { 0 }, day = 0;
int endR, endC;

// r, c의 위치 주변에 what 타일이 있는지 확인한다.
// 출구 주변에 PET이 다가왔는지 체크하기 위함.
int aroundCheck ( int r, int c, int what )
{
    if( c > 0 && map[r][c-1] == what ) return 1;
    if( c < C - 1 && map[r][c+1] == what ) return 1;
    if( r > 0 && map[r-1][c] == what ) return 1;
    if( r < R - 1 && map[r+1][c] == what ) return 1;
    return 0;
}

// r, c의 위치에서 level 값보다 낮은 레이어 값을 지닌 타일을 삼켜버린다.
// 삼켜진 타일은 매개변수로 받은 stack 배열에 쌓는다. ( cnt는 배열의 크기 )
void expand ( int r, int c, int stack[][2], int* cnt, int level )
{
    if( c > 0 && map[r][c-1] < level )
        map[r][c-1] = level, stack[*cnt][ROW] = r, stack[*cnt][COL] = c-1, (*cnt)++;
    if( c < C - 1 && map[r][c+1] < level )
        map[r][c+1] = level, stack[*cnt][ROW] = r, stack[*cnt][COL] = c+1, (*cnt)++;
    if( r > 0 && map[r-1][c] < level )
        map[r-1][c] = level, stack[*cnt][ROW] = r-1, stack[*cnt][COL] = c, (*cnt)++;
    if( r < R - 1 && map[r+1][c] < level )
        map[r+1][c] = level, stack[*cnt][ROW] = r+1, stack[*cnt][COL] = c, (*cnt)++;
}

// 재귀호출이 일어나는 계산. 매 회마다 1턴의 동작을 실행한다.
// 확장이 일어날 물과 펫의 이동경로의 배열과 그 크기를 매개변수로 받는다.
void calculate ( int waterArr[][2], int waterLength, int petArr[][2], int petLength )
{
    day++; // 1턴 증가
    
    // 출구 주변에 고슴도치가 있다면 종료.
    if( aroundCheck( endR, endC, PET ) )
        return;
    
    // 다음 calculate 실행 시, 보내줄 물 위치와 펫의 위치들을 담을 배열을 만든다.
    // 크기는 각각 ~~Length * 4인데, 모든 타일이 최대한 확장될 수 있는 방향은
    // 상,하,좌,우로 총 4곳이기에 가능한 최대의 배열 크기로 잡아주었다.
    int stackWater[ waterLength * 4 ][ 2 ], cntWater = 0;
    int stackPet[ petLength * 4 ][ 2 ], cntPet = 0;
    
    // 물 타일을 하나씩 확장시켜준다.
    for( int i = 0; i < waterLength; ++ i )
        expand( waterArr[i][ROW], waterArr[i][COL], stackWater, &cntWater, WATER );
        
    // 고슴도치 타일을 하나씩 확장시켜준다.
    for( int i = 0; i < petLength; ++ i )
        expand( petArr[i][ROW], petArr[i][COL], stackPet, &cntPet, PET );
    
    // cntPet이 0이라면 이번 턴에서 고슴도치가 확장한 타일이 없다는 것이다.
    // 즉, 앞으로 영영 아무 곳으로 이동할 수 없다는 뜻으로 종료한다.
    if( cntPet == 0 )
        day = -1; // day가 -1인 경우, 불가능한 상황으로 KAKTUS를 출력하도록 한다.
    else
        calculate( stackWater, cntWater, stackPet, cntPet );
        // 확장할 물, 고슴도치 타일들을 보내주며 다음 턴을 실행한다.
}

int main ( void )
{
    // 확장할 물과 고슴도치 위치를 담을 배열을 생성한다.
    int stackWater[ 2500 ][ 2 ] = { 0 }, cntWater = 0;
    int stackPet[ 1 ][ 2 ] = { 0 }, cntPet = 0;
    
    // 초기 맵을 받아오기 위한 부분
    char tmp;
    scanf( "%d %d", &R, &C );
    for( int r = 0; r < R; ++ r )
    {
        for( int c = 0; c < C; ++ c )
        {
            scanf( " %c", &tmp );
            switch( tmp )
            {
                case 'D':
                    map[ r ][ c ] = EXIT;
                    endR = r, endC = c;
                    // 출구의 경우 endR, endC로 따로 위치를 저장해둔다.
                    break;
                case '*':
                    map[ r ][ c ] = WATER;
                    stackWater[ cntWater ][ ROW ] = r;
                    stackWater[ cntWater ][ COL ] = c;
                    cntWater ++;
                    break;
                case 'S':
                    map[ r ][ c ] = PET;
                    stackPet[ cntPet ][ ROW ] = r;
                    stackPet[ cntPet ][ COL ] = c;
                    cntPet ++;
                    break;
                case 'X':
                    map[ r ][ c ] = STONE;
                    break;
            }
        }
    }
    
    // 재귀 함수를 호출한다.
    calculate( stackWater, cntWater, stackPet, cntPet );
    
    // day가 -1이라면 불가능한 상황이고, 아닐 경우 출구로 도달하기까지 최단 거리 값이다.
    if( day == -1 )
        printf( "KAKTUS" );
    else
        printf( "%d", day );
        
    return 0;
}