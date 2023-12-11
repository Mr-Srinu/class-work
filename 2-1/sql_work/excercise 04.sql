create table tonumber(N varchar(5));
insert into tonumber values('43');
select sum(N) from tonumber;
insert into tonumber values('2.34');
select sum(N) from tonumber;

select TO_CHAR(1210.73,'$9,999.00') FROM DUAL;
select to_char(dob,'mm-dd-yyyy') as Format1, to_char(dob,'yyyy-dd-mm') as Format2 from customers where c_id='c001';
select to_char(dob,'year') from customers where c_id='c001';

select TO_DATE('20150302','yyyymmdd') as date_format from dual;
select TO_DATE('2022/10/14','yyyy/mm/dd') as date_format2 from dual;

select concat('rose','flower') as Flowername from dual;

select lpad('sql tutorial',15,'*') from dual;
select lpad('sql tutorial',10,'*/') from dual;

select rpad('sql tutorial',15,'*') from dual;
select rpad('sql tutorial',10,'/*') from dual;

select ltrim('xxyyDBMSyzx','xy') from dual;

commit;

select rtrim('xxyyDBMSyzxxyyxy','xy') from dual;

select trim(both 'x' from 'xxyyDBMSyzxxyxyx' ) from dual;

select lower('ROSE') from dual;

select upper('rose') from dual;

select initcap('rose flower'),initcap('rose') from dual;

select substr('rose flower',1,4) from dual;

select length(c_name) from customers where c_id='c001';

select instr('information technology','m') from dual;

select sysdate from dual;

select next_day('19-Oct-2022','Saturday') from dual;

select last_day('19-Oct-2022') from dual;


create table tomnum(n varchar(5));
insert into tomnum values('123');
insert into tomnum values('231');
select sum(n) from tomnum;
insert into tomnum values('2,3,1');
select TO_NUMBER(n,'99999') from tomnum;
select sum(TO_NUMBER(n,'99999')) from tomnum;

select sysdate from dual;


select c_id,c_name,gender from customers;
select c_id,dob from customers where gender='female';
select c.city,b.city,c.c_name from customers c,branches b,accounts a
where c.c_id='c001' and c.c_id=a.c_id and b.b_id=a.b_id ;
select acc_no from accounts where acc_type='sb' and status='suspended';
select t1.acc_no,t1.t_date from transactions t1, transactions t2
where t1.acc_no=t2.acc_no and t1.t_date=t2.t_date and t1.t_type='debit' and t2.t_type='credit';
select floor((sysdate-dob)/365) as age from customers where c_id='c001';
alter table customers add l_name char(2);
insert into customers(l_name) values('B');
select * from  customers;
select max as salary_range from sal where job='president';
commit;
