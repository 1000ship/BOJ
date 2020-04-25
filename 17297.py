import math
lst = [6,14]

i = 2
tmp = 0
while tmp < math.pow(2,30):
    tmp = lst[i - 1] + lst[i - 2]
    lst.append(tmp)
    i += 1

i -= 1
m = int(input())
while i > 1:
    if lst[i-1] < m:
        m -= lst[i-1]
        i -= 2
    else:
        i -= 1

str = "Messi Gimossi "
def result (c):
    if c == " ":
        return "Messi Messi Gimossi"
    return c

print( result(str[m-1]) )