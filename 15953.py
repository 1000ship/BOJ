a_list = [0]
b_list = [0]

def addto( list, value, cnt ):
    for i in range(cnt):
        list += [value*10000];

a_tuple = [(10,6),(30,5),(50,4),(200,3),(300,2),(500,1)]
b_tuple = [(32,16),(64,8),(128,4),(256,2),(512,1)]
a_tuple.reverse()
b_tuple.reverse()
for x, y in a_tuple:
    addto(a_list,x,y)
for x, y in b_tuple:
    addto(b_list,x,y)
def get_item(list,idx):
    if idx >= len(list):
        return 0
    else:
        return list[idx]

T = int(input())
for t_num in range(T):
    a, b = map(int,input().split())
    result = get_item(a_list,a) + get_item(b_list,b)
    print(result)
