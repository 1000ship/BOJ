total = int(input())
for t in range(total):
    n, strings = map(str,input().split())
    n = int(n)
    strings = [ c * n for c in strings ]
    print("".join(strings))