# input N, M
N, M = map(int, input().split())

# input N rows, M columns string
# each row is string array
# each column is a string
place = []
for i in range(N):
  place.append(input())

# Range of x is 0 ~ M-1
# Range of y is 0 ~ N-1
# rectangle is ((top_left_x, top_left_y), (bottom_right_x, bottom_right_y))
# Find all of rectangles
rectangles = []
for x in range(M):
  for y in range(N):
    for size in range(0, min(M-x, N-y)):
      # Check x is 0~M-1, y is 0~N-1
      if x + size >= M or y + size >= N:
        break
      rectangles.append(((x, y), (x+size, y+size)))

def get_size_of_rectangle(rectangle):
  (top_left_x, top_left_y), (bottom_right_x, bottom_right_y) = rectangle
  return (bottom_right_x - top_left_x + 1) * (bottom_right_y - top_left_y + 1)

# Filter rectangles
# rectangle is ((top_left_x, top_left_y), (bottom_right_x, bottom_right_y))
# 1. Find value of top_left in place
# 2. Find value of bottom_right in place
# 3. Find value of top_right in place
# 4. Find value of bottom_left in place
# 5. If all of these values are same, then it is a valid rectangle
max_size = 0
for rectangle in rectangles:
  top_left_x, top_left_y = rectangle[0]
  bottom_right_x, bottom_right_y = rectangle[1]
  top_right_x, top_right_y = bottom_right_x, top_left_y
  bottom_left_x, bottom_left_y = top_left_x, bottom_right_y
  top_left = place[top_left_y][top_left_x]
  top_right = place[top_right_y][top_right_x]
  bottom_right = place[bottom_right_y][bottom_right_x]
  bottom_left = place[bottom_left_y][bottom_left_x]
  if top_left == top_right == bottom_right == bottom_left:
    size = get_size_of_rectangle(rectangle)
    if size > max_size:
      max_size = size

print(max_size)
