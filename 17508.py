N, M = map(int, input().split())
ori = []
rot = []

for n in range(N):
    ori += [list(map(int,list(input())))]
    rot += [ori[n][:]]

#n, m
#N-n-1, M-m-1

for n in range(N):
    for m in range(M):
        rot[N-n-1][M-m-1] = ori[n][m]

'''
for n in range(N):
    print(ori[n])
print()
for n in range(N):
    print(rot[n])
    '''

# 홀수개의 줄 가운데 줄은 7이 없어야한다 error
# 6과 9 이외 서로 다른 숫자가 만나면 error
# + 홀수개의 행, 열에 정 가운데에 6이나 9도 안된다

# 6과 9가 만나면 +1

cnt = 0
isError = False
if N % 2 == 1 and M % 2 == 1 and ori[int(N/2)][int(M/2)] != 8:
    isError = True

rowCnt = int((N+1)/2)
lastColCnt = int( (M+1)/2 )
#print( rowCnt, lastColCnt )

for n in range( rowCnt ):
    colCnt = M
    if N % 2 == 1 and n == rowCnt - 1:
        colCnt = lastColCnt
    for m in range(colCnt):
        a = ori[n][m]
        b = rot[n][m]
        if a==b:
            if a==7:
               cnt += 1
            if a==6 or a==9:
                cnt += 1
        else:
            if not {a,b}.difference({6,9}):
                # 6, 9 라면
                pass
            else:
                # error
                isError = True
                break

if isError:
    print(-1)
else:
    print(cnt)