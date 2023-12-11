--TRIGGERS EXAMPLES

--EX1

    create or replace trigger min_balance
    before insert or update on accounts
    for each row
    begin
        if inserting then
            if :new.balance<1000 then
                RAISE_APPLICATION_ERROR(-20000, 'Account has not created');
            end if;
        elsif  updating then
            if(:new.balance<1000) then
                RAISE_APPLICATION_ERROR(-20000, 'Account has no sufficient balance');
            end if;
        end if;
    end;
    /
    update accounts set balance=990
    where acc_no='a001';
    
    update accounts set balance=1500
    where acc_no='a001';
    
--Ex2

create table book(bid char(3) primary key,status varchar(10) check (status in('available','issued')));
insert into book values('&bid','&status');

create table issue(bid char(3) primary key references book, sid char(3),due_date date);

create or replace trigger book_status
after insert or delete on issue
for each row
begin
    if inserting then
        update book set status='issued'
        where bid=:new.bid;
    elsif deleting then
        update book set status='available'
        where bid=:old.bid;
    end if;
end;
/

insert into issue values('b01','s01','25-11-2023');
delete from issue where bid='b01';
select * from book;
select * from issue;


--EXAMPLE 3

--TABLES CREATION--
        
create table students(sid char(3) primary key, cgpa number(4,2));        
insert into students values('s01',8.2);
insert into students values('&sid',&cgpa);
select * from students;

create table std_8(sid char(3) primary key references students, cgpa number(4,2));
insert into std_8 select * from students where students.cgpa>=8.0;
select * from std_8;

--TRIGGER

create or replace trigger cgpa
after update on students
for each row
begin
    if(:new.cgpa>=8.0 and :old.cgpa>=8.0) then
        update std_8 set cgpa=:new.cgpa
        where sid=:new.sid;
    elsif(:new.cgpa<8.0 and :old.cgpa>8.0) then
        delete from std_8 where sid=:new.sid;
    elsif(:new.cgpa>=8.0 and :old.cgpa<8) then
        insert into students values(:new.sid,:new.cgpa);
    end if;
end;
/

update students set cgpa='7.9' 
where sid='s01';


--EXAMPLE 4

select * from customers;

commit;

--TRIGGER--

create or replace trigger count
after insert or delete on customers

declare 
    n INTEGER;
begin
    select count(*) into n from customers;
    DBMS_OUTPUT.PUT_LINE('There are '||n||' customers');
end;
/
set serveroutput on;

insert into customers values('c11','ongole','male','22-11-2005','employee','david','b');
delete from customers where c_id='c11';

commit;

--EXAMPLE 5

--INSTEAD OF TRIGGER 

create table emptemp(empid number(4) primary key,deptid number(2),salary number(6),mgr_id number(4));
insert into emptemp values(&id,&dept,&sal,&mig);
select * from emptemp;

create view  emptemp_view AS select deptid,salary from emptemp;
select * from emptemp_view;

create sequence seq1 start with 1 increment by 1;

create or replace trigger trg
instead of insert on emptemp_view
begin
    insert into emptemp values(seq1,nextval,:new.deptid,:new.salary);
end;
/


    


