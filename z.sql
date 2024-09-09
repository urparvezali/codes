-- Active: 1719579663058@@127.0.0.1@1433@pubs
select * from sysobjects;
select name from sysobjects where xtype='U';
select au_lname,state from authors;


#task 1
select title from titles where ytd_sales>8000;

#task 2
select title from titles where royalty between 12 and 24;

#task 3

select type, avg(price) as Average from titles GROUP BY type;




create table customer_and_suppliers(
	cust_id varchar(6)
)