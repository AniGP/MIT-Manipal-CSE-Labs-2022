DECLARE
	in_date date;
	out_date date;
	diff number(10);
	penalty number(10);
BEGIN
	out_date:='&d';
	in_date:='&f';
	
	diff := TO_DATE(in_date,'dd/mm/yy')-TO_DATE(out_date,'dd/mm/yy'); 
		DBMS_OUTPUT.PUT_LINE(diff);
	IF diff between 0 and 7 then
		penalty := 0;
		DBMS_OUTPUT.PUT_LINE('NIL');
	ELSIF diff between 8 and 15 then
		penalty:=(diff-7)*0+(diff-8)*1;
		DBMS_OUTPUT.PUT_LINE(penalty);
	ELSIF diff between 16 and 30 then
		penalty:=(diff-7)*0+(diff-8)*1+(diff-15)*2;
		DBMS_OUTPUT.PUT_LINE(penalty);
	ELSE
		penalty:=(diff-7)*0+(diff-8)*1+(diff-15)*2+(diff-30)*5;
		DBMS_OUTPUT.PUT_LINE(penalty);
	END IF;					
END;