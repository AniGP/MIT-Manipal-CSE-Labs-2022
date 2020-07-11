Intoduction to SQL : 

DDL Commands : 

1.) CREATION OF TABLE

create table STUDENT(
reg_no number(5),
stu_name varchar(20),
stu_age number(5),
stu_dob date,
subject1_marks number(4,2),
subject2_marks number(4,2),
subject3_marks number(4,1));

insert into STUDENT values(101,'AAA',16,'03-jul-88',80,90,98);
desc STUDENT;

2.) Modifying the structure of tables  

alter table student add(Gender char(5)); (case insensitive )
desc STUDENT;

3.) Dropping a column from a table

alter table STUDENT drop column Gender;
desc STUDENT;

4.) Modfiying existing columns

alter table STUDENT modify(stu_age number(7));

5.) Renaming the tables 

Rename student to students;

6.) Truncate the table

Truncate table students;

7.) Delete the table structure

drop table student;

DML Commands : 

1.) Selecting the information from table(s) : 

a) List all students - Select * from students;

b) Select stu_age student_age from students; 

c) Select subject1_marks + subject2_marks + subject3_marks tot_marks from students;  

2.) Inserting data into tables : 

insert into STUDENTS(reg_no,stu_name) values(102, 'KRISH');

3.) Delete Operations

Removal of specified rows : Delete from STUDENTS where reg_no=102;

Remove all rows : Delete from STUDENT;

4.) 

a.) Updating all rows 

Update STUDENTS set stu_name='MANAV';

b) Updating selected records

Update STUDENTS set stu_name='YADAV' where reg_no=101;

LAB EXERCISES :

1.) create table EMPLOYEE(
emp_no number(5),
emp_name varchar(20),
emp_address varchar(30));

2.) 

insert into EMPLOYEE(emp_no, emp_name, emp_address) values(1, 'A', 'Bengaluru');

insert into EMPLOYEE(emp_no, emp_name, emp_address) values(2, 'B', 'Hyderabad');

insert into EMPLOYEE(emp_no, emp_name, emp_address) values(3, 'C', 'Manipal');

insert into EMPLOYEE(emp_no, emp_name, emp_address) values(4, 'D', 'Mangalore');

insert into EMPLOYEE(emp_no, emp_name, emp_address) values(5, 'E', 'Mangalore');

3.) Select * from employee;

4.) Select emp_name from employee where emp_address='Manipal';

5.) alter table employee add(salary number(4));

6.) Update employee set salary='100';

7.) desc EMPLOYEE;

8.) Delete from employee where emp_address='Mangalore';

9.) Rename employee to employee1;

10.) drop table employee1;