arr = []
for i in range(9):
    arr += list(map(int, input().split()))
max_item = max(arr)
max_idx = -1
for idx, item in enumerate(arr):
    if item == max_item:
        max_idx = idx
        break
print(max_item)
print(max_idx // 9 + 1, max_idx % 9 + 1)