# just using my library
class Segment ():
    def __init__(self, value):
        self.value = value
        self.left = self.right = self.parent = None
        self.begin = self.end = None
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
    def getNodeByIndex(self, index):
        if self.begin == self.end == index:
            return self
        if self.left.begin <= index <= self.left.end:
            return self.left.getNodeByIndex(index)
        elif self.right.begin <= index <= self.right.end:
            return self.right.getNodeByIndex(index)
    def getTreesInRange(self, begin, end):
        trees = []
        if begin <= self.begin and self.end <= end:
            trees += [self]
        elif not(self.end < begin or end < self.begin):
            trees += self.left.getTreesInRange(begin, end)
            trees += self.right.getTreesInRange(begin, end)
        return trees
    def executeDown(self, begin, end, func):
        if begin <= self.begin and self.end <= end:
            func(self)
        elif not(self.end < begin or end < self.begin):
            if self.left:
                self.left.execute(begin, end, func)
            if self.right:
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
        while stack:
            begin, end, pointer = stack.pop()
            pointer.setBeginEnd( begin, end )
            if begin == end:
                pointer.setValue(arr[begin])
            else:
                mid = (begin+end) // 2
                stack.append( (mid+1, end, pointer.setRight(Segment(defaultValue))) )
                stack.append( (begin, mid, pointer.setLeft(Segment(defaultValue))) )
        return root

import sys
def input():
    return sys.stdin.readline()

import math
n = int(input())
arr = list(map(int,input().split()))
m = int(input())

root = Segment.makeTree(arr, defaultValue=math.inf)

def updateMinValue ( node ):
    if node.left and node.right:
        node.value = min(node.left.value, node.right.value)
root.executeUpFromBottom(updateMinValue)

for _m in range(m):
    op, i, j = map(int, input().split())
    i -= 1
    if op == 1:
        target = root.getNodeByIndex(i)
        target.value = j
        target.executeUp(updateMinValue)
    elif op == 2:
        j -= 1
        values = [node.value for node in root.getTreesInRange(i, j)]
        print(min(values))