set serveroutput on;
DECLARE
	roll_number studenttable.roll%TYPE;
	score studenttable.gpa%TYPE;
BEGIN
	roll_number:='&r';
	select gpa into score from studenttable where roll = roll_number;
	DBMS_OUTPUT.PUT_LINE(score);
END;