CREATION OF EMPLOYEE

create table EMPLOYEE(
emp_no number(10) primary key,
emp_name varchar(20) not null,
gender char(2) not null,
salary number(10,2) not null,
address varchar(50) not null,
dno number(10),
check(gender in ('f','m')));

CREATION OF DEPARTMENT

create table DEPARTMENT(
dept_no number(5) primary key,
dept_name varchar(10) unique,
location varchar(10));

3.) alter table EMPLOYEE modify foreign key(dno) references department(dept_no);

4.) 

insert into DEPARTMENT(dept_no,dept_name,location) values(102, 'CSE','Manipal');

insert into DEPARTMENT(dept_no,dept_name,location) values(103, 'ECE','Manipal');

insert into DEPARTMENT(dept_no,dept_name,location) values(104, 'EEE','Manipal');

insert into EMPLOYEE(emp_no,emp_name,gender,salary,address,dno) values(1,'Anirudh','m',100000,'Manipal','102');

insert into EMPLOYEE(emp_no,emp_name,gender,salary,address,dno) values(2,'Adithya','m',100000,'Manipal','103');

insert into EMPLOYEE(emp_no,emp_name,gender,salary,address,dno) values(3,'Ruth','m',100000,'Manipal','104');

5.)

insert into EMPLOYEE(emp_no,emp_name,gender,salary,address,dno) values(1,'Anirudh','m',100000,'Manipal','102');

insert into EMPLOYEE(emp_no,emp_name,gender,salary,address,dno) values(1,'Adithya','m',100000,'Manipal','103');

insert into EMPLOYEE(emp_no,emp_name,gender,salary,address,dno) values(1,'Ruth','m',100000,'Manipal','104');

6.) 

alter table Employee drop constraint abc;
alter table Employee add constraint FK_DNo foreign key(dno) references Department(dept_no) ON DELETE CASCADE;


7.) alter table EMPLOYEE drop foreign key;

8.) alter table EMPLOYEE modify salary default 10000; 


Select sysdate from dual;

9.) Select name,dept_name from student;

10.)Select name,dept_name from instructor where dept_name='Comp. Sci.';

11.) Select title,credits from course where dept_name='Comp. Sci.' and credits=3;

12.) Select title,course_id from course natural join takes where ID=12345;

13.) Select name from instructor where salary between 40000 and 90000;

14.) Select instructor.id from instructor where id not in (select distinct teaches.id from teaches);

15.) 

Select name, title, takes.year FROM student, section, course, takes WHERE room_number=3128 and course.course_id = section.course_id and course.course_id = takes.course_id and takes.id = student.id and takes.year = section.year and takes.sec_id = section.sec_id and section.semester = takes.semester;

16.) Select name,course_id,title as c_name from (student natural join takes) join course using(course_id) join student using (id) where year=2010 ;
 

17.) Select distinct T.name from instructor as T, instructor as S where T.salary > S.salary and S.dept_name='Comp. Sci. ';

18.) Select name from instructors where dept_name like '%ch%';

19.) Select name,LENGTH(name) from student;

20.) select dept_name,substr(dept_name,3,3) from department;

21.) Select UPPER(name) from instructor;

22.) Select NVL(grade,'F') from takes;

23.) Select salary,ROUND(salary/3,-2) from instructor;

alter table EMPLOYEE add(DOB date);

Update employee set DOB='29-DEC-2000';

Select * from EMPLOYEE WHERE DOB='29-DEC-2000';

24.)

Select emp_name, to_char(DOB,'DD-MON-YYYY') from employee;
Select emp_name, to_char(DOB,'DD-MON-YY') from employee;
Select emp_name, to_char(DOB,'DD-MM-YY') from employee;

25.)

Select emp_name,dob from EMPLOYEE;
Select emp_name, TO_CHAR(DOB, 'YYYY') from EMPLOYEE;


26.) Select emp_name, TO_CHAR(DOB, 'DD') from EMPLOYEE;

27.)  Select emp_name, TO_CHAR(DOB, 'MON') from EMPLOYEE;deop

28.) Select emp_name, LAST_DAY(DOB) from EMPLOYEE;

29.) Select emp_name, DAYNAME(DOB) from EMPLOYEE;

30.) Select Next_day(Add_Months(DOB, 720), 'Saturday') from employee;

31.) Select emp_name from employee where extract(year from dob) = 1998;

32.) Select emp_name from employee where extract(year from dob) between 1997 AND 1999;

33.) Select emp_name from employee where (extract(year from dob)+60) = 2058;