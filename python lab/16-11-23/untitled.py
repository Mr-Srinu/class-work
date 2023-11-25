#!/usr/bin/env python
# coding: utf-8

# In[20]:


class product:
    def __init__(self,name,amount,price):
        self.name=name
        self.amount=amount
        self.price=price
    def get_price(self,quantity):
        if quantity<10:
            return quantity*self.price
        elif 10<=quantity<100:
            return quantity*self.price*0.9
        else:
            return quantity*self.price*0.8
        
    def make_purchase(self,amount):
        if amount<=self.amount:
            self.amount=self.amount-amount
            print("remaining stocks:",self.amount)
        else:
            print(f"Insufficient stock, we have {self.amount} stocks only")
obj=product("mobile",100,6000)
print(obj.get_price(5))
print(obj.get_price(20))
print(obj.get_price(101))
obj.make_purchase(6)
obj.make_purchase(101)


# In[30]:


class time:
    def __init__(self,sec):
        self.sec=sec
    def convert_to_minutes(self):
        sec=self.sec%60
        mini=self.sec//60
        return f"{mini}:{sec}"
    def convert_to_hours(self):
        hours=self.sec//3600
        rem_s=self.sec%3600
        mini=rem_s//60
        sec=rem_s%60
        return f"{hours}:{mini:02d}:{sec:02d}"
sec=int(input("enter number of seconds: "))
obj=time(sec)
print(obj.convert_to_minutes())
print(obj.convert_to_hours())
        


# In[40]:


class power:
    def pow1(self,x,n):
        p=x**n
        print(f"Power of {x},{n} is {p}")
obj=power()
obj.pow1(8,3)


# In[12]:


class str_reverse:
    def rev(self,s):
        w=s.split(' ')
        r=' '.join(reversed(w))
        return r
    
s=input("enter a string: ")
obj=str_reverse()
print(obj.rev(s))


# In[ ]:




