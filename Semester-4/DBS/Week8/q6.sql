DECLARE
	roll_number studenttable.roll%TYPE;
	score studenttable.gpa%TYPE;
	n number(10);
	temp studenttable.gpa%TYPE;	
BEGIN
	temp:=0;
	roll_number:=1;
	select count(roll) into n from studenttable;
	FOR i IN 1..n LOOP
		select gpa into score from studenttable where roll = roll_number;
			IF score>temp THEN
				temp:=score;
			ELSE
				temp:=temp;
			END IF;
			roll_number:=roll_number+1;
	END LOOP;
	DBMS_OUTPUT.PUT_LINE(temp);
END;