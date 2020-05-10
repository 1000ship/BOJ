arr = [ tuple(map(int,input().split())) for i in range(4) ]
num = 0
max_num = 0
for out, come in arr:
    num -= out
    max_num = max(max_num, num)
    num += come
    max_num = max(max_num, num)
print( max_num )