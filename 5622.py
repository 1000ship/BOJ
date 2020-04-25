lst = ['ABC', 'DEF', 'GHI', 'JKL', 'MNO', 'PQRS', 'TUV', 'WXYZ' ]
def getTime( cha ):
    for i in range(len(lst)):
        if cha in lst[i]:
            return i+3
    return 0
cnt = 0
for i in input():
    cnt += getTime(i)
print(cnt)
