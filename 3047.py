arr = list(map(int, input().split()))
abc = input()
arr.sort()
for c in abc:
    if c == 'A':
        print(arr[0], end=" ")
    elif c == 'B':
        print(arr[1], end=" ")
    else:
        print(arr[2], end=" ")