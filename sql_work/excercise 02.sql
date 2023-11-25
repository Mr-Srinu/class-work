
--EXCERCISE 2 QUERIES (ON BANK DB)

select distinct b2.b_id,b2.city,b2.assets from branches b1, branches b2
where b1.city='bhimavaram' and b1.b_id!=b2.b_id and b1.assets<b2.assets and b1.city!=b2.city;

select distinct a1.acc_no from accounts a1, accounts a2 where a1.balance>a2.balance;

select t_id from transactions where acc_no='a001' or acc_no='a005';

select c_id from accounts where b_id='ub001' or b_id='cb002' or (b_id='ub001' and b_id='cb002');

select DISTINCT l.c_id from loan l, accounts a where l.b_id='ub001' and l.c_id=a.c_id; 

select DISTINCT a.c_id from loan l, accounts a where a.b_id='cb001' and a.c_id!=l.c_id and a.b_id=l.b_id ;

select DISTINCT a.c_id  from branches b, accounts a where b.city!='bhimavaram' and b.b_id=a.b_id ;

select DISTINCT a.c_id  from branches b, accounts a where b.city='bhimavaram' and b.b_id=a.b_id ;

select distinct a.acc_no ,c.c_name from accounts a, customers c where a.b_id='cb001' and a.c_id=c.c_id;

select DISTINCT a1.c_id  from branches b, accounts a1,accounts a2 
where b.city='bhimavaram' and b.b_id=a1.b_id and a1.b_id=a2.b_id and a1.c_id=a2.c_id ;

--TABLES

--stores

create TABLE stores(store_id char(3) primary key,adress varchar(20), manager varchar(6));
insert into stores values('&s_id','&a','&m');
select * from stores;

--ITEMS

create table items(item_id char(3) primary key,name varchar(10),unit_price number(4),units varchar(6),main_store char(3) references stores);
insert into items values('&id','&n',&p,'&u','&m');
select * from items;

--CUSTOMER

create table customer (cust_id char(3) primary key,f_name varchar(6),l_name varchar(6),gender char(1) check(gender in('m','f')),
f_store char(3) references stores );
insert into customer values('&cid','&f','&l','&g','&s');
select * from customer;
commit;

--PURCHASE

create table purchase(p_id char(3) primary key , units_sold number(2),item_id char(3) references items, 
cust_id char(3) references customer, store_id char(3) references stores, p_date date); 

insert into purchase values('&pid',&units,'&id','&cid','&sid','&date');
select * from purchase;
commit;

--QUERIES

--Q1
select cust_id from customer where f_store='s01';

--Q2
select sum(units_sold) from purchase where cust_id='c01';

--Q5
select distinct f_store from customer where f_store in 
((select distinct p.store_id from purchase p,customer c where p.cust_id=c.cust_id and c.gender='f')
MINUS(select distinct p.store_id from purchase p,customer c where p.cust_id=c.cust_id and c.gender='m'));

--Q7
select cust_id from customer where customer.cust_id IN
((select cust_id from customer )
MINUS 
(select distinct cust_id from purchase));

--Q8
select cust_id,gender from customer where cust_id in 
(select distinct p1.cust_id from purchase p1 where p1.store_id='s01' or p1.store_id='s03');
--OR
select cust_id,gender from customer where cust_id in 
((select distinct p1.cust_id from purchase p1 where p1.store_id='s01' )
intersect
(select distinct p2.cust_id from purchase p2 where p2.store_id='s03' ));

