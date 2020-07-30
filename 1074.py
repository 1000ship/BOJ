N, r, c = map(int, input().split())
size = 2 << N
count = 0

while size > 1:
    size //= 2
    if size > r and size > c:
        pass
    elif size > r and size <= c:
        count += size ** 2
        c -= size
    elif size <= r and size > c:
        count += size ** 2 * 2
        r -= size
    elif size <= r and size <= c:
        count += size ** 2 * 3
        r -= size
        c -= size

print(count)
