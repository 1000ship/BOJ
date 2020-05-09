# 2268.py used
# 14438(2).py used

class Segment ():
    def __init__(self, value):
        self.value = value
        self.left = self.right = self.parent = None
        self.begin = self.end = None
        self.children = None # only root has children
    def setBeginEnd(self, begin, end):
        self.begin = begin
        self.end = end
    def setLeft(self, node):
        self.left = node
        node.setParent(self)
        return node
    def setRight(self,node):
        self.right = node
        node.setParent(self)
        return node
    def setParent(self, node):
        self.parent = node
        return node
    def setValue(self, value):
        self.value = value
    def __str__(self):
        if not self.left and not self.right:
            return f"{self.value} "
        else:
            return f"{self.left}{self.right}"
    def __repr__(self):
        return f"{self.value}"
    def getNodeByIndex(self, index):
        if self.children:
            return self.children[index]
        if self.begin == self.end == index:
            return self
        if self.left.begin <= index <= self.left.end:
            return self.left.getNodeByIndex(index)
        elif self.right.begin <= index <= self.right.end:
            return self.right.getNodeByIndex(index)
    def getTreesInRange(self, begin, end):
        if begin <= self.begin and self.end <= end:
            return [self]
        trees = []
        if not(self.left.end < begin or end < self.left.begin):
            trees += self.left.getTreesInRange(begin, end)
        if not(self.right.end < begin or end < self.right.begin):
            trees += self.right.getTreesInRange(begin, end)
        return trees
    def getHeapList(self):
        heap = []
        stackA = [self]
        stackB = []
        while stackA or stackB:
            if not stackB:
                while stackA:
                    stackB.append(stackA.pop())
            node = stackB.pop()
            heap.append(node)
            if node.left:
                stackA.append(node.left)
            if node.right:
                stackA.append(node.right)
        return heap
    def executeDown(self, begin, end, func):
        if begin <= self.begin and self.end <= end:
            func(self)
        elif not(self.end < begin or end < self.begin):
            if self.left:
                self.left.execute(begin, end, func)
            if self.right:
                self.right.execute(begin, end, func)
    def executePropagation(self, begin, end, func):
        func(self)
        if not(self.left.end < begin or self.left.begin < end):
            self.left.execute(begin, end, func)
        if not(self.right.end < begin or self.right.begin < end):
            self.right.execute(begin, end, func)
    def executeUp(self, func):
        func(self)
        if self.parent:
            self.parent.executeUp(func)
    def executeUpFromBottom(self, func):
        if self.left:
            self.left.executeUpFromBottom(func)
        if self.right:
            self.right.executeUpFromBottom(func)
        if not self.left and not self.right:
            self.executeUp(func)
    @staticmethod
    def makeTree(arr, defaultValue = None):
        root = Segment(defaultValue)
        stack = [(0, len(arr)-1, root)]
        children = []
        while stack:
            begin, end, pointer = stack.pop()
            pointer.setBeginEnd( begin, end )
            if begin == end:
                pointer.setValue(arr[begin])
                children.append(pointer)
            else:
                mid = (begin+end) // 2
                stack.append( (mid+1, end, pointer.setRight(Segment(defaultValue))) )
                stack.append( (begin, mid, pointer.setLeft(Segment(defaultValue))) )
        root.children = children
        return root

if __name__ == "__main__":
    import math
    root = Segment.makeTree([4, 5, 2, 1, 3, 0], defaultValue=math.inf)
    heap = reversed(root.getHeapList())
    for node in heap:
        if node.left and node.right:
            node.value = min(node.left.value, node.right.value)
    print( root.value )
    print( root.children )
