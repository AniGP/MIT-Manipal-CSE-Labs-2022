DECLARE
	roll_number studenttable.roll%TYPE;
	score studenttable.gpa%TYPE;
	n number(10);
	i number(10);
BEGIN
	roll_number:=1;
	i:=0;
	select count(roll) into n  from studenttable;
	while i<n
	LOOP
		select gpa into score from studenttable where roll = roll_number;
		IF score between 0 and 4  then
			DBMS_OUTPUT.PUT_LINE('F');
		ELSIF score between 4 and 5 then
			DBMS_OUTPUT.PUT_LINE('E');
		ELSIF score between 5 and 6 then
			DBMS_OUTPUT.PUT_LINE('D');
		ELSIF score between 6 and 7 then
			DBMS_OUTPUT.PUT_LINE('C');
		ELSIF score between 7 and 8 then
			DBMS_OUTPUT.PUT_LINE('B');
		ELSIF score between 8 and 9 then
			DBMS_OUTPUT.PUT_LINE('A');	
		ELSE 
			DBMS_OUTPUT.PUT_LINE('A+');									
		END IF;
		i:=i+1;
		roll_number:=roll_number+1;
	END LOOP;
END;