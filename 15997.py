teamName = input().strip().split()

WIN = 0
DRAW = 1
LOSE = 2

p = [ [ None for i in range(4) ] for i in range(4) ]
for i in range(6):
    first, second, win, draw, lose = tuple(input().strip().split())
    win, draw, lose = map(float, (win,draw,lose))
    firstIdx = teamName.index(first)
    secondIdx = teamName.index(second)
    p[firstIdx][secondIdx] = [win, draw, lose]
    p[secondIdx][firstIdx] = [lose, draw, win]

match = [(0,1), (0,2), (0,3), (1,2), (1,3), (2,3)]
final_pr = [0,0,0,0]

def bf ( results ):
    global WIN, DRAW, LOSE, final_pr
    if len(results) < 6:
        # 모든 경우의 수
        bf( results + [WIN] )
        bf( results + [DRAW] )
        bf( results + [LOSE] )
    else:
        pr = 1
        score = [ [i, 0] for i in range(4) ]
        # 본 경우의 확률을 구한다.
        for idx, item in enumerate(results):
            first, second = match[idx]
            pr *= p[first][second][item]
            if item == WIN:
                score[first][1] += 3
            elif item == DRAW:
                score[first][1] += 1
                score[second][1] += 1
            else:
                score[second][1] += 3
        score.sort(key=lambda x: x[1], reverse=True)
        first_pr = [0, 0, 0, 0] # 1등할 확률
        second_pr = [0, 0, 0, 0] # 2등할 확률
        only_score = [ j for i, j in score ];
        first_cnt = only_score.count( score[0][1] ) # 공동 1등 세기
        for i in range(first_cnt):
            first_pr[ score[i][0] ] += 1 / first_cnt
        second_cnt = only_score.count( score[1][1] ) # 공동 2등 세기
        for i in range(second_cnt):
            bias = only_score.index( score[1][1] )
            second_pr[ score[i+bias][0] ] += 1 / second_cnt 
        for i in range(4):
            final_pr[i] += pr * (first_pr[i] + second_pr[i])

bf([])
for i in final_pr:
    print(i)