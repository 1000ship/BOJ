N,M = map(int, input().split())
lst = list(map(int, input().split()))

class request (object):
    def __init__(self, w, ww, s):
        self.who = w
        self.what = ww
        self.state = s

table = []
student = []
for i in range(M):
    table.append([])
    student.append([])

def jup ():
    for i in range(N):
        wanted = map(int, input().split())
        for w in wanted:
            if w == -1:
                continue
            req = request(i, w, 0)
            table[w-1].append(req)
            student[i].append(req)

def check ():
    for i in range(M):
        if len(table[i]) <= lst[i]:
            for req in table[i]:
                req.state = 1

for i in range(2):
    jup()
    check()

for i in range(N):
    tmp = [req.what for req in student[i] if req.state==1]
    if len(tmp) == 0:
        print("망했어요")
    else:
        tmp.sort()
        print(" ".join(map(str,tmp)))