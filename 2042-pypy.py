import sys

class Node (object):
	def __repr__ ( self ):
		return "({})".format(self.value)
	def __init__( self ):
		self.left = None
		self.right = None
		self.parent = None
		self.value = 0
		self.start = 0
		self.end = 0
		self.mid = 0
		
	def calc (self, chaining=True):
		if self.left:
			self.value = self.left.value + self.right.value
		if self.parent and chaining:
			self.parent.calc()
			
def makeTree (left, right, parent):
	global arr, top
	
	if parent == None:
		parent = Node()
	mid = (left+right) // 2
	parent.start = left; parent.end = right; parent.mid = mid
	
	if left == right:
		parent.value = arr[left]
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

N, M, K = map(int,sys.stdin.readline().split())
arr = []
for n in range(N):
	arr.append( int(sys.stdin.readline()) )
nodes = [None] * N
top = makeTree(0, N-1, None)

def setValue (idx, value):
	nodes[idx].value = value
	nodes[idx].calc()

def getValue (start, end, parent):
	if start == parent.start and end == parent.end:
		return parent.value	
	if end <= parent.mid:
		return getValue(start, end, parent.left)
	if start > parent.mid:
		return getValue(start, end, parent.right)
	return getValue(start, parent.mid, parent.left) + getValue(parent.mid+1, end, parent.right)

for m in range(M+K):
	in1, in2, in3 = map(int, sys.stdin.readline().split())
	if in1 == 1:
		setValue( in2-1, in3 )
	else:
		print( getValue( in2-1, in3-1, top ) )
