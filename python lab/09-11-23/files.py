def bwrite():
    import pickle
    f=open("bfile.bin",'wb')
    d=(2,3,4,5)
    pickle.dump(d,f)
bwrite()
f=open("bfile.bin",'rb')
f.read()

f=open("bfiles.bin","wb+")
msg="hello coders "
fileencode=msg.encode('ASCII')
f.write(fileencode)
bdata=f.read()
print(bdata)
ndata=bdata.decode('ASCII')
print(ndata)

with open("temp.txt") as f:
    data=file.readlines()
    print(data)
    for i in data:
        word=i.split()
        print(word)