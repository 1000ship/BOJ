import sys

class Flag (object):
    def __init__(self, id, x, y):
        self.id = id
        self.x = x
        self.y = y
        self.parent = self
    def getMaster(self):
        if self.parent == self:
            return self
        self.parent = self.parent.getMaster()
        return self.parent
    def combine(self, who):
        if who.getMaster().id < self.getMaster().id:
            self.getMaster().parent = who.getMaster()
            # print(">>", self, who)
        elif who.getMaster().id > self.getMaster().id:
            who.getMaster().parent = self.getMaster()
            # print( ">>", self, who )
    def isCombined(self, who):
        return who.getMaster().id == self.getMaster().id
    def __repr__(self):
        return "({}, {})".format(self.x, self.y)

class Query (object):
    def __init__(self, id, before, after, hp):
        self.id = id
        self.before = before
        self.after = after
        self.hp = hp
        self.answer = False
    def __repr__(self):
        return "({}->{}, {} => {})".format(self.before, self.after, self.hp, self.answer)

class Relation (object):
    def __init__(self, before, after, cost):
        self.before = before
        self.after = after
        self.cost = cost
    def __repr__(self):
        return "[{} to {}, {}]".format(self.before, self.after, self.cost)

N, Q = map(int, sys.stdin.readline().strip().split())
flags = []
for n in range(N):
    x, y = map(int, sys.stdin.readline().strip().split())
    flags.append( Flag( n, x, y ) )
querys = []
for q in range(Q):
    before, after, hp = map(int, sys.stdin.readline().strip().split())
    before -= 1
    after -= 1
    querys.append( Query( q, flags[before], flags[after], hp ) )
querys.sort(key=lambda q: q.hp)

# print( flags )
# print( querys )

relations = []
flags.sort(key=lambda f: f.x)
for i in range(N-1):
    relations.append( Relation(flags[i], flags[i+1], flags[i+1].x - flags[i].x) )
flags.sort(key=lambda f: f.y)
for i in range(N-1):
    relations.append( Relation(flags[i], flags[i+1], flags[i+1].y - flags[i].y) )
relations.sort(key=lambda r: r.cost, reverse=True)

currentCost = 0
# print(relations)

for q in range(Q):
    currentCost = querys[q].hp;
    while relations and relations[-1].cost <= currentCost:
        rel = relations.pop()
        rel.before.combine( rel.after )
    querys[q].answer = querys[q].before.isCombined( querys[q].after )

result = [ False for i in range(Q) ]
for q in querys:
    result[q.id] = q.answer
# print( querys )
for b in result:
    if b:
        sys.stdout.writelines("YES\n")
    else:
        sys.stdout.writelines("NO\n")