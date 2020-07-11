1.) 

Select bdate,address from employee where fname='John' and minit='B' and lname='Smith';

Select fname,minit,lname,address from employee natural join department1 where dname='Research';

2.) Select lname,address,bdate,dnumber from department1 natural join project,employee
where employee.ssn=mgr_ssn and plocation='Stafford';

3.) Select distinct(salary) from employee; 

4.) Select T.lname,T.fname,S.lname,S.fname from employee T,employee S where T.ssn=S.super_ssn;

5.) Select pnumber from employee,works_on,project where lname='Smith' and employee.ssn=works_on.essn and works_on.pno=project.pnumber;

6.) Select * from employee where address like '%Houston, TX%';

7.) Update employee set salary=1.1*salary where employee.ssn in (Select essn from works_on,project where works_on.pno=project.pnumber and pname='ProductX');

8.) Select fname from department1,employee where dnumber=5 and salary between 30000 and 40000 and employee.dno=department1.dnumber;

9.) Select fname,lname from employee,project,works_on where works_on.pno=project.pnumber and works_on.essn=employee.ssn order by fname,lname;

10.) Select fname,lname from employee where super_ssn is NULL;

11.) Select lname,fname from employee,dependent where.employee.fname=dependent.dependent_name and employee.sex=dependent.sex;

12.) Select distinct(fname) from employee,dependent where employee.ssn not in (Select essn
from dependent);

13.) 

With a(b,c) as 
(Select fname,ssn
from department1,employee
where department1.mgr_ssn=employee.ssn)
Select distinct(a.b)
from a,employee
where a.c=employee.ssn and 1<=(select count(essn)
from dependent,employee
where dependent.essn=employee.ssn);

14.)

Select distinct(ssn) from employee,works_on,project where (pnumber=1 or pnumber=2 or pnumber=3) and employee.ssn=works_on.essn;

15.) Select max(salary),sum(salary),min(salary),avg(salary) from employee;

16.) Select max(salary),sum(salary),min(salary),avg(salary) from employee,department1
where employee.dno=department1.dnumber and dname='Research';

17.) Select pnumber,pname from works_on,employee,project where employee.ssn=works_on.essn and employee.ssn=project;

18.) Select pno, pname, count(name) from works_on, project where pno=pnumber, group by pro, name having count(pname)>2;

19.) Select don from department where department.dno=employee.dno and salary>40000 and dno in ( Select duo, count(*) from employee, group by don having count(*)>5);
