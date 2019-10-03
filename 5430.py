T = int(input())
for t in range(T):
    str = input()
    N = int(input())
    arr = input()[1:-1].split(",")
    if not N:
        arr = []
    isFront = True
    front = 0
    back = 0
    for c in str:
        if c=='R':
            isFront = not isFront
        else:
            if isFront:
                front += 1
            else:
                back += 1
    if front + back <= len(arr):
        arr = arr[front:len(arr)-back]
        if not isFront:
            arr.reverse()
        print("[{}]".format(",".join(arr)))
    else:
        print("error")