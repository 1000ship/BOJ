n = int(input())

edges = []
owner = [ item for item in range(n) ]
sum = 0
cnt = 0

class Edge ( object ):
    def __init__(self, start, end, value ):
        if start < end:
            self.start = start
            self.end = end
        else:
            self.start = end
            self.end = start
        self.value = value
    def __repr__(self):
        return str(self.value)

for i in range(n):
    tmp = list(map(int,input().split()))
    for j in range(i+1, n):
        edges.append(Edge(i, j, tmp[j]))
edges.sort(key=lambda x: x.value)

for e in edges:
    start = e.start
    end = e.end
    start_owner = owner[start]
    while start_owner != owner[start_owner]:
        start_owner = owner[start_owner]
    end_owner = owner[end]
    while end_owner != owner[end_owner]:
        end_owner = owner[end_owner]
    if start_owner == end_owner:
        continue
    if start_owner > end_owner:
        owner[start_owner] = end_owner
    else:
        owner[end_owner] = start_owner
    cnt += 1
    sum += e.value
    if cnt == n-1:
        break

print( sum )
