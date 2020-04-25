t = int(input())
cnt = 0
for i in range(t):
    str = input()
    s = set()
    prev = 'a'
    for cha in str:
        if cha not in s:
            s.add(cha)
            prev = cha
        elif prev == cha:
            pass
        else:
            break
    else:
        cnt += 1
print(cnt)