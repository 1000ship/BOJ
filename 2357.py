import sys

class Node (object):
	def __repr__ ( self ):
		return "({})".format(self.value)
	def __init__( self ):
		self.left = None
		self.right = None
		self.parent = None
		self.start = 0
		self.end = 0
		self.mid = 0
		self.min = 0
		self.max = 0
	def calc (self, chaining=True):
		if self.left:
			self.min = min(self.left.min, self.right.min)
			self.max = max(self.left.max, self.right.max)
		if self.parent and chaining:
			self.parent.calc()
			
def makeTree (left, right, parent):
	global arr, top
	
	if parent == None:
		parent = Node()
	mid = (left+right) // 2
	parent.start = left; parent.end = right; parent.mid = mid
	
	if left == right:
		parent.min = parent.max = arr[left]
		nodes[left] = parent
		return
	
	parent.left = Node()
	parent.right = Node()
	parent.left.parent = parent
	parent.right.parent = parent
	makeTree(left, mid, parent.left)
	makeTree(mid+1, right, parent.right)
	parent.calc(False)
	return parent

N, M = map(int,sys.stdin.readline().split())
arr = []
for n in range(N):
	arr.append( int(sys.stdin.readline()) )
nodes = [None] * N
top = makeTree(0, N-1, None)

def setValue (idx, value):
	nodes[idx].min = nodes[idx].max = value
	nodes[idx].calc()

def getValue (start, end, parent):
	if start == parent.start and end == parent.end:
		return (parent.min, parent.max)
	if end <= parent.mid:
		return getValue(start, end, parent.left)
	if start > parent.mid:
		return getValue(start, end, parent.right)
	aMin, aMax = getValue(start, parent.mid, parent.left)
	bMin, bMax = getValue(parent.mid+1, end, parent.right)
	return (min(aMin, bMin), max(aMax, bMax))

for m in range(M):
	in1, in2 = map(int, sys.stdin.readline().split())
	a, b = getValue( in1-1, in2-1, top )
	print(a,b)
