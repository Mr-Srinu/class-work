#!/usr/bin/env python
# coding: utf-8

# In[25]:


from mypackage import Arithmetic as a
a.mul(10,2)
a.pow(10,2)


# In[39]:


d={1:20,2:30,3:40}
print(d.pop(2))
print(d.update(d))
print(d)
print(d.clear())
print(d)


# In[51]:


a=[1,2,3]
b=[1,3,56,{1:30,3:59}]

a.append(b)
print(a)


# In[ ]:


from package import module
module.fn1()


# In[59]:


a={1:20,2:30,4:[1,2,[10,20],3]}
print(a[4][2])
b={2:30,7:{2:30,5:80}}
print(a)
print(b)


# In[62]:


#22nd Question
def merge(l1,l2):
    l3=l1+l2
    l3.sort()
    print(l3)
def merge2(l1,l2):
    l3=l1+l2
    n=len(l3)
    for i in range(0,n):
        for j in range(0,n):
            if l3[i]<l3[j]:
                l3[j],l3[i]=l3[i],l3[j]
            
    print(l3)
l1=[1,2,3,5]
l2=[1,3,4,6]
merge2(l1,l2)


# In[63]:


#23rd Question
c=0
n=input("enter a word:")
for i in n:
    if i.islower():
        c+=1
print("the number of smalls:",c)
        


# In[ ]:


def primes(n):
    l=[]
    x=2
    while len(l)<n:
        for i in range(2,x):
            if x%i==0:
                pass
            else:
                l.append(i)
                x=x+1
    return l
n=100
l1=primes(n)
print(l1)


# In[ ]:





# In[2]:


f=open('temps.txt',"r")
f1=open('ftemps.txt',"w")
n=f.readlines()
for i in range(len(n)):
    d=n[i].strip()
    v=(float(d)*9/5)+32
    f1.write(str(v)+"\n")
f.close()
f1=open('ftemps.txt',"r")
f1.read()
f.close()
f1.close()


# In[ ]:




