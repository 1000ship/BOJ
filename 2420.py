a, b = map(int, input().split())
n = a - b
if n < 0:
    n *= -1
print( n )