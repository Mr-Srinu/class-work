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

