n = int(input())
lst = map(float, input().split())

isfirst = True
cnt = 0
for f in lst:
    if f == 0:
        continue
    if f-float(int(f)) > 0 and isfirst:
        cnt = 1
    isfirst = False
    cnt += int(f)
print(cnt)