n, m = map(int, input().split())

start = (0,0)
maps = []
res = [[-1]*m for iter in range(n)]
for i in range( n ):
    maps.append( list(map(int,input().split())) )
    for idx, item in enumerate(maps[i]):
        if item == 2:
            start = (i, idx)
        elif item == 0:
            res[i][idx] = 0


def print_res():
    global res
    for line in res:
        for item in line:
            print( item, end=" " )
        print()

current_stack = [start]
step = 0
while current_stack:
    new_stack = []
    checker = [[False]*m for iter in range(n)]
    for x, y in current_stack:
        if maps[x][y] > 0:
            res[x][y] = step
            for dx, dy in [(1,0),(-1,0),(0,1),(0,-1)]:
                tox = x+dx
                toy = y+dy
                if tox < 0 or tox >= n or toy < 0 or toy >= m or checker[tox][toy]:
                    pass
                elif res[tox][toy] == -1:
                    new_stack.append( (tox, toy) )
                    checker[tox][toy] = True
        else:
            res[x][y] = 0
    step += 1
    current_stack = new_stack
print_res()
