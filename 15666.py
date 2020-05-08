n, m = map(int, input().split())
sub = list(map(int, input().split()))
sub = list(set(sub))
sub.sort()
n = len(sub)

def recursion( arr, start ):
    global n, m
    if len(arr) < m:
        for i in range(start, n+1):
                recursion( arr+[i], i )
    else:
        print( " ".join(map(lambda x: str(sub[x-1]), arr)) )

recursion([], 1)