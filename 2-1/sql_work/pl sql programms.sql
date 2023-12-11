
--EXAMPLE 1

set SERVEROUTPUT ON;
DECLARE
    Esal employee.salary%Type;
    Eno employee.emp_id%Type;
    N employee.dept_no%Type:=&n;
    F number;
    Cursor C is select emp_id,salary from employee where dept_no=N for update of salary;
    Wrong_Dept Exception;
Begin
    Open C;
        Loop
            Fetch c into Eno,Esal;
            Exit when C%NotFound;
            DBMS_OUTPUT.PUT_LINE(Eno||' '||Esal||' '||' '||Esal*1.1);
            Update employee set salary=salary*1.1 where current of c;
        end loop;
    F:=C%rowcount;
close C;
if(C%isopen) then dbms_output.put_line('cursor is opened');
Else dbms_output.put_line('cursor is closed');
end if;
if(F=0) then raise Wrong_Dept;
end if;
EXCEPTION
    When Wrong_Dept then dbms_output.put_line('no such department');
end;
/
    
    
--EXAMPLE 2


select * from daily_sales;
create table daily_sales (item_id number(2) primary key,qunatitiy number(5));
insert into daily_sales values(&id,&quantitiy);
truncate table daily_sales;
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

select * from cummulative_sales;


--EXAMPLE 3


select * from employee where dept_no=20;
create or replace procedure add_bonus( n in number,m in number) is
    cursor c1 is
    select emp_id,e_name,salary from employee where dept_no=m for update of salary;
    z number;
    p number;
    begin
        DBMS_OUTPUT.PUT_LINE('dept_no   emp_id   old_sal   new_sal');
        for emp_record in c1
        loop
            update employee set salary=emp_record.salary+n where current of c1;
            select salary into z from employee where emp_id=emp_record.emp_id;
            DBMS_OUTPUT.PUT_LINE(m||'   '||emp_record.emp_id||'   '||emp_record.salary||'   '||z);
            p:=c1%rowcount;
        end loop;
        DBMS_OUTPUT.PUT_LINE(p||'records are updated');
    END;
    /

exec add_bonus(1000,20);

select * from employee where dept_no=20;


--EXAMPLE 4


create or replace procedure circles(r in real,area out real,peri out real) is
    begin
        area:=3.14*r*r;
        peri:=2*3.14*r;
    end;
    /
declare
    x real;
    y real;
begin
    circles(5,x,y);
    DBMS_OUTPUT.PUT_LINE('area of circle is: '||x);
    DBMS_OUTPUT.PUT_LINE('perimeter of circle is: '||y);
end;
/

commit;


