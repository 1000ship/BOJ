n, m, v = map(int, input().split())
connect = [ ([False] * n) for i in range(n) ]

for i in range(m):
	a, b = map(int, input().split())
	a -= 1
	b -= 1
	connect[a][b] = connect[b][a] = True

def dfs (point, opened):
	global n, m, connect
	print( point + 1, end=" " )
	opened[ point ] = True
	for i in range(n):
		if i == point:
			continue
		if connect[point][i] and not opened[ i ]:
			dfs(i, opened)

def bfs (point):
	global n, m, connect
	stack = [point]
	opened = [ False ] * n
	opened[point] = True
	while stack:
		item = stack.pop(0)
		print( item + 1, end=" " )
		for i in range(n):
			if i == item:
				continue
			if connect[item][i] and not opened[ i ]:
				stack += [i]
				opened[ i ] = True

dfs( v-1, [ False ] * n )
print()
bfs( v-1 )
