lst = []

for i in range(11):
    a, b = map(int, input().split())
    lst += [(a,b,a+b*20)]

lst.sort(key=lambda x:x[1])
lst.sort(key=lambda x:x[0])
#lst.sort(key=lambda x:x[2])

t = 0
score = 0

for a, b, c in lst:
    tmp = t+a+b*20
    t += a
    score += tmp

print( score )