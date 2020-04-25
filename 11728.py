a, b = map(int,input().split())
first = list(map(int,input().split()))
second = list(map(int,input().split()))
print( " ".join(list(map(str,sorted(first+second)))))