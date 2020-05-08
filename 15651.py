n, m = map(int, input().split())

def recursion( arr ):
    global n, m
    if len(arr) < m:
        for i in range(1, n+1):
            recursion( arr+[i] )
    else:
        print( " ".join(map(str,arr)) )

recursion( [] )