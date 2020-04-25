a, b, c = map(float, input().split())
if b >= c:
    x = -1
else:
    x = a / (c-b) + 1

print( int(x) )