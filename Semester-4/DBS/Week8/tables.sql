create table studentTable(
	roll number(2),
	gpa numeric(4,2));
insert into studentTable values(1,5.8);
insert into studentTable values(2,6.5);
insert into studentTable values(3,3.4);
insert into studentTable values(4,7.8);
insert into studentTable values(5,9.5);
insert into studentTable values(6,11);

alter table studentTable 
add  grade varchar2(2);