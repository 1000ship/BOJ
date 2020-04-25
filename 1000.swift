let str = readLine()!
var sum = 0
let arr = str.split(separator: " ")
for i in arr {
	sum += Int(i)!
}
print(sum)
