1.) Select dept_name,count(distinct ID) from student group by dept_name;

2.) Select dept_name,count(distinct ID) from (student natural join takes) group by dept_name having count(distinct id) > 10;

3.) Select dept_name,count(distinct course_id) from course group by dept_name;

4.) Select dept_name,avg(salary) from instructor group by dept_name having avg(salary) > 42000;

5.) Select sec_id,count(distinct ID) from (takes natural join section) where semester='Spring' and year=2009 group by sec_id;

6.) Select course_id,prereq_id from prereq order by course_id; 

7.) Select name,salary from instructor order by salary desc ;

8.) Select max(total_salary) from (Select sum(salary) as total_salary from instructor group by dept_name);

9.) Select dept_name,avg(salary) from (Select dept_name, avg(salary) as avg_salary from instructor group by dept_name) where avg_salary>42000; 

10.) Select max(total_student) from (Select count(distinct ID) as total_student from takes group by sec_id, semester, year having semester='Spring' and year=2010);

11.) Select distinct t.Name from Instructor t, teaches s, takes m, student n where t.id=s.id and s.course_id=m.course_id and m.id = n.id and n.dept_name = 'Comp. Sci';

12.) Select dept_name, avg(inst_salary) From instructor group by dept_name having avg(inst_salary)>50000 and count(id)>5;

13.) With max_budget(value) as (Select max(budget) from department) Select budget from department, max_budget where department.budget=max_budget.value;

14.) 

With dept_total(dept_name,value) as (Select dept_name,sum(salary) from instructor group by dept_name),dept_total_average(value) as (Select avg(value) from dept_total) Select dept_name from dept_total, dept_total_average >= dept_total_avg.value;

15.) With max_enroll(value) as(Select max(count(id)) From takes group by sec_id, year, semester having year=2009 and semester ='Fall') enrollment(sec_id, value) as (select sec_id, count(id) from takes group by sec_id, year, semester having year=2009 and semester='Fall') Select sec_id from enrollment.value;


16.) 

17.) Delete from instructor where dept_name = 'Finance';

18.) Delete from course where dept_name='Comp. Sci.';

19.) 

Update student 
set dept_name ='IT';
Where dept_name = 'Comp. Sci';

20.) 

Update instructor
set salary=case
when salary<=100000 then salary*1.05
else salary*1.03
end

(OR)

Update instructor set salary=salary*1.03 where salary>100000;
Update instructor set salary=salary*1.03 where salary<=100000;

21.) 

Insert into student 
Select ID,name,dept_name,0 from instructor;

22.) Delete from instructor where salary < (Select avg(salary) from instructor);