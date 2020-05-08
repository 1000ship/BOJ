n, m = map(int, input().split())

def recursion( arr, start ):
    global n, m
    if len(arr) < m:
        for i in range(start, n+1):
            if i not in arr:
                recursion( arr+[i], i+1 )
    else:
        print( " ".join(map(str,arr)) )

recursion( [], 1 )