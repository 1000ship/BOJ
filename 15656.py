n, m = map(int, input().split())
sub = list(map(int, input().split()))
sub.sort()

def recursion( arr ):
    global n, m
    if len(arr) < m:
        for i in range(1, n+1):
            recursion( arr+[i] )
    else:
        print( " ".join(map(lambda x: str(sub[x-1]), arr)) )

recursion( [] )