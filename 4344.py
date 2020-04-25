t = int(input())
for i in range(t):
    lst = list(map(int,input().split()))
    lst.pop(0)
    avg = sum(lst)/len(lst)
    cnt = len( [a for a in lst if a > avg])
    print("{:.3f}%".format(cnt/len(lst)*100))
