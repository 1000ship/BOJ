n = int(input())

relation = []
selected = [False]*n
distance = [pow(10,8)+1]*n
sum = 0

for i in range(n):
    relation.append( list(map(int,input().split())) )

distance[0] = 0
for t in range(n):
    target = -1
    checker = pow(10,8)+1
    for i in range(n):
        if not selected[i] and checker > distance[i]:
            checker = distance[i]
            target = i
    if target == -1:
        print("graph error")
        break
    selected[target] = True
    sum += distance[target]
    for idx, dist in enumerate(relation[target]):
        distance[idx] = min(distance[idx], dist)

print( sum )

