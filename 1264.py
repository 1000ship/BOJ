vowels = "aeiouAEIOU"
strings = input()
while strings != "#":
    cnt = 0
    for c in strings:
        if c in vowels:
           cnt += 1
    print( cnt )
    strings = input()