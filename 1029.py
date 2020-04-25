n = int(input())
relation = []
for i in range(n):
    str = input()
    relation += [[]]
    for char in str:
        relation[-1].append(int(char))

def countForTrue ( list ):
    count = 0
    for item in list:
        if item:
            count += 1
    return count

def flagToDPCode ( list ):
    code = 0
    for idx, item in enumerate(list):
        if item:
            code += 2 ** idx
    return code

result = 0
dp =  [[10 for i in range(2 ** 15 + 1)] for j in range(n)]
def calc (to, flags, cost):
    global result, dp
    count = countForTrue(flags)
    dp_code = flagToDPCode(flags)
    if cost < dp[to][dp_code]:
        dp[to][dp_code] = cost
        if result < count:
            result = count
    else:
        return

    for i in range(n):
        if flags[i] or relation[to][i] < cost:
            continue
        flags[i] = True
        calc(i, flags, relation[to][i])
        flags[i] = False
calc( 0, [True]+[False]*(n-1), 0 )

print( result )