left = "qwertyasdfgzxcvb"
left = "{}{}".format(left, left.upper())
str = input()
cnt = 0
l=0
r=0
for c in str:
    if c==" ":
       cnt += 1
    else:
        if c.isupper():
            cnt += 1
        if c in left:
            l += 1
        else:
            r += 1

if l > r:
    if cnt >= l-r:
        cnt -= l-r
        r = l
    else:
        r += cnt
        cnt = 0
else:
    if cnt >= r-l:
        cnt -= r-l
        l += r-l
    else:
        l += cnt
        cnt = 0
if cnt > 0:
    l += int(cnt/2)
    r += int(cnt/2)
    if cnt % 2 == 1:
        l += 1;
print(l, r)