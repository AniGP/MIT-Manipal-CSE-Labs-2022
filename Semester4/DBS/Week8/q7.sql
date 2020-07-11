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
			GOTO F;
		ELSIF score between 4 and 5 then
		GOTO E;
		ELSIF score between 5 and 6 then
		GOTO D;
		ELSIF score between 6 and 7 then
		GOTO C;
		ELSIF score between 7 and 8 then
		GOTO B;
		ELSIF score between 8 and 9 then
		GOTO A;
		ELSE 
		GOTO Aplus;
		END IF;
		i:=i+1;
		roll_number:=roll_number+1;
	END LOOP;
	<<F>>
		DBMS_OUTPUT.PUT_LINE('F');
	<<E>>
		DBMS_OUTPUT.PUT_LINE('E');
	<<D>>
		DBMS_OUTPUT.PUT_LINE('D');
	<<C>>
		DBMS_OUTPUT.PUT_LINE('C');
	<<B>>
		DBMS_OUTPUT.PUT_LINE('B');
	<<A>>
		DBMS_OUTPUT.PUT_LINE('A');	
	<<Aplus>>
		DBMS_OUTPUT.PUT_LINE('A+');									
END; 	