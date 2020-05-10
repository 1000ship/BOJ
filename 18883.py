n, m = map(int, input().split())
arr = [ str(i) for i in range(1, n*m + 1) ]
for i in range( 0, n*m, m ):
    print(" ".join(arr[i:i+m]) )