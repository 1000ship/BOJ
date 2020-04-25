str='''c=
c-
dz=
d-
lj
nj
s=
z='''
lst=str.split('\n')
txt=input()
for i in lst:
    txt = txt.replace(i, "_")
print(len(txt))