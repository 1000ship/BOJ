class BinarySearch():
    def __init__(self, value):
        self.value = value
        self.left = self.right = self.parent = None
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
    def removeChild(self, node):
        if self.left == node:
            self.left = None
        if self.right == node:
            self.right = None
    def getIndexByValue(self, value):
        if self.value == value:
            return self.value
        elif self.value > value:
            if self.left:
                return self.left.getIndexByValue(value)
            else:
                return None
        else:
            if self.right:
                return self.right.getIndexByValue(value)
            else:
                return None
    @staticmethod
    def makeTree(arr, autoSort = False):
        if autoSort:
            arr.sort()
        root = BinarySearch( arr[(len(arr)-1)//2] )
        stack = [((len(arr)-1)//2 + 1, len(arr)-1, root.setRight(BinarySearch(None))), (0, (len(arr)-1)//2 - 1, root.setLeft(BinarySearch(None)))]
        while stack:
            begin, end, pointer = stack.pop()
            if begin > end:
                pointer.parent.removeChild(pointer)
            else:
                mid = (begin+end) // 2
                pointer.value = arr[mid]
                stack.append( (mid+1, end, pointer.setRight(BinarySearch(None))) )
                stack.append( (begin, mid-1, pointer.setLeft(BinarySearch(None))) )
        return root
    def __str__(self):
        return f"{self.left if self.left else ''}{self.value} {self.right if self.right else ''}"