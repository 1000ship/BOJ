class Class:
    def __init__(self, begin, end):
        self.id = 0
        self.begin = begin
        self.end = end
    def collisionCheck ( self, c ):
        if self.end <= c.begin or c.end <= self.begin:
            return False
        return True
    def __repr__(self):
        return f"{self.id}"

n = int(input())
classes = [ Class(*map(int, input().split())) for i in range(n) ]
classes.sort(key= lambda x: x.begin)

max_cnt = -1
max_arr = []
arr = [ classes[0] ]
for i in range( 1, len( classes ) ):
    target = classes[i]
    if target.end < arr[-1].end:
        arr[-1] = target
    elif arr[-1].end <= target.begin:
        arr += [target]
print( len(arr) )
#print( arr )
