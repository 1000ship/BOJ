hwSet = { i for i in range(1,31) }
submitSet = set()
for i in range(28):
    n = int(input())
    submitSet.add(n)
lateSet = hwSet.difference(submitSet)
print( min(lateSet) )
print( max(lateSet) )
