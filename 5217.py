case = int(input())
tuples = [ (a, b) for a in range(1,13) for b in range(a+1, 13) ]
for _case in range(case):
    n = int(input())
    print(f"Pairs for {n}:", end="")
    isFirst = True
    for a, b in tuples:
        if a + b == n:
            print( f"{',' if not isFirst else ''}", a, b, end="" )
            isFirst = False
    print()