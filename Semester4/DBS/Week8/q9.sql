DECLARE
	roll_number studenttable.roll%TYPE;
	score studenttable.gpa%TYPE;
	n number(10);
	i number(10);
	out_of_range EXCEPTION;
BEGIN
	roll_number:=1;
	i:=0;
	select count(roll) into n  from studenttable;
	while i<n
	LOOP		
	select gpa into score from studenttable where roll = roll_number;
	IF score between 0 and 4  then
		update studenttable
			set grade = 'F' where roll = roll_number;
	ELSIF score between 4 and 5 then
		update studenttable
			set grade = 'E' where roll = roll_number;
	ELSIF score between 5 and 6 then
		update studenttable
			set grade = 'D' where roll = roll_number;
	ELSIF score between 6 and 7 then
		update studenttable
			set grade = 'C' where roll = roll_number;
	ELSIF score between 7 and 8 then
		update studenttable
			set grade = 'B' where roll = roll_number;
	ELSIF score between 8 and 9 then
		update studenttable
			set grade = 'A' where roll = roll_number;	
	ELSIF score between 9 and 10 THEN 
		update studenttable
			set grade = 'A+' where roll = roll_number;
	ELSE
		RAISE out_of_range;								
	END IF;
	i:=i+1;
	roll_number:=roll_number+1;
	END LOOP;
EXCEPTION
	WHEN out_of_range THEN
	DBMS_OUTPUT.PUT_LINE('GPA out of range');	
END;