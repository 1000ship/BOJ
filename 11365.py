while True:
    string = input()
    if string == "END":
        break
    for i in range(len(string)-1, -1, -1):
        print(string[i], end="")
    print()