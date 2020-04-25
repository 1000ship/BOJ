t = int(input())
lst = [ [0 for i in range(t)] for i in range(t) ]

def func (x,y,level):
    if level < 0:
        lst[y][x] = 1
    else:
        for i in range(3):
            for j in range(3):
                if i != 1 or j != 1:
                    func(x+j*pow(3,level),y+i*pow(3,level), level-1)

cnt = -1
while t != 1:
    t /= 3
    cnt += 1
func(0,0,cnt)

for arr in lst:
    for ele in arr:
        if ele:
            print("*",end="")
        else:
            print(" ", end="")
    print()