num = int(input())

def naming(n):
    if n==1:
        return "1 bottle"
    elif n==0:
        return "no more bottles"
    return "{} bottles".format(n)

def sing(a, b):
    str = "{} of beer on the wall, {} of beer.\nTake one down and pass it around, {} of beer on the wall.".format(naming(a), naming(a), naming(b))
    return str

def sing_end(b):
    str = "No more bottles of beer on the wall, no more bottles of beer.\nGo to the store and buy some more, {} of beer on the wall.".format(naming(b))
    return str


for i in range(num, 0, -1):
    print(sing(i, i-1))
    print()
print(sing_end(num))