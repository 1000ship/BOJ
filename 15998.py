import sys

n = int(sys.stdin.readline())
money = 0

charges = []
remains = []
isError = False

for case in range(n):
    bias, remain = map(int, sys.stdin.readline().split())
    if bias == 0:
        continue
    if money + bias < 0:
        charges += [remain - bias - money]
        remains += [remain]
    elif money + bias != remain:
        isError = True
        break
    money = remain

if remains:
    max_remain = max(remains)
else:
    max_remain = -1

def gcd ( a, b ):
    large = max(a,b)
    small = min(a,b)
    while True:
        if large % small == 0:
            return small
        else:
            large, small = small, large % small
while len(charges) > 1:
    first, second = charges.pop(), charges.pop()
    charges.append( gcd(first, second) )
if charges:
    total_gcd = charges[0]
else:
    total_gcd = 1

if total_gcd <= max_remain or isError:
    print(-1)
else:
    print(total_gcd)