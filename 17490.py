N, M, K = map(int, input().split())
cost = list(map(int, input().split()))
cut = {}
min = [0]

# M가지 공사 정보를 받는다 (최대 1,000,000)
for m in range(M):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    if a > b:
        a, b = b, a
    if a == 0 and b == N-1:
        cut[b] = 1
    else:
        cut[a] = 1

# 각 묶음을 모아 최소값을 구한다 (1,000,000)
idx = 0
for i in range(0,N):
    if min[idx] == 0 or min[idx] > cost[i]:
        min[idx] = cost[i]
    if i in cut:
        min.append(0)
        idx += 1
if N-1 not in cut:
    if min[idx] < min[0]:
        min[0] = min[idx]
    min[idx] = 0
    idx -= 1
idx += 1

total = sum(min)

if K >= total or idx == 1:
    print("YES")
else:
    print("NO")
