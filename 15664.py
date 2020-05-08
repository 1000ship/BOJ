n, m = map(int, input().split())
sub = list(map(int, input().split()))
sub.sort()
ds = [ sub.index(i) for i in sub ]

def recursion( arr, start ):
    global n, m
    if len(arr) < m:
        before_ds = -1
        black = []
        for i in range(start, n+1):
            if i not in arr:
                if before_ds != ds[i-1] and ds[i-1] not in black:
                    recursion( arr+[i], i+1 )
                    black += [ds[i-1]]
                before_ds = ds[i-1]
    else:
        print( " ".join(map(lambda x: str(sub[x-1]), arr)) )

recursion([], 1)