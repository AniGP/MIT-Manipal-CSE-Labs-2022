1.) 

SELECT course_id FROM section WHERE semester = 'Fall' AND year = 2009 
UNION 
SELECT course_id FROM section WHERE semester = 'Spring' and year = 2010; 

2.)

SELECT course_id FROM section WHERE semester = 'Fall' AND year = 2009 
INTERSECT 
SELECT course_id FROM section WHERE semester = 'Spring' and year = 2010;                    

3.)

SELECT course_id FROM section WHERE semester = 'Fall' AND year = 2009 
MINUS 
SELECT course_id FROM section WHERE semester = 'Spring' and year = 2010; 

4.) SELECT course.course_id FROM course WHERE course.course_id NOT IN (SELECT takes.course_id FROM takes); 

5.) SELECT s1.course_id FROM section s1 WHERE semester = 'Fall' AND year = 2009 AND s1.course_id IN (SELECT s2.course_id FROM section s2 WHERE semester = 'Spring' and year = 2010 ); 

6.) SELECT COUNT(UNIQUE takes.id) FROM takes WHERE takes.course_id IN (SELECT teaches.course_id FROM teaches WHERE teaches.ID = '10101'); 

7.) SELECT s1.course_id FROM section s1 WHERE semester = 'Fall' AND year = 2009 AND s1.course_id NOT IN (SELECT s2.course_id FROM section s2 WHERE semester = 'Spring' and year = 2010 ); 

8.) SELECT UNIQUE student.name FROM student WHERE student.name IN (SELECT instructor.name FROM instructor); 

9.) SELECT i1.name FROM instructor i1 WHERE i1.salary > SOME(SELECT i2.salary FROM instructor i2 WHERE i2.dept_name = 'Biology'); 

10.) SELECT i1.name FROM instructor i1 WHERE i1.salary > ALL(SELECT i2.salary FROM instructor i2 WHERE i2.dept_name = 'Biology' ); 

11.) SELECT dept_name FROM(SELECT dept_name, avg(salary) avgsal FROM instructor GROUP BY dept_name) WHERE avgsal = (SELECT MAX(avgsal) FROM (SELECT dept_name, AVG(salary) avgsal FROM instructor GROUP BY dept_name)); 

12.) SELECT department.dept_name FROM department WHERE department.budget < (SELECT avg(salary) avgsal FROM instructor); 

13.) SELECT course_id FROM section WHERE semester = 'Fall' AND year = 2009 AND EXISTS(SELECT course_id FROM section WHERE semester = 'Spring' and year = 2010); 

14.) SELECT DISTINCT S.ID, S.name FROM student S WHERE NOT EXISTS((SELECT course_id FROM course WHERE dept_name = 'Biology') 
EXCEPT(SELECT T.course_id FROM takes T WHERE S.ID = T.ID));

15.) SELECT course.course_id from course WHERE UNIQUE(SELECT section.course_id FROM section WHERE course.course_id = section.course_id AND section.year = 2009); 

16.) SELECT dept_name, avg_salary FROM (SELECT dept_name, AVG(salary) avg_salary FROM instructor GROUP BY dept_name) WHERE avg_salary > 42000;

17.) CREATE VIEW all_courses as SELECT section.course_id, building, room_number FROM section, course WHERE semester = 'Fall' AND year = 2009 AND section.course_id = course.course_id AND dept_name = 'Physics';

18.) SELECT course_id FROM all_courses;

19.) CREATE VIEW department_total_salary as SELECT dept_name, SUM(salary) sum_sal FROM instructor GROUP BY dept_name;