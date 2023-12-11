d1={1:23,2:"hellp",3:{4:"srkr",5:"it",6:{1:"C",2:"branch"}}}
print(d1[3][6][2])

d=dict()
for i in range(0,3):
    ename=input()
    sal=int(input())
    d['ename'+str(i)]=ename
    d['sal'+str(i)]=sal
print(d)

d={1:10,2:"hello"}
x=d.keys()
y=d.values()
print("keys:")
for i in x:
    print(i)
print("values:")
for j in y:
    print(j)