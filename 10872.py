def fact(x):
    if x == 1 or x == 0:
        return 1
    return x * fact(x-1)
print(fact(int(input())))