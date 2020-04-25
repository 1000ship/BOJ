str = input()
if len(str)==1:
    print("◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!")
else:
    d = int(str[0]) - int(str[1])
    b = False
    for i in range(1,len(str)-1):
        if d != int(str[i])-int(str[i+1]):
            break
    else:
        b = True
    if b:
        print("◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!")
    else:
        print("흥칫뿡!! <(￣ ﹌ ￣)>")