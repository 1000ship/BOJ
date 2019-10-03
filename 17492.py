N = int(input())
EMPTY = 0
WALL = 1
EGG = 2

class EggDict (dict):
    global EMPTY, WALL, EGG, N
    def getEgg (self, x, y):
        if N*x+y in self:
            return self[N*x + y]
        print('sibal')
    def popEgg (self, x, y):
        self.pop(N*x + y)
    def setEgg (self, x,y, egg):
        self[N*x+y] = egg
        egg.x = x;
        egg.y = y;
    def moveEgg(self, x, y, dx, dy):
        tmp = self.getEgg(x+dx, y+dy)
        self.setEgg(x+dx*2, y+dy*2, self.getEgg(x,y))
        self.popEgg(x,y)
        self.popEgg(x+dx, y+dy)
        return tmp
    def recoverEgg(self, x, y, dx, dy, tmp):
        self.setEgg(x, y, self.getEgg(x + dx * 2, y + dy * 2))
        self.setEgg(x + dx, y + dy, tmp)
        self.popEgg(x + dx * 2, y + dy * 2)

class Egg ():
    global EMPTY, WALL, EGG
    def __init__(self, x, y):
        self.x = x;
        self.y = y;
    def cando (self, cells):
        lst = []
        # 할 수 있는 동작 출력 (x,y,dx,dy)
        # x,y가 dx,dy로 이동 가능
        for dx in [-1, 0, 1]:
            for dy in [-1, 0, 1]:
                if dx == 0 and dy == 0:
                    continue
                if self._move( cells, dx, dy ):
                    lst.append( (self.x, self.y, dx, dy) )
        return lst
    def _move (self, cells, dx, dy ):
        try:
            if cells[self.x+dx][self.y+dy] == EGG and cells[self.x+dx*2][self.y+dy*2] == EMPTY:
                return True
        except Exception:
            return False


cells = []
eggs = EggDict()

for n in range(N):
    cells += [list(map(int, input().split()))]
for i, row in enumerate(cells):
    for j, item in enumerate(row):
        if item == EGG:
            eggs.setEgg( i, j, Egg(i, j) )

isPossible = False

def rec ():
    global isPossible, cells, eggs
    if isPossible:
        return;

    canDoList = []
    for idx in eggs:
        egg = eggs[idx]
        canDoList += egg.cando(cells)
    for x, y, dx, dy in canDoList:
        # 시도하고
        tmp = eggs.moveEgg(x,y,dx,dy)
        cells[x][y] = EMPTY
        cells[x+dx][y+dy] = EMPTY
        cells[x+dx*2][y+dy*2] = EGG
        # 재귀호출
        rec()
        # 복구하고
        eggs.recoverEgg(x,y,dx,dy,tmp)
        cells[x][y] = EGG
        cells[x+dx][y+dy] = EGG
        cells[x+dx*2][y+dy*2] = EMPTY
    for i, idx in enumerate(eggs):
        if i != 0:
            break
    else:
        isPossible = True

def render ():
    for row in cells:
        for item in row:
            print(item, end=" ")
        print()
    print(eggs)

rec()

if isPossible:
    print("Possible")
else:
    print("Impossible")