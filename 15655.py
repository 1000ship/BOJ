n, m = map(int, input().split())
sub = list(map(int, input().split()))
sub.sort()

def recursion( arr, start ):
    global n, m
    if len(arr) < m:
        for i in range(start, n+1):
            if i not in arr:
                recursion( arr+[i], i+1 )
    else:
        print( " ".join(map(lambda x: str(sub[x-1]), arr)) )

recursion( [], 1 )