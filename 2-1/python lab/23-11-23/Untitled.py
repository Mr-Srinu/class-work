#!/usr/bin/env python
# coding: utf-8

# In[6]:


from tkinter import filedialog
from tkinter import Tk
from tkinter import *
root=Tk()
root.fileName=filedialog.askopenfilename()
text1=open(root.fileName).read()
T=Text(root,height=25,width=80)
T.pack()
T.insert(END,text1)
root.mainloop()


# In[9]:


try:
    a=int(input("enter first number: "))
    b=int(input("enter second number: "))
    s=a/b
except ZeroDivisionError:
    print("you are trying to divide with zero!")
else:
    print("the division result is:",s)


# In[18]:


try:
    a=int(input("enter first number: "))
    b=int(input("enter second number: "))
    s=a/b
except ZeroDivisionError:
    print("you are trying to divide with zero!")
else:
    print("the division result is:",s)
finally:
    print("The programm execution completed")
with open("temp.txt",'w') as f:
    try:
        f.write("hello hi")
    finally:
        f.close()
with open("temp.txt",'r') as f:
    print(f.read())


# In[ ]:




