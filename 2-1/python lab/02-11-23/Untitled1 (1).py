#!/usr/bin/env python
# coding: utf-8

# In[9]:


f=open("temps.txt","r")
li=f.readlines()
f1=open("ftemps.txt","w")
for i in range(len(li)):
    e=li[i].strip()
    val=(float(e)*9/5)+32
    f1.write(str(val)+"\n")
f1.close()
f2=open("ftemps.txt","r")
f2.read()

    


# In[10]:


f=open("ftemps.txt","r")
f.read()


# In[ ]:




