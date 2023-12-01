set serveroutput on;
--pl/sql-1

declare
    Esal employees.salary%Type;
    Eno employees.emp_id%Type;
    N employees.dept_no%Type:=&N;
    F number;
    Cursor C is select emp_id, salary from employees where dept_no = N for update of salary;
    wrong_dept Exception;
Begin
    Open C;
        loop
            Fetch C into Eno,Esal;
            Exit when C%NotFound;
            dbms_output.put_line(Eno||' '||Esal||' '||Esal*1.1);
            update employees set salary = salary *1.1 where current of c;
        end loop;
    F:=C%rowcount;
    close C;
    if(C%isopen) then dbms_output.put_line('cursor is opened');
    Else dbms_output.put_line('cursor is closed');
    end if;
    if(F=0)then raise Wrong_dept;
    end if;
    Exception
    When Wrong_dept then dbms_output.put_line('No such department');
end;
/
--ex2--
select * from daily_sales;
create table daily_sales (item_id number(2) primary key,qunatitiy number(5));
insert into daily_sales values(&id,&quantitiy);
create table cummulative_sales(item_id number(2) primary key,qunatitiy number(5));

create or replace function check_item(id number)
    return number is di number(2);
    begin
        select item_id into di from cummulative_sales where item_id=id;
        if(di is not null) then return 1;
        end if;
    Exception
        when no_data_found then return 0;
    end;
    /

declare
    cursor c is select item_id,sum(qunatitiy) as total from daily_sales group by item_id;
    vid daily_sales.item_id%Type;
    vqty daily_sales.qunatitiy%TYPE;
    value number(1);
Begin
    open c;
    loop
        fetch c into vid,vqty;
        exit when c%NotFound;
        value:=check_item(vid);
        if value=0 then insert into cummulative_sales values(vid,vqty);
        elsif value=1 then update cummulative_sales set qunatitiy=qunatitiy+vqty where item_id=vid;
        end if;
    end loop;
    close c;
end;
/
commit;
select * from daily_sales;

--Ex 3--
insert into emps select * from employees;
create or replace procedure Add_bonus(N in Number, M in Number) is 
     cursor C1 is 
     select emp_id,e_name,salary from employees where dept_no = M for update of salary;
     z number;
     p number;
     begin 
        dbms_output.put_line('dept_no   emp_id   old_sal   new_sal');
        for emp_record in C1
        loop
            update employees set salary = emp_record.salary+N where current of C1;
            select salary into z from employees where emp_id = emp_record.emp_id;
            dbms_output.put_line(M||'   '||emp_record.emp_id||'   '||emp_record.salary||'   '||Z);
            p:= C1%rowcount;
        end loop;
        dbms_output.put_line(p||' Records are updated ');
    end;
/
exec Add_bonus(500,20);
select * from employees;

create or replace procedure circle_area( radius in real, area out real, peri out real) is 
    begin 
        area:=3.14*radius*radius;
        peri  :=2*3.14*radius;
        end;
    /
    

--example4
CREATE OR REPLACE PROCEDURE Circle_area(radius IN REAL, Area OUT REAL, Peri OUT REAL) IS
BEGIN
    Area := 3.14 * radius * radius;
    Peri := 2 * 3.14 * radius;
END;
/
DECLARE
    X REAL;
    Y REAL;
BEGIN
    Circle_area(5, X, Y);
    DBMS_OUTPUT.PUT_LINE('Area of circle is: ' || X);
    DBMS_OUTPUT.PUT_LINE('Perimeter of circle is: ' || Y);
END;
/
--example5
CREATE OR REPLACE FUNCTION conver(N REAL, CF REAL) 
RETURN REAL IS
BEGIN 
    RETURN N * CF;
END;
/
create table hw(foot number(5),inches number(2),cm number(5,2),weight number(5,2));
insert into hw values('&foot','&inches','&cm','&weight');
drop table hw purge;
create table hw(foot number(5),inches number(2),cm number(5,2),weight number(5,2));
create or replace procedure populate_hwtable is
f number(1);
i number(2);
t number(5,2);
begin
for f in 5..6 loop
for i in 0..11 loop
t:=conver(conver(f,12)+i,2.54);
if(f=5)then
    IF(i>=0 AND i<=11) THEN
        insert into hw values(f,i,t,(t-100));
    end if;
end if;
if(f=6) then
    if(i>=0 and i<=2) then 
        insert into hw values(f,i,t,(t-100));
    end if;
end if;
end loop;
end loop;
end;
/
exec populate_hwtable;
select * from hw;