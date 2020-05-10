while True:
    arr = list(map(int,input().split()))
    n = arr[0]
    arr = arr[1:]
    if n == 0:
        break
    for i, item in enumerate(arr):
        if i == 0 or (i > 0 and arr[i-1] != arr[i]):
            print(item, end=" ")
    print("$")


