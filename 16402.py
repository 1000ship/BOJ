n, m = map(int,input().split())
arr1 = []
arr2 = []
for i in range(n):
    arr1.append( input()[11:] )
    arr2.append( i )

for i in range(m):
    tmp = input().split(",")
    a = tmp[0][11:]
    b = tmp[1][11:]
    ta = arr2[ arr1.index(a) ]
    while ta != arr2[ ta ] :
        ta = arr2[ ta ]
    tb = arr2[ arr1.index(b) ]
    while tb != arr2[ tb ] :
        tb = arr2[ tb ]
    if ta == tb:
        ta = arr2[arr1.index(a)]
        if ta == arr2[ ta ] and tmp[2] == "2":
            arr2[ arr1.index(b) ] = arr1.index(b)
            arr2[ ta ] = arr1.index(b)
        elif tb == arr2[ tb ] and tmp[2] == "1":
            arr2[arr1.index(a)] = arr1.index(a)
            arr2[tb] = arr1.index(a)
    else:
        if tmp[2] == "1" :
            arr2[ tb ] = ta
        else:
            arr2[ ta ] = tb

result = []
for i in range(n):
    if arr2[ i ] == i:
        result.append( arr1[i] )

print( len(result) )
result.sort()
for i in range(len(result)):
    print( "Kingdom of {}".format(result[i]) )