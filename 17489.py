N, M, L = map(int, input().split())
clue = input()
map = []
for n in range(N):
    map += [ input() ]
K = 0
dest = (-1,0)

def news (x,y):
    result = []
    pos = (x,y)
    if pos[0] < N-1:
        result += [(pos[0]+1, pos[1], map[pos[0]+1][pos[1]])]
    if pos[1] < M-1:
        result += [(pos[0], pos[1]+1, map[pos[0]][pos[1]+1])]
    if pos[0] > 0:
        result += [(pos[0]-1, pos[1], map[pos[0]-1][pos[1]])]
    if pos[1] > 0:
        result += [(pos[0], pos[1]-1, map[pos[0]][pos[1]-1])]
    return result

def debug (x,y):
    global N,M
    for i in range(N):
        for j in range(M):
            if x==i and y==j:
                print("1",end="")
            else:
                print("0",end="")
        print()
    print()

def loop (current_x, current_y, idx, k, history ):
    global map, clue, N, M, L, K, dest
    if K < 0:
        return
    history = history[:]

    #print(current_x, current_y, idx, k, history)
    #debug(current_x, current_y)

    if idx >= L:
        idx = 0
        k += 1
        current_pos = (current_x, current_y)
        if K < k:
            K = k
            dest = current_pos
        if current_pos not in history:
            history += [current_pos]
        else:
            K = -1
            return

    for x, y, w in news(current_x, current_y):
        if w == clue[idx]:
            loop(x,y,idx+1,k,history)


loop(0,0,1,0,[])

if K > 0:
    print(K)
    print(dest[0]+1, dest[1]+1)
else:
    print(-1)