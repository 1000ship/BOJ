class Queue ():
    def __init__(self, initList = []):
        self._stackA = initList if initList else []
        self._stackB = []
    def isEmpty(self):
        return not self._stackA and not self._stackB
    def push(self, item):
        self._stackA.append(item)
    def pop(self):
        if self.isEmpty():
            return None
        if not self._stackB:
            while self._stackA:
                self._stackB.append(self._stackA.pop())
        return self._stackB.pop()
    def count(self):
        return len(self._stackA) + len(self._stackB)
    def __str__(self):
        while self._stackB:
            self._stackA.append(self._stackB.pop())
        return f"{self._stackA}"
    def __repr__(self):
        while self._stackB:
            self._stackA.append(self._stackB.pop())
        return self._stackA

if __name__ == "__main__":
    que = Queue([1,4,5,2,3])
    while que.count():
        print( que.pop(), que ) 