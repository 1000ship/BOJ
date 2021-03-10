import sys
input = lambda: sys.stdin.readline().strip()
print = lambda x: sys.stdout.write(f"{x}\n")

N, M = map(int, input().split())
arr = [ input() for _ in range(N) ]
nameToIndex = { name: index+1 for index, name in enumerate( arr ) }
indexToName = { index+1: name for index, name in enumerate( arr ) }

queries = [input() for _ in range(M) ]
for query in queries:
  if query.isdigit():
    print(indexToName[int(query)])
  else:
    print(nameToIndex[query])
