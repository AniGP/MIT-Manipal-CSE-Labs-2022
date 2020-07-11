CREATE TABLE Match(
MatchID NUMERIC(10),
TeamName1 VARCHAR(20),
TeamName2 VARCHAR(20),
Ground VARCHAR(20),
MatchDate DATE,
PRIMARY KEY(MatchID));

CREATE TABLE Player(
PlayerID NUMERIC(10),
LastName VARCHAR(20),
FirstName VARCHAR(20),
Country VARCHAR(20),
YearBorn NUMERIC(10),
BirthPlace VARCHAR(20),
PRIMARY KEY(PlayerID));

CREATE TABLE Batting(
MatchID NUMERIC(10),
PlayerID NUMERIC(10),
BattingOrder NUMERIC(10),
RunsScored NUMERIC(10),
PRIMARY KEY(MatchID, PlayerID),
FOREIGN KEY(MatchID) REFERENCES Match(MatchID),
FOREIGN KEY(PlayerID) REFERENCES Player(PlayerID));


INSERT INTO Match VALUES(2688, 'Australia', 'India', 'Sydney', '2-MAR-2008');
INSERT INTO Match VALUES(2675, 'Australia', 'India', 'Melbourne', '10-FEB-2008');
INSERT INTO Match VALUES(2688, 'Australia', 'India', 'Sydney', '2-MAR-2008');
INSERT INTO Match VALUES(2689, 'Australia', 'India', 'Brisbane', '4-MAR-2008');
INSERT INTO Match VALUES(2755, 'India', 'West Indies', 'Brisbane', '7-JUL-2010');
INSERT INTO Match VALUES(2750, 'Sri Lanka', 'India', 'Brisbane', '7-APR-2010');

INSERT INTO Player VALUES(89001, 'Tendulkar', 'Sachin', 'India', 1973, 'Mumbai');
INSERT INTO Player VALUES(27002, 'Sharma', 'Ishant', 'India', 1988, 'Delhi');
INSERT INTO Player VALUES(99001, 'Lee', 'Brett', 'Australia', 1976, 'Wollongong');
INSERT INTO Player VALUES(98002, 'Lara', 'Brian', 'West Indies', 1969, 'Santa Cruz');
INSERT INTO Player VALUES(91001, 'Jayasurya', 'Sanath', 'Sri Lanka', 1969, 'Matara');

INSERT INTO Batting VALUES(2689, 89001, 1, 71);
INSERT INTO Batting VALUES(2688, 98002, 2, 42);
INSERT INTO Batting VALUES(2675, 27002, 2, 0);
INSERT INTO Batting VALUES(2689, 99001, 2, 9);
INSERT INTO Batting VALUES(2755, 89001, 1, 44);
INSERT INTO Batting VALUES(2750, 89001, 4, 40);
INSERT INTO Batting VALUES(2755, 27002, 3, 29);

SELECT * FROM Player WHERE Country='India' AND YearBorn>1975;

SELECT * FROM Match WHERE TeamName1='India' OR TeamName1='Australia';

SELECT FirstName, LastName FROM Player P WHERE NOT EXISTS((SELECT MatchID FROM Match WHERE Ground='Melbourne') MINUS (SELECT MatchID FROM Batting WHERE PlayerID=P.PlayerID));

SELECT FirstName,LastName FROM Player WHERE YearBorn=(SELECT MAX(YearBorn) FROM Player);\


DECLARE
      ID numeric(5);
      totalscored numeric(10);
      num_to_word VARCHAR2(100); 
      str		 VARCHAR2(100); 
      len		 INTEGER; 
      c		 INTEGER;
BEGIN
  ID:=&inp;
  Select sum(RunsScored) into totalscored from Batting where PlayerID=ID;
  len := Length(totalscored); 

  FOR i IN 1..len LOOP 
		c := Substr(totalscored, i, 1);
        IF c = '0' THEN
          str := 'Zero';
        ELSIF c = '1' THEN
          str := 'One';
        ELSIF c = '2' THEN
          str := 'Two';
        ELSIF c = '3' THEN
          str := 'Three';
        ELSIF c = '4' THEN
          str := 'Four';
        ELSIF c = '5' THEN
          str := 'Five';
        ELSIF c = '6' THEN
          str := 'Six';
        ELSIF c = '7' THEN
          str := 'Seven';
        ELSIF c = '8' THEN
          str := 'Eight';
        ELSIF c = '9' THEN
          str := 'NINE';
        END IF;

		num_to_word := num_to_word ||str; 
	END LOOP; 

	DBMS_OUTPUT.PUT_LINE(num_to_word); 
END;
/