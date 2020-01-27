class Word ():
	def __init__ (self, word):
		self.dict = {}
		self.origin = word
		for c in word:
			if c not in self.dict:
				self.dict[c] = 0
			self.dict[c] += 1
		self.length = len(word)
	def cost (self, word):
		cnt = 0
		tmpDict = self.dict.copy()
		if len(word) != self.length:
			return -1
		for i, c in enumerate(word):
			if c not in tmpDict:
				return -1
			tmpDict[c] -= 1
			if self.origin[i] != c:
				cnt += 1
			if tmpDict[c] < 0:
				return -1
		return cnt

str = input()
n = int(input())
arr = []
for i in range(n):
	arr += [Word(input())]

dp = [0] + [-1]*len(str) # x 번째까지 들었던 비용

def calc(current):
	global dp, str
	for word in arr:
		index = current + word.length
		cost = word.cost(str[current:current+word.length])
		if cost == -1:
			continue
		if dp[index] == -1 or dp[index] > cost + dp[current]:
			dp[index] = dp[current] + cost
			calc(index)

calc(0)
print( dp[len(str)] )
