n, m = map(int, input().split())

def recursion( arr, start ):
    global n, m
    if len(arr) < m:
        for i in range(start, n+1):
            if not arr or max(arr) <= i:
                recursion( arr+[i], i )
    else:
        print( " ".join(map(str,arr)) )

recursion( [], 1 )