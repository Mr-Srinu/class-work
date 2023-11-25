--EXCERCISE 1 (TABLES)

--CUSTOMERS TABLE

create table customers(c_id char(4) primary key,city varchar(12),gender varchar(6) Check(gender in ('male','female')));
select * from customers;
alter table customers add dob date;
alter table customers add occupation varchar(10);
alter table customers add c_name varchar(10);
select * from customers;
insert into customers values('c001','bhimavaram','male','11-08-1998','employee','chandra');
insert into customers values('&a','&b','&c','&d','&e','&f');
select * from customers;
commit;

--BRANCHES TABLE

create table branches (b_id char(5) primary key,b_name varchar(12), city varchar(12),assets number(10));
insert into branches values('&a','&b','&c',&d);
select * from branches;
commit;

--ACCOUNTS TABLE

create table accounts(acc_no char(4) primary key,c_id char(4) references customers,b_id char(5) references branches,balance number(10,2),
open_date date,acc_type char(4) check(acc_type in('sb','ca')),
status varchar(9) check (status in ('active','suspended')));
insert into accounts values('a001','c001','sb001',20000,'10-08-2017','sb','active');
insert into accounts values('&a','&b','&c',&d,'&e','&f','&h');
select * from accounts;

--TRANSACTIONS TABLE

create table transactions (t_id char(4) primary key ,acc_no char(4) references accounts,
t_date date,t_type varchar(6)check (t_type in('credit','debit')),
t_mode varchar(6) check (t_mode in('online','cash','cheque')),amount number(5));
insert into transactions values('&a','&b','&c','&d','&e',&f);
select * from transactions;

--LOANS TABLE

create table loan(l_no char(4)primary key ,c_id char(4) references customers,
b_id char(5) references branches,amount number(10,2));
insert into loan values('&a','&b','&c',&d);
select * from sal;

--DEPARTMENTS TABLE

create table dept (dept_no number(2) primary key, d_name varchar(15), location varchar(10));
insert into dept values(&a,'&b','&c');
select * from dept;

--SALARY TABLE

create table sal (job varchar(15),min number(5), max number(6));
insert into sal values('&a',&b,&c);
select * from sal;
commit;

--EMPLOYEES TABLE


create table employee(emp_id number(4) primary key,e_name varchar(20), dob date,job varchar(15),m_id NUMBER(4),
hire_date date,salary number(5),bonus number(5),dept_no number(2) references dept);

insert into employee values(&eid,'&name','&dob','&job',&mid,'&date',&sal,&bonus,&dept);
select * from employee;
commit;

select * from BIN$gJHJlrwfSgmxmby4OWncRQ==$0;
--END OF TABLES

select * from tab;
commit