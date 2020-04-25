l = []
max = -1
for i in range(9):
    l.append(int(input()))
    if l[i] > max:
        max = l[i]
print(max, l.index(max)+1)
