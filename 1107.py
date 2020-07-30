N = int(input())
M = int(input())
if M != 0:
    blocked = list(map(int, input().split()))
else:
    blocked = []


def isInclude(target, what):
    if target == 0 and what == 0:
        return True
    while target > 0:
        if what == target % 10:
            return True
        else:
            target //= 10
    return False


NOW = 100
minClick = int(abs(N-NOW))
for i in range(0, 999901):
    ideal = int(abs(N - i)) + len(str(i))
    if ideal >= minClick:
        continue
    for button in blocked:
        if isInclude(i, button):
            break
    else:
        minClick = ideal

print(minClick)
