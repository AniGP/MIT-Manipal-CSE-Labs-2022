DECLARE
	teacher_name instructor.name%TYPE;
	details instructor%ROWTYPE;
	n number(10);
	more_people_with_name EXCEPTION;
BEGIN
	teacher_name := '&name';
	select count(id) into n from instructor group by name having name = teacher_name;
	IF n = 1 THEN
		select * into details from instructor where instructor.name = teacher_name;
		DBMS_OUTPUT.PUT_LINE(details.name || details.salary);
	ELSIF n>1 THEN
		RAISE more_people_with_name;
	END IF;
EXCEPTION
	WHEN more_people_with_name THEN
		DBMS_OUTPUT.PUT_LINE('More than one instructors with the name');
	WHEN OTHERS THEN
		DBMS_OUTPUT.PUT_LINE('No instructor with this name');
END;
