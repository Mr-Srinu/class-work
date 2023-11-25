select * from transactions;
select * from branches;
select * from accounts;
select * from loan;
select * from employee;

update loan set amount=500000 where c_id='c001';

--EXCERCISE 3 QUERIES

--QUESTION 1

select sum(balance) from accounts where status='active';

--QUESTION 2

select b.b_id,sum(balance) from branches b,accounts a
group by b.b_id;

--QUESTION 3

select b.b_id,sum(balance) from branches b,accounts a
where a.status='active'
group by b.b_id;

--QUESTION 4

select distinct a.b_id from accounts a
where (select sum(balance) from accounts a1 where status='active' and a1.b_id=a.b_id)>50000; 

--QUESTION 5

select distinct a.b_id from accounts a
where ((select sum(balance) from accounts a1 where a1.b_id=a.b_id)<(select sum(amount) from loan a2 where a2.b_id=a.b_id));

--QUESTION 6

select b_id,sum(balance) from accounts
group by b_id
order by sum(balance) desc;

--QUESTION 7

select distinct b_id from accounts a
where ((select sum(balance) from accounts a1 where a1.b_id=a.b_id)
-(select avg(balance) from accounts a2 where a2.b_id=a.b_id))>=5500;

-- B SECTION QUESTIONS IN EX3

-- QUESTION 1


