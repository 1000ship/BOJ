N, M = map(int,input().split())

# getChildrenNum >> 최초 1번 O(N), 재귀 10만번 가능..
class Node (object):
    def __init__ (self, id):
        self.id = id
        self.children = []
        self.childrenNum = -1
        self.order = -1
    def setOrder (self, order):
        self.order = order
    def getChildrenNum (self):
        return self.childrenNum
    def __repr__ (self):
        return "<ID: {}, ORDER:{}, children:{}>".format(self.id, self.order, self.getChildrenNum())

# +10만번 = O(N)
nodes = [Node(i) for i in range(N)]
head = nodes[0]
relation = list(map(int,input().split()))

# make tree번 = O(N)
for idx in range(len(relation)):
    item = relation[idx]
    if item == -1:
        head = nodes[idx]
        continue
    nodes[item-1].children.append(nodes[idx])

# ordering = O(N)
cnt = 0
ordering_stack = [ head ]
while ordering_stack:
    node = ordering_stack.pop()
    if node is None:
        node = ordering_stack.pop()
        node.childrenNum = cnt - node.order - 1
        continue
    node.setOrder( cnt )
    cnt += 1
    ordering_stack += [node, None]
    ordering_stack += node.children

class Segment (object):
    def __init__(self, begin, end):
        self.begin = begin
        self.end = end
        self.value = 0
        self.left = None
        self.right = None
        self.mid = -1
        self.top = None
    def __repr__(self):
        return "<Seg {}~{}, value={}>\n{} / {}".format(self.begin, self.end, self.value, self.left, self.right)

# make segments = O(log2N + N)
seg_order = [ None for i in range(N)]
seg_head = Segment( 0, N-1 )
def seg_recursion (seg):
    if seg.begin == seg.end:
        seg_order[ seg.begin ] = seg
        return
    seg.mid = (seg.begin + seg.end) // 2
    seg.left = Segment( seg.begin, seg.mid )
    seg.right = Segment( seg.mid + 1, seg.end )
    seg.left.top = seg.right.top = seg
    seg_recursion( seg.left )
    seg_recursion( seg.right )
seg_recursion( seg_head )

# 여기까지 기본세팅 50만 정도 반복했

# make add function(십만번 호출가능) = O(34)
def addValue ( seg, begin, end, value ):
    if begin <= seg.begin and seg.end <= end:
        seg.value += value
    else:
        if end <= seg.mid:
            addValue( seg.left, begin, end, value )
        elif seg.mid < begin:
            addValue( seg.right, begin, end, value)
        else:
            addValue( seg.left, begin, seg.mid, value )
            addValue( seg.right, seg.mid+1, end, value )

# define getValue(십만번 호출가능) = O(17)
def getValue ( seg ):
    result = 0
    while seg is not None:
        result += seg.value
        seg = seg.top
    return result

# main
for case_by_case in range(M):
    ins = list(map(int,input().split()))
    who = ins[1]-1
    if ins[0] == 1:
        value = ins[2]
        addValue( seg_head, nodes[who].order, nodes[who].order + nodes[who].getChildrenNum(), value )
    else:
        node_order = nodes[who].order
        segment = seg_order[ node_order ]
        print( getValue( segment ) )