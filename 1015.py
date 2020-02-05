class Item ():
	def __init__ (self, number):
		self.number = number
		self.order = 0
	def __str__(self):
		return "{}".format(self.order)
n = int(input())
arr = map(int, input().split())
arr = [Item(i) for i in arr]
arr2 = sorted(arr, key=lambda x: x.number)
for index, item in enumerate(arr2):
	item.order = index
arr = map(str, arr)
print(" ".join(arr))
