T = int(input())

class Queue (list):
    def __init__(self):
        self.stack_list = []
    def push_first(self, item):
        item.isIn = True
        self.stack_list.append( item )
    def pop_back(self):
        if len( self ) == 0:
            while self.stack_list:
                self.append( self.stack_list.pop() )
        poped = self.pop()
        poped.isIn = False
        return poped
    def isEmpty(self):
        return len(self)+len(self.stack_list) == 0

class Node (object):
    def __repr__(self):
        return "Node:{}".format(self.id)
    def __init__(self, id, time):
        self.id = id
        self.time = time
        self.parents = []
        self.children = []
        self.childrenTime = 0
        self.isComplete = False
        self.isIn = False
    def calc(self):
        while self.children:
            child = self.children[-1]
            if child.isComplete:
                self.childrenTime = max(self.childrenTime, child.time)
                self.children.pop()
            else:
                break
        else:
            self.isComplete = True
            self.time += self.childrenTime
            return True
        return False


for case_number in range(T):
    N, K = map(int, input().split())
    times = list(map(int,input().split()))
    nodes = [ Node(i,time) for i, time in enumerate(times) ]
    for k in range(K):
        a, b = map(int,input().split())
        nodes[b-1].children.append( nodes[a-1] )
        nodes[a-1].parents.append( nodes[b-1] )
    goal = nodes[ int(input())-1 ]

    queue = Queue()
    for node in nodes:
        if len(node.children) == 0:
            queue.push_first( node )
    while not queue.isEmpty():
        node = queue.pop_back()
        if node.calc():
            for parent in node.parents:
                if not parent.isIn:
                    queue.push_first(parent)
            if node == goal:
                print(node.time)
                break