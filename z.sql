select * from sysobjects;
select name from sysobjects where xtype='U';
select au_lname,state from authors;


#task 1
select title from titles where ytd_sales>8000;

#task 2
select title from titles where royalty between 12 and 24;

#task 3

select type, avg(price) as Average from titles GROUP BY type;

select * from titles;

