import re

string = input()
arr = re.findall("\d+|[+-]", string)
for i, el in enumerate(arr):
  if i % 2 == 0:
    arr[i] = int(el)

newArr = [0]
for el in arr:
  if type(el) == int:
      newArr[-1] += el
  elif el == "-":
    newArr.append(0)

result = newArr[0] * 2
result -= sum(newArr)
print( result )
